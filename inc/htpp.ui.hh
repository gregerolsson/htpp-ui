#pragma once

#include <map>
#include <string>
#include <vector>
#include <cassert>
#include <string>
#include <string_view>
#include <sstream>
#include <vector>

#include "htpp.hh"

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

// Classify the suffix after "border-".
constexpr group_id classify_border(std::string_view suffix) {
    if (!suffix.empty()) {
        char c = suffix[0];
        // border-{side}(-...) — side-specific width/color utilities.
        // Use none so t/r/b/l sides don't false-conflict with each other.
        if ((c == 't' || c == 'r' || c == 'b' || c == 'l')
                && (suffix.size() == 1 || suffix[1] == '-'))
            return group_id::none;
        // border-{digit} = overall border-width (border-0, border-2 ...)
        if (c >= '0' && c <= '9')
            return group_id::border_width;
    }
    return group_id::border_color;
}

constexpr group_id classify_utility(std::string_view util) {
    // text-* needs suffix inspection.
    if (util.starts_with("text-"))
        return classify_text_variant(util.substr(5));

    // border-* needs suffix inspection to split width/side/color.
    if (util.starts_with("border-x-") || util.starts_with("border-y-"))
        return group_id::border_width;
    if (util.starts_with("border-"))
        return classify_border(util.substr(7));
    if (util == "border")
        return group_id::border_width;

    constexpr std::array<prefix_entry, 6> table{{
        {"rotate-", group_id::rotate},
        {"bg-",     group_id::bg_color},
        {"px-",     group_id::padding_x},
        {"py-",     group_id::padding_y},
        {"pt-",     group_id::padding_t},
        {"mx-",     group_id::margin_x},
    }};

    for (const auto& e : table) {
        if (util.starts_with(e.prefix))
            return e.group;
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

} // namespace ui

using attributes = std::map<std::string, std::string>;

namespace accordion {
    struct props { std::string_view id; std::string_view class_; };
    struct item_props { std::string_view id; std::string_view class_; };
    struct trigger_props { std::string_view id; std::string_view class_; };
    struct content_props { std::string_view id; std::string_view class_; };

    HT_COMPONENT_DECL(accordion, const props &props);
    HT_COMPONENT_DECL(item, const item_props &props);
    HT_COMPONENT_DECL(trigger, const trigger_props &props);
    HT_COMPONENT_DECL(content, const content_props &props);
}

namespace alert {
    enum variant {
        normal,
        destructive,
    };

    struct props {
        std::string_view id;
        std::string_view class_;
        variant variant = normal;
    };

    struct title_props { std::string_view id; std::string_view class_; };
    struct description_props { std::string_view id; std::string_view class_; };

    HT_COMPONENT_DECL(alert, const props& props);
    HT_COMPONENT_DECL(title, const title_props& props);
    HT_COMPONENT_DECL(description, const description_props& props);
}

namespace aspectratio {
    enum ratio {
        automatic,
        square,
        video,
        portrait,
        wide,
    };

    struct props {
        std::string_view id;
        std::string_view class_;
        ratio   ratio;
    };

    HT_COMPONENT_DECL(aspectratio, const props& props);
}

namespace avatar {
    struct props { std::string_view id; std::string_view class_; };

    struct image_props {
        std::string_view id;
        std::string_view class_;
        std::string_view alt;
        std::string_view src;
    };

    struct fallback_props { std::string_view id; std::string_view class_; };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(avatar, const props& props);
    HT_COMPONENT_DECL(image, const image_props& props);
    HT_COMPONENT_DECL(fallback, const fallback_props& props);
}

namespace badge {
    enum variant {
        normal,
        secondary,
        destructive,
        outline,
    };

    struct props {
        std::string_view id;
        std::string_view class_;
        variant variant;
    };

    HT_COMPONENT_DECL(badge, const props& props);
}

namespace breadcrumb {
    struct props { std::string_view id; std::string_view class_; };
    struct list_props { std::string_view id; std::string_view class_; };

    struct item_props {
        std::string_view id;
        std::string_view class_;
        bool current;
    };

    struct link_props {
        std::string_view id;
        std::string_view class_;
        std::string_view href;
    };

    struct separator_props {
        std::string_view id;
        std::string_view class_;
        bool use_custom;
    };

    HT_COMPONENT_DECL(breadcrumb, const props& props);
    HT_COMPONENT_DECL(list, const list_props& props);
    HT_COMPONENT_DECL(item, const item_props& props);
    HT_COMPONENT_DECL(link, const link_props& props);
    HT_COMPONENT_DECL(separator, const separator_props& props);
    HT_COMPONENT_DECL(page, const item_props& props);
}

namespace button {
    enum variant {
        normal,
        destructive,
        outline,
        secondary,
        ghost,
        link,
    };

    enum size {
        medium,
        sm,
        lg,
        icon,
    };

    enum type_ {
        btn,
        reset,
        submit,
    };

    struct props {
        std::string_view id;
        std::string_view class_;
        variant          variant;
        size             size;
        type_            type_;
        bool             full_width;
        std::string_view href;
        std::string_view target;
        bool             disabled;
        std::string_view form;
    };

    HT_COMPONENT_DECL(button, const props& props);
}

namespace calendar {
    enum locale_tag {
        locale_default,
        chinese,
        french,
        german,
        italian,
        japanese,
        portuguese,
        spanish,
    };

    enum weekday {
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        friday,
        saturday,
    };

    struct props {
        std::string_view id;
        std::string_view class_;
        locale_tag       locale;
        std::string_view value;
        std::string_view name;
        int              initial_month;
        int              initial_year;
        weekday          start_of_week;
        bool             hide_hidden_input;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(calendar, const props& props);
}

namespace card {
    struct props { std::string_view id; std::string_view class_; };
    struct header_props { std::string_view id; std::string_view class_; };
    struct title_props { std::string_view id; std::string_view class_; };
    struct description_props { std::string_view id; std::string_view class_; };
    struct content_props { std::string_view id; std::string_view class_; };
    struct footer_props { std::string_view id; std::string_view class_; };

    HT_COMPONENT_DECL(card, const props& props);
    HT_COMPONENT_DECL(header, const header_props& props);
    HT_COMPONENT_DECL(title, const title_props& props);
    HT_COMPONENT_DECL(description, const description_props& props);
    HT_COMPONENT_DECL(content, const content_props& props);
    HT_COMPONENT_DECL(footer, const footer_props& props);
}

namespace carousel {
    struct props {
        std::string_view id;
        std::string_view class_;
        bool autoplay;
        int  interval;
        bool loop;
    };

    struct content_props { std::string_view id; std::string_view class_; };
    struct item_props { std::string_view id; std::string_view class_; };
    struct previous_props { std::string_view id; std::string_view class_; };
    struct next_props { std::string_view id; std::string_view class_; };

    struct indicators_props {
        std::string_view id;
        std::string_view class_;
        int count;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(carousel, const props& props);
    HT_COMPONENT_DECL(content, const content_props& props);
    HT_COMPONENT_DECL(item, const item_props& props);
    HT_COMPONENT_DECL(previous, const previous_props& props);
    HT_COMPONENT_DECL(next, const next_props& props);
    HT_COMPONENT_DECL(indicators, const indicators_props& props);
}

namespace chart {
    enum variant {
        bar,
        line,
        pie,
        doughnut,
        radar,
    };

    struct dataset {
        std::string_view    label;
        std::vector<double> data;
        int                 border_width;
        std::string_view    border_color;
        std::string_view    background_color;
        double              tension;
        bool                fill;
        bool                stepped;
    };

    struct options {
        bool responsive;
        bool legend;
    };

    struct data {
        std::vector<std::string> labels;
        std::vector<dataset>     datasets;
    };

    struct props {
        std::string_view id;
        std::string_view class_;
        variant          variant;
        data             data;
        options          options;
        std::string_view raw_config;
        bool             show_legend;
        bool             show_x_axis;
        bool             show_y_axis;
        bool             show_x_labels;
        bool             show_y_labels;
        bool             show_x_grid;
        bool             show_y_grid;
        bool             horizontal;
        bool             stacked;
        double           y_min;
        double           y_max;
        bool             begin_at_zero;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(chart, const props& props);
}

namespace checkbox {
    struct props {
        std::string_view id;
        std::string_view class_;
        std::string_view name;
        std::string_view value;
        bool             disabled;
        bool             checked;
        std::string_view group;
        bool             group_parent;
        std::string_view form;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(checkbox, const props& props);
}

namespace collapsible {
    struct props {
        std::string_view id;
        std::string_view class_;
        bool open;
    };

    struct trigger_props { std::string_view id; std::string_view class_; };
    struct content_props { std::string_view id; std::string_view class_; };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(collapsible, const props& props);
    HT_COMPONENT_DECL(trigger, const trigger_props& props);
    HT_COMPONENT_DECL(content, const content_props& props);
}

namespace copybutton {
    struct props {
        std::string_view id;
        std::string_view class_;
        std::string_view target_id;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(copybutton, const props& props);
}

namespace datepicker {
    enum format {
        locale_short,
        locale_medium,
        locale_long,
        locale_full,
    };

    enum locale_tag {
        locale_default,
        chinese,
        french,
        german,
        italian,
        japanese,
        portuguese,
        spanish,
    };

    struct props {
        std::string_view id;
        std::string_view class_;
        std::string_view name;
        std::string_view value;
        std::string_view form;
        format           format;
        locale_tag       locale;
        int              start_of_week;
        std::string_view placeholder;
        bool             disabled;
        bool             has_error;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(datepicker, const props& props);
}

namespace dialog {
    struct props {
        std::string_view id;
        std::string_view class_;
        bool disable_click_away;
        bool disable_esc;
        bool open;
    };

    struct trigger_props {
        std::string_view id;
        std::string_view class_;
        std::string_view for_;
    };

    struct content_props {
        std::string_view id;
        std::string_view class_;
        bool hide_close_button;
        bool disable_modal;
    };

    struct close_props {
        std::string_view id;
        std::string_view class_;
        std::string_view for_;
    };

    struct header_props { std::string_view id; std::string_view class_; };
    struct footer_props { std::string_view id; std::string_view class_; };
    struct title_props { std::string_view id; std::string_view class_; };
    struct description_props { std::string_view id; std::string_view class_; };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(dialog, const props& props);
    HT_COMPONENT_DECL(trigger, const trigger_props& props);
    HT_COMPONENT_DECL(content, const content_props& props);
    HT_COMPONENT_DECL(close, const close_props& props);
    HT_COMPONENT_DECL(header, const header_props& props);
    HT_COMPONENT_DECL(footer, const footer_props& props);
    HT_COMPONENT_DECL(title, const title_props& props);
    HT_COMPONENT_DECL(description, const description_props& props);
}

namespace popover {
    enum placement {
        top,
        top_start,
        top_end,
        right,
        right_start,
        right_end,
        bottom,
        bottom_start,
        bottom_end,
        left,
        left_start,
        left_end,
    };

    enum trigger_type {
        hover,
        click,
        manual,
    };

    struct root_props { std::string_view id; std::string_view class_; };

    struct trigger_props {
        std::string_view id;
        std::string_view class_;
        trigger_type trigger_type;
    };

    struct content_props {
        std::string_view id;
        std::string_view class_;
        placement        placement;
        int              offset;
        bool             disable_click_away;
        bool             disable_esc;
        bool             show_arrow;
        int              hover_delay;
        int              hover_out_delay;
        bool             exclusive;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(root, const root_props& props);
    HT_COMPONENT_DECL(trigger, const trigger_props& props);
    HT_COMPONENT_DECL(content, const content_props& props);
}

namespace dropdown {
    using placement = popover::placement;

    struct props { std::string_view id; std::string_view class_; };
    struct trigger_props { std::string_view id; std::string_view class_; };
    struct group_props { std::string_view id; std::string_view class_; };
    struct label_props { std::string_view id; std::string_view class_; };
    struct separator_props { std::string_view id; std::string_view class_; };
    struct shortcut_props { std::string_view id; std::string_view class_; };
    struct sub_props { std::string_view id; std::string_view class_; };
    struct sub_trigger_props { std::string_view id; std::string_view class_; };
    struct sub_content_props { std::string_view id; std::string_view class_; };

    struct content_props {
        std::string_view id;
        std::string_view class_;
        placement placement;
    };

    struct item_props {
        std::string_view id;
        std::string_view class_;
        bool             disabled;
        std::string_view href;
        std::string_view target;
        bool             prevent_close;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(dropdown, const props& props);
    HT_COMPONENT_DECL(trigger, const trigger_props& props);
    HT_COMPONENT_DECL(content, const content_props& props);
    HT_COMPONENT_DECL(group, const group_props& props);
    HT_COMPONENT_DECL(label, const label_props& props);
    HT_COMPONENT_DECL(item, const item_props& props);
    HT_COMPONENT_DECL(separator, const separator_props& props);
    HT_COMPONENT_DECL(shortcut, const shortcut_props& props);
    HT_COMPONENT_DECL(sub, const sub_props& props);
    HT_COMPONENT_DECL(sub_trigger, const sub_trigger_props& props);
    HT_COMPONENT_DECL(sub_content, const sub_content_props& props);
}

namespace form {
    enum message_variant {
        error,
        info,
    };

    struct item_props { std::string_view id; std::string_view class_; };
    struct description_props { std::string_view id; std::string_view class_; };

    struct label_props {
        std::string_view id;
        std::string_view class_;
        std::string_view for_;
        std::string_view disabled_class;
    };

    struct message_props {
        std::string_view id;
        std::string_view class_;
        message_variant variant;
    };

    HT_COMPONENT_DECL(item, const item_props& props);
    HT_COMPONENT_DECL(item_flex, const item_props& props);
    HT_COMPONENT_DECL(label, const label_props& props);
    HT_COMPONENT_DECL(description, const description_props& props);
    HT_COMPONENT_DECL(message, const message_props& props);
}

namespace input {
    enum type_ {
        text,
        password,
        email,
        number,
        tel,
        url,
        search,
        date,
        date_time,
        time_,
        file,
        color,
        week,
        month,
    };

    struct props {
        std::string_view id;
        std::string_view class_;
        std::string_view name;
        type_            type_;
        std::string_view form;
        std::string_view placeholder;
        std::string_view value;
        bool             disabled;
        bool             readonly;
        bool             required;
        std::string_view file_accept;
        bool             has_error;
        bool             no_toggle_password;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(input, const props& props);
}

namespace inputotp {
    struct props {
        std::string_view id;
        std::string_view class_;
        std::string_view value;
        std::string_view name;
        std::string_view form;
        bool             has_error;
    };

    struct group_props { std::string_view id; std::string_view class_; };

    struct slot_props {
        std::string_view id;
        std::string_view class_;
        int              index;
        std::string_view type;
        std::string_view placeholder;
        bool             disabled;
        bool             has_error;
    };

    struct separator_props { std::string_view id; std::string_view class_; };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(inputotp, const props& props);
    HT_COMPONENT_DECL(group, const group_props& props);
    HT_COMPONENT_DECL(slot, const slot_props& props);
    HT_COMPONENT_DECL(separator, const separator_props& props);
}

namespace label {
    struct props {
        std::string_view id;
        std::string_view class_;
        std::string_view for_;
        bool             error;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(label, const props& props);
}

namespace pagination {
    struct props { std::string_view id; std::string_view class_; };
    struct content_props { std::string_view id; std::string_view class_; };
    struct item_props { std::string_view id; std::string_view class_; };

    struct link_props {
        std::string_view id;
        std::string_view class_;
        std::string_view href;
        bool             is_active;
        bool             disabled;
    };

    struct previous_props {
        std::string_view id;
        std::string_view class_;
        std::string_view href;
        bool             disabled;
        std::string_view label;
    };

    struct next_props {
        std::string_view id;
        std::string_view class_;
        std::string_view href;
        bool             disabled;
        std::string_view label;
    };

    HT_COMPONENT_DECL(pagination, const props& props);
    HT_COMPONENT_DECL(content, const content_props& props);
    HT_COMPONENT_DECL(item, const item_props& props);
    HT_COMPONENT_DECL(link, const link_props& props);
    HT_COMPONENT_DECL(previous, const previous_props& props);
    HT_COMPONENT_DECL(next, const next_props& props);
    HT_COMPONENT_DECL(ellipsis);
}

namespace progress {
    enum size {
        sm,
        lg,
    };

    enum variant {
        normal,
        success,
        danger,
        warning,
    };

    struct props {
        std::string_view id;
        std::string_view class_;
        int              max;
        int              value;
        std::string_view label;
        bool             show_value;
        size             size;
        variant          variant;
        std::string_view bar_class;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(progress, const props& props);
}

namespace radio {
    struct props {
        std::string_view id;
        std::string_view class_;
        std::string_view name;
        std::string_view value;
        std::string_view form;
        bool             disabled;
        bool             checked;
    };

    HT_COMPONENT_DECL(radio, const props& props);
}

namespace rating {
    enum style {
        star,
        heart,
        emoji,
    };

    struct props {
        std::string_view id;
        std::string_view class_;
        double           value;
        bool             read_only;
        double           precision;
        std::string_view name;
        std::string_view form;
        bool             only_integer;
    };

    struct group_props { std::string_view id; std::string_view class_; };

    struct item_props {
        std::string_view id;
        std::string_view class_;
        int   value;
        style style;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(rating, const props& props);
    HT_COMPONENT_DECL(group, const group_props& props);
    HT_COMPONENT_DECL(item, const item_props& props);
}

namespace selectbox {
    struct props {
        std::string_view id;
        std::string_view class_;
        bool multiple;
    };

    struct group_props { std::string_view id; std::string_view class_; };
    struct label_props { std::string_view id; std::string_view class_; };

    struct item_props {
        std::string_view id;
        std::string_view class_;
        std::string_view value;
        bool             selected;
        bool             disabled;
    };

    struct trigger_props {
        std::string_view id;
        std::string_view class_;
        std::string_view name;
        std::string_view form;
        bool             disabled;
        bool             has_error;
        bool             multiple;
        bool             show_pills;
        std::string_view selected_count_text;
    };

    struct value_props {
        std::string_view id;
        std::string_view class_;
        std::string_view placeholder;
        bool             multiple;
    };

    struct content_props {
        std::string_view id;
        std::string_view class_;
        bool             no_search;
        std::string_view search_placeholder;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(selectbox, const props& props);
    HT_COMPONENT_DECL(group, const group_props& props);
    HT_COMPONENT_DECL(label, const label_props& props);
    HT_COMPONENT_DECL(item, const item_props& props);
    HT_COMPONENT_DECL(trigger, const trigger_props& props);
    HT_COMPONENT_DECL(value, const value_props& props);
    HT_COMPONENT_DECL(content, const content_props& props);
}

namespace separator {
    enum orientation { horizontal, vertical, };
    enum decoration { dashed, dotted, };

    struct props {
        std::string_view id;
        std::string_view class_;
        orientation orientation;
        decoration  decoration;
    };

    HT_COMPONENT_DECL(separator, const props& props);
}

namespace sheet {
    enum side { top, right, bottom, left, };

    struct props {
        std::string_view id;
        std::string_view class_;
        side side;
        bool open;
        bool disable_click_away;
        bool disable_esc;
    };

    struct trigger_props {
        std::string_view id;
        std::string_view class_;
        std::string_view for_;
    };

    struct content_props {
        std::string_view id;
        std::string_view class_;
        bool hide_close_button;
        side side;
    };

    struct header_props { std::string_view id; std::string_view class_; };
    struct title_props { std::string_view id; std::string_view class_; };
    struct description_props { std::string_view id; std::string_view class_; };
    struct footer_props { std::string_view id; std::string_view class_; };

    struct close_props {
        std::string_view id;
        std::string_view class_;
        std::string_view for_;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(sheet, const props& props);
    HT_COMPONENT_DECL(trigger, const trigger_props& props);
    HT_COMPONENT_DECL(content, const content_props& props);
    HT_COMPONENT_DECL(header, const header_props& props);
    HT_COMPONENT_DECL(title, const title_props& props);
    HT_COMPONENT_DECL(description, const description_props& props);
    HT_COMPONENT_DECL(footer, const footer_props& props);
    HT_COMPONENT_DECL(close, const close_props& props);
}

namespace sidebar {
    enum side {
        left,
        right,
    };

    enum variant {
        sidebar_variant,
        floating,
        inset_variant,
    };

    enum collapsible {
        offcanvas,
        icon,
        none,
    };

    enum menu_button_size {
        normal,
        sm,
        lg,
    };

    struct props {
        std::string_view id;
        std::string_view class_;
        side             side;
        variant          variant;
        collapsible      collapsible;
        bool             collapsed;
        std::string_view keyboard_shortcut;
    };

    struct header_props { std::string_view id; std::string_view class_; };
    struct footer_props { std::string_view id; std::string_view class_; };
    struct content_props { std::string_view id; std::string_view class_; };
    struct group_props { std::string_view id; std::string_view class_; };
    struct group_label_props { std::string_view id; std::string_view class_; };
    struct menu_props { std::string_view id; std::string_view class_; };
    struct menu_item_props { std::string_view id; std::string_view class_; };

    struct menu_button_props {
        std::string_view id;
        std::string_view class_;
        std::string_view href;
        bool             is_active;
        menu_button_size size;
        std::string_view tooltip;
    };

    struct menu_badge_props { std::string_view id; std::string_view class_; };
    struct menu_sub_props { std::string_view id; std::string_view class_; };
    struct menu_sub_item_props { std::string_view id; std::string_view class_; };

    struct menu_sub_button_props {
        std::string_view id;
        std::string_view class_;
        std::string_view href;
        bool             is_active;
    };

    struct separator_props { std::string_view id; std::string_view class_; };
    struct layout_props { std::string_view id; std::string_view class_; };

    struct trigger_props {
        std::string_view id;
        std::string_view class_;
        std::string_view target;
    };

    struct inset_props { std::string_view id; std::string_view class_; };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(sidebar, const props& props);
    HT_COMPONENT_DECL(header, const header_props& props);
    HT_COMPONENT_DECL(footer, const footer_props& props);
    HT_COMPONENT_DECL(content, const content_props& props);
    HT_COMPONENT_DECL(group, const group_props& props);
    HT_COMPONENT_DECL(group_label, const group_label_props& props);
    HT_COMPONENT_DECL(menu, const menu_props& props);
    HT_COMPONENT_DECL(menu_item, const menu_item_props& props);
    HT_COMPONENT_DECL(menu_button, const menu_button_props& props);
    HT_COMPONENT_DECL(menu_badge, const menu_badge_props& props);
    HT_COMPONENT_DECL(menu_sub, const menu_sub_props& props);
    HT_COMPONENT_DECL(menu_sub_item, const menu_sub_item_props& props);
    HT_COMPONENT_DECL(menu_sub_button, const menu_sub_button_props& props);
    HT_COMPONENT_DECL(separator, const separator_props& props);
    HT_COMPONENT_DECL(layout, const layout_props& props);
    HT_COMPONENT_DECL(trigger, const trigger_props& props);
    HT_COMPONENT_DECL(inset, const inset_props& props);
}

namespace skeleton {
    struct props { std::string_view id; std::string_view class_; };

    HT_COMPONENT_DECL(skeleton, const props& props);
}

namespace slider {
    struct props {
        std::string_view id;
        std::string_view class_;
        std::string_view name;
        int              min;
        int              max;
        int              step;
        int              value;
        bool             disabled;
    };

    struct range_props {
        std::string_view id;
        std::string_view class_;
        std::string_view name_min;
        std::string_view name_max;
        int              min;
        int              max;
        int              step;
        int              min_value;
        int              max_value;
        bool             disabled;
    };

    struct value_props {
        std::string_view id;
        std::string_view class_;
        std::string_view for_;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(slider, const props& props);
    HT_COMPONENT_DECL(range, const range_props& props);
    HT_COMPONENT_DECL(value, const value_props& props);
}

namespace switch_ {
    struct props {
        std::string_view id;
        std::string_view class_;
        std::string_view name;
        std::string_view value;
        bool             disabled;
        bool             checked;
        std::string_view form;
    };

    HT_COMPONENT_DECL(switch_, const props& props);
}

namespace table {
    struct props { std::string_view id; std::string_view class_; };
    struct header_props { std::string_view id; std::string_view class_; };
    struct body_props { std::string_view id; std::string_view class_; };
    struct footer_props { std::string_view id; std::string_view class_; };

    struct row_props {
        std::string_view id;
        std::string_view class_;
        bool selected;
    };

    struct head_props { std::string_view id; std::string_view class_; };
    struct cell_props { std::string_view id; std::string_view class_; };
    struct caption_props { std::string_view id; std::string_view class_; };

    HT_COMPONENT_DECL(table, const props& props);
    HT_COMPONENT_DECL(header, const header_props& props);
    HT_COMPONENT_DECL(body, const body_props& props);
    HT_COMPONENT_DECL(footer, const footer_props& props);
    HT_COMPONENT_DECL(row, const row_props& props);
    HT_COMPONENT_DECL(head, const head_props& props);
    HT_COMPONENT_DECL(cell, const cell_props& props);
    HT_COMPONENT_DECL(caption, const caption_props& props);
}

namespace tabs {
    struct props { std::string_view id; std::string_view class_; };
    struct list_props { std::string_view id; std::string_view class_; };

    struct trigger_props {
        std::string_view id;
        std::string_view class_;
        std::string_view value;
        bool             is_active;
        std::string_view tabs_id;
    };

    struct content_props {
        std::string_view id;
        std::string_view class_;
        std::string_view value;
        bool             is_active;
        std::string_view tabs_id;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(tabs, const props& props);
    HT_COMPONENT_DECL(list, const list_props& props);
    HT_COMPONENT_DECL(trigger, const trigger_props& props);
    HT_COMPONENT_DECL(content, const content_props& props);
}

namespace tagsinput {
    struct props {
        std::string_view         id;
        std::string_view         class_;
        std::string_view         name;
        std::vector<std::string> value;
        std::string_view         form;
        std::string_view         placeholder;
        bool                     has_error;
        bool                     disabled;
        bool                     readonly;
        std::vector<std::string> suggestions;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(tagsinput, const props& props);
}

namespace textarea {
    struct props {
        std::string_view id;
        std::string_view class_;
        std::string_view name;
        std::string_view value;
        std::string_view form;
        std::string_view placeholder;
        int              rows;
        bool             auto_resize;
        bool             disabled;
        bool             readonly;
        bool             has_error;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(textarea, const props& props);
}

namespace timepicker {
    struct props {
        std::string_view id;
        std::string_view class_;
        std::string_view name;
        std::string_view form;
        std::string_view value;
        std::string_view min_time;
        std::string_view max_time;
        int              step;
        bool             use_12_hours;
        std::string_view am_label;
        std::string_view pm_label;
        std::string_view placeholder;
        bool             disabled;
        bool             has_error;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(timepicker, const props& props);
}

namespace toast {
    enum variant {
        normal,
        success,
        error,
        warning,
        info,
    };

    enum position {
        top_right,
        top_left,
        top_center,
        bottom_right,
        bottom_left,
        bottom_center,
    };

    struct props {
        std::string_view id;
        std::string_view class_;
        std::string_view title;
        std::string_view description;
        variant          variant;
        position         position;
        int              duration;
        bool             dismissible;
        bool             show_indicator;
        bool             icon;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(toast, const props& props);
}

namespace tooltip {
    enum position {
        top,
        right,
        bottom,
        left,
    };

    struct props { std::string_view id; std::string_view class_; };
    struct trigger_props { std::string_view id; std::string_view class_; };

    struct content_props {
        std::string_view id;
        std::string_view class_;
        bool     show_arrow;
        position position;
        int      hover_delay;
        int      hover_out_delay;
    };

    HT_COMPONENT_DECL(script);
    HT_COMPONENT_DECL(tooltip, const props& props);
    HT_COMPONENT_DECL(trigger, const trigger_props& props);
    HT_COMPONENT_DECL(content, const content_props& props);
}
