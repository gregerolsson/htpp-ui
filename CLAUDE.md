# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

A C++20/23 header-only library for generating HTML server-side. It has two layers:

- **`inc/htpp.hh`** — the core HTML DSL: RAII tag objects, typed attribute keys, and macros (`HT_DIV`, `HT_BUTTON`, etc.) that write directly to a `std::ostream`.
- **`inc/htpp.htpp.ui.hh`** — shadcn/ui-style component library built on top of htpp. Contains the `ui::merge()` Tailwind class merging utility and `HT_COMPONENT_DECL` declarations for ~30 components.
- **`src/*.cc`** — one `.cc` per component: the actual `HT_COMPONENT(name, props)` definitions.

## Build

There is no Makefile. This is a library meant to be included into a user's project. The `.cc` files in `src/` must be compiled into the user's build.

Compiler flags required (see `.clangd`):
```
-std=c++23 -I/opt/homebrew/include -I./inc
```

### Tailwind CSS

The CSS pipeline uses Tailwind v4 via Bun:

```sh
bun run @tailwindcss/cli -i index.css -o htm/index.css   # one-shot
bun run @tailwindcss/cli -i index.css -o htm/index.css --watch  # watch mode
```

`index.css` just contains `@import "tailwindcss";`. The compiled output is `htm/index.css`.

## Key architecture

### PRECONDITION: `os` must be in scope

Every file that uses `HT_*` macros must have a local `std::ostream& os` variable. Components receive it as their first parameter.

### Attribute system

Attributes are zero-cost `inline constexpr` objects in `htpp::attr`. They produce typed values via `operator=`:
- `class_ = "..."` → `attr_set<"class">` (escapes value)
- `disabled` → `attr_bool_t<"disabled">` (bare boolean attribute)
- `"data-foo"_a = "..."` → `attr_dyn` (dynamic name, validated at stream time)
- `attr_if(cond, id = "foo")` → conditional attribute

### Defining components

Use `HT_COMPONENT_DECL` in `.hh` and `HT_COMPONENT` in `.cc`:

```cpp
// in htpp.htpp.ui.hh
HT_COMPONENT_DECL(card, const card::props& props);

// in src/card.cc
HT_COMPONENT(card, const card::props& props) {
    HT_DIV(class_ = ui::merge(base_classes, props.class_)) {
        HT_SLOT();   // children land here
    }
}
```

Call sites use `HT_USE` to pass a children block:
```cpp
HT_USE(card::card, p) { HT_TEXT("content"); }
// or without children:
card::card(os, p);
```

### Tailwind class merging (`ui::merge`)

`ui::merge(a, b, c, ...)` deduplicates conflicting Tailwind utilities. Later arguments win:

```cpp
ui::merge("px-2", "px-4")  // → "px-4"
ui::merge(base, props.class_)  // props always wins
```

In production builds, define `UI_MERGE_PRODUCTION` to skip parsing and just concatenate strings.

The classifier in `htpp.htpp.ui.hh` covers a stub set of group IDs (not the full ~200 Tailwind utilities). Add new `group_id` enum values and `prefix_entry` table entries when conflict detection is needed for an unrecognized utility.

### Component props pattern

Every component takes a `props` struct with at least `id` and `class_` as `std::string_view`. Enums (`variant`, `size`, etc.) use unscoped enums defined inside the component's namespace. The `script` component variant (where present) emits the JavaScript needed for interactive behavior.
