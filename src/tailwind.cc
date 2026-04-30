// ui_merge.hpp — Tailwind class merger
//
// Three build modes, selected by macros:
//   UI_MERGE_PRODUCTION  — concatenate only, no classification, no checks
//   (default)            — full classify + merge, assert on intra-source conflict
//
// Lifetimes: all string_views must outlive the result of merge().

#pragma once

#include <array>
#include <cassert>
#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

namespace ui {

// ---------------------------------------------------------------------------
// Group IDs. Two classes with the same (variants, group, important) conflict.
// Stub set — real Tailwind has ~200.
// ---------------------------------------------------------------------------
enum class group_id : std::uint16_t {
    none = 0,        // unrecognized; never conflicts
    display,
    padding_x,
    padding_y,
    padding_t,
    margin_x,
    bg_color,
    text_color,
    font_size,
    border_width,
    border_color,
    rotate,
};

// ---------------------------------------------------------------------------
// One parsed class.
// ---------------------------------------------------------------------------
struct parsed_class {
    std::string_view raw;       // full token, e.g. "hover:!px-4"
    std::string_view variants;  // "hover:" or "" or "[&[open]>summary>svg]:"
    std::string_view utility;   // "px-4"
    group_id group = group_id::none;
    bool important = false;
};

// ---------------------------------------------------------------------------
// Classifier. Prefix table + special-case suffix classifiers for ambiguous
// prefixes like text-*.
// ---------------------------------------------------------------------------
constexpr group_id classify_text_variant(std::string_view suffix) {
    constexpr std::array<std::string_view, 13> sizes{
        "xs", "sm", "base", "lg", "xl",
        "2xl", "3xl", "4xl", "5xl", "6xl", "7xl", "8xl", "9xl"
    };
    constexpr std::array<std::string_view, 6> aligns{
        "left", "center", "right", "justify", "start", "end"
    };
    for (auto s : sizes)  if (suffix == s) return group_id::font_size;
    for (auto s : aligns) if (suffix == s) return group_id::none; // text_align stub
    return group_id::text_color;
}

struct prefix_entry {
    std::string_view prefix;
    group_id group;
};

constexpr group_id classify_utility(std::string_view util) {
    // text-* needs suffix inspection.
    if (util.starts_with("text-")) {
        return classify_text_variant(util.substr(5));
    }

    // Sorted longest-prefix-first so first match wins.
    constexpr std::array<prefix_entry, 9> table{{
        {"border-x-", group_id::border_width},
        {"border-",   group_id::border_color},
        {"border",    group_id::border_width},  // bare "border"
        {"rotate-",   group_id::rotate},
        {"bg-",       group_id::bg_color},
        {"px-",       group_id::padding_x},
        {"py-",       group_id::padding_y},
        {"pt-",       group_id::padding_t},
        {"mx-",       group_id::margin_x},
    }};

    for (const auto& e : table) {
        if (util.starts_with(e.prefix)) {
            // Bare tokens (no trailing '-') require exact match.
            if (e.prefix.back() != '-' && util.size() != e.prefix.size())
                continue;
            return e.group;
        }
    }
    return group_id::none;
}

// ---------------------------------------------------------------------------
// Parser. Splits variants from utility while respecting bracket depth, so
// "[&[open]>summary>svg]:rotate-180" parses correctly.
// ---------------------------------------------------------------------------
constexpr parsed_class parse_class(std::string_view raw) {
    auto rest = raw;
    bool important = false;
    if (!rest.empty() && rest.front() == '!') {
        important = true;
        rest.remove_prefix(1);
    }

    std::size_t variants_end = 0;
    int depth = 0;
    for (std::size_t i = 0; i < rest.size(); ++i) {
        char c = rest[i];
        if      (c == '[') ++depth;
        else if (c == ']') --depth;
        else if (c == ':' && depth == 0) variants_end = i + 1;
    }

    auto variants = rest.substr(0, variants_end);
    auto utility  = rest.substr(variants_end);

    auto group = utility.starts_with('[')
        ? group_id::none
        : classify_utility(utility);

    return parsed_class{raw, variants, utility, group, important};
}

// ---------------------------------------------------------------------------
// Classified set. Flat vector — n is small, linear scan beats hashing.
// ---------------------------------------------------------------------------
struct classified_set {
    std::vector<parsed_class> entries;

    // Returns true if an existing entry was overwritten (i.e. conflict).
    constexpr bool insert(parsed_class c) {
        if (c.group != group_id::none) {
            for (auto& e : entries) {
                if (e.group == c.group
                    && e.variants == c.variants
                    && e.important == c.important) {
                    e = c;
                    return true;
                }
            }
        }
        entries.push_back(c);
        return false;
    }

    constexpr void merge_from(const classified_set& other) {
        for (const auto& c : other.entries) insert(c);
    }
};

// Classify a whole string. Reports intra-string conflicts via the second
// return value, which callers can assert on.
struct classify_result {
    classified_set set;
    bool had_conflict = false;
};

constexpr classify_result classify(std::string_view classes) {
    classify_result r;
    std::size_t i = 0;
    while (i < classes.size()) {
        while (i < classes.size() && classes[i] == ' ') ++i;
        std::size_t start = i;
        while (i < classes.size() && classes[i] != ' ') ++i;
        if (start < i) {
            if (r.set.insert(parse_class(classes.substr(start, i - start))))
                r.had_conflict = true;
        }
    }
    return r;
}

// ---------------------------------------------------------------------------
// Serialization.
// ---------------------------------------------------------------------------
constexpr std::string serialize(const classified_set& set) {
    std::string out;
    for (const auto& c : set.entries) {
        if (!out.empty()) out += ' ';
        out += c.raw;
    }
    return out;
}

// ---------------------------------------------------------------------------
// merge() — the public API.
//
// Conflict policy:
//   - Conflicts WITHIN a single source argument are bugs and trigger an
//     assertion (or static_assert when the source is a constant expression).
//   - Conflicts ACROSS source arguments are intentional overrides; later
//     arguments win silently. This is what makes
//         merge(base, variant_classes(v), props.class)
//     do the right thing.
// ---------------------------------------------------------------------------

namespace detail {

constexpr void absorb(classified_set& dst, std::string_view source) {
    auto r = classify(source);
    assert(!r.had_conflict && "ui::merge: intra-source class conflict");
    dst.merge_from(r.set);
}

constexpr void absorb(classified_set& dst, const classified_set& source) {
    dst.merge_from(source);
}

}  // namespace detail

#ifdef UI_MERGE_PRODUCTION

// Fast path: concatenate with single spaces, no parsing.
template <typename... Ts>
constexpr std::string merge(const Ts&... sources) {
    std::string out;
    auto add = [&](std::string_view s) {
        if (s.empty()) return;
        if (!out.empty()) out += ' ';
        out += s;
    };
    auto dispatch = [&]<typename T>(const T& s) {
        if constexpr (std::is_same_v<T, classified_set>) {
            // Production mode shouldn't really see classified_set inputs,
            // but handle them by re-serializing.
            add(serialize(s));
        } else {
            add(std::string_view{s});
        }
    };
    (dispatch(sources), ...);
    return out;
}

#else

template <typename... Ts>
constexpr std::string merge(const Ts&... sources) {
    classified_set result;
    (detail::absorb(result, sources), ...);
    return serialize(result);
}

#endif

}  // namespace ui
