#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace selectbox {
    HT_COMPONENT(script) {
    }

    HT_COMPONENT(selectbox, const selectbox::props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("select-container w-full relative", props.class_)
        ) {
            HT_USE(popover::root, {}) {
                HT_SLOT();
            }
        }
    }

    HT_COMPONENT(group, const group_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("p-1", props.class_),
            role = "group"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(label, const label_props &props) {
        HT_TAG("span",
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("px-2 py-1.5 text-sm font-medium", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(item, const item_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "select-item group relative flex w-full cursor-default select-none items-center rounded-sm py-1.5 px-2 text-sm font-light outline-none "
                "hover:bg-accent hover:text-accent-foreground "
                "focus-visible:bg-accent focus-visible:text-accent-foreground "
                "data-[tui-selectbox-selected=true]:bg-accent data-[tui-selectbox-selected=true]:text-accent-foreground",
                props.disabled ? "pointer-events-none opacity-50" : "",
                props.class_
            ),
            role = "option",
            "data-tui-selectbox-value"_a = props.value,
            "data-tui-selectbox-selected"_a = (props.selected ? "true" : "false"),
            "data-tui-selectbox-disabled"_a = (props.disabled ? "true" : "false"),
            tabindex = "0"
        ) {
            HT_TAG("span", class_ = "truncate select-item-text") { HT_SLOT(); }
            HT_TAG("span",
                class_ = "select-check absolute right-2 flex h-3.5 w-3.5 items-center justify-center opacity-0 "
                         "group-data-[tui-selectbox-selected=true]:opacity-100"
            ) {
            }
        }
    }

    HT_COMPONENT(trigger, const trigger_props &props) {
        HT_TAG("span",
            class_ = "contents",
            "data-tui-popover-trigger"_a = "",
            "data-tui-popover-type"_a = "click"
        ) {
            HT_BUTTON(
                attr_if(!props.id.empty(), id = props.id),
                type = "button",
                class_ = ui::merge(
                    "select-trigger "
                    "w-full h-9 px-3 py-1 text-base md:text-sm "
                    "flex items-center justify-between "
                    "rounded-md border border-input bg-transparent shadow-xs transition-[color,box-shadow] outline-none "
                    "dark:bg-input/30 "
                    "selection:bg-primary selection:text-primary-foreground "
                    "focus-visible:border-ring focus-visible:ring-ring/50 focus-visible:ring-[3px] "
                    "aria-invalid:ring-destructive/20 aria-invalid:border-destructive dark:aria-invalid:ring-destructive/40",
                    props.has_error ? "border-destructive ring-destructive/20 dark:ring-destructive/40" : "",
                    props.class_
                ),
                attr_if(props.disabled, disabled),
                "data-tui-selectbox-multiple"_a = (props.multiple ? "true" : "false"),
                "data-tui-selectbox-show-pills"_a = (props.show_pills ? "true" : "false"),
                "data-tui-selectbox-selected-count-text"_a = props.selected_count_text,
                tabindex = "0",
                attr_if(props.has_error, "aria-invalid"_a = "true")
            ) {
                HT_INPUT(
                    type = "hidden",
                    attr_if(!props.name.empty(), name = props.name),
                    attr_if(!props.form.empty(), "form"_a = props.form),
                    "data-tui-selectbox-hidden-input"_a = ""
                );
                HT_SLOT();
                HT_TAG("span",
                    class_ = "ml-1 hidden cursor-pointer text-muted-foreground hover:text-foreground",
                    "data-tui-selectbox-clear-trigger"_a = "",
                    aria_label = "Clear selection",
                    role = "button"
                ) {
                }
                HT_TAG("span",
                    class_ = "pointer-events-none ml-1",
                    "data-tui-selectbox-chevron"_a = ""
                ) {
                }
            }
        }
    }

    HT_COMPONENT(value, const value_props &props) {
        HT_TAG("span",
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("block truncate select-value text-muted-foreground", props.class_),
            attr_if(!props.placeholder.empty(), "data-tui-selectbox-placeholder"_a = props.placeholder)
        ) {
            if (!props.placeholder.empty()) {
                HT_TEXT(props.placeholder);
            }
            HT_SLOT();
        }
    }

    HT_COMPONENT(content, const content_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "p-1 select-content z-50 overflow-hidden rounded-md border bg-popover text-popover-foreground shadow-md",
                props.class_
            ),
            "popover"_a = "manual",
            "data-tui-popover-content"_a = "",
            "data-tui-popover-open"_a = "false",
            "data-tui-popover-placement"_a = "bottom-start",
            "data-tui-popover-offset"_a = "4",
            "data-tui-popover-disable-esc"_a = (props.no_search ? "false" : "true"),
            "data-tui-popover-exclusive"_a = "true",
            role = "listbox",
            tabindex = "-1",
            "data-tui-selectbox-content"_a = "true"
        ) {
            HT_DIV(class_ = "w-full overflow-hidden") {
                if (!props.no_search) {
                    HT_DIV(class_ = "sticky top-0 bg-popover p-1") {
                        HT_DIV(class_ = "relative") {
                            HT_TAG("span", class_ = "absolute left-3 top-1/2 -translate-y-1/2 text-muted-foreground z-10 pointer-events-none") {
                            }
                            HT_INPUT(
                                type = "search",
                                class_ = "pl-8 flex h-9 w-full min-w-0 rounded-md border border-input bg-transparent px-3 py-1 text-base shadow-xs transition-[color,box-shadow] outline-none md:text-sm placeholder:text-muted-foreground focus-visible:border-ring focus-visible:ring-ring/50 focus-visible:ring-[3px]",
                                placeholder = (props.search_placeholder.empty() ? "Search..." : props.search_placeholder),
                                "data-tui-selectbox-search"_a = ""
                            );
                        }
                    }
                }
                HT_DIV(class_ = "max-h-[300px] overflow-y-auto") {
                    HT_SLOT();
                }
            }
        }
    }
}
