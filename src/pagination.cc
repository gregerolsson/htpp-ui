#include "htpp.hh"
#include "ui.hh"

using namespace htpp::attr;

namespace pagination {
    HT_COMPONENT(pagination, const pagination::props &props) {
        HT_NAV(
            attr_if(!props.id.empty(), id = props.id),
            role = "navigation",
            aria_label = "pagination",
            class_ = ui::merge("flex flex-wrap justify-center", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(content, const content_props &props) {
        HT_UL(
            attr_if(!props.id.empty(), id = props.id),
            class_ = "flex flex-row items-center gap-1"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(item, const item_props &props) {
        HT_LI(attr_if(!props.id.empty(), id = props.id)) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(link, const link_props &props) {
        if (props.disabled) {
            HT_BUTTON(
                attr_if(!props.id.empty(), id = props.id),
                class_ = ui::merge(
                    "size-9 inline-flex items-center justify-center gap-2 whitespace-nowrap rounded-md text-sm font-medium "
                    "hover:bg-accent hover:text-accent-foreground cursor-pointer "
                    "disabled:pointer-events-none disabled:opacity-50",
                    props.class_
                ),
                disabled,
                type = "button"
            ) {
                HT_SLOT();
            }
        } else {
            HT_A(
                attr_if(!props.id.empty(), id = props.id),
                attr_if(!props.href.empty(), href = props.href),
                class_ = ui::merge(
                    "size-9 inline-flex items-center justify-center gap-2 whitespace-nowrap rounded-md text-sm font-medium "
                    "hover:bg-accent hover:text-accent-foreground cursor-pointer",
                    props.is_active ? "border bg-background shadow-xs" : "",
                    props.class_
                )
            ) {
                HT_SLOT();
            }
        }
    }

    HT_COMPONENT(previous, const previous_props &props) {
        HT_A(
            attr_if(!props.id.empty(), id = props.id),
            attr_if(!props.href.empty(), href = props.href),
            class_ = ui::merge(
                "gap-1 inline-flex items-center justify-center whitespace-nowrap rounded-md text-sm font-medium "
                "hover:bg-accent hover:text-accent-foreground cursor-pointer "
                "h-9 px-4 py-2 has-[>svg]:px-3",
                props.disabled ? "pointer-events-none opacity-50" : "",
                props.class_
            )
        ) {
            if (!props.label.empty()) {
                HT_TAG("span") { HT_TEXT(props.label); }
            }
        }
    }

    HT_COMPONENT(next, const next_props &props) {
        HT_A(
            attr_if(!props.id.empty(), id = props.id),
            attr_if(!props.href.empty(), href = props.href),
            class_ = ui::merge(
                "gap-1 inline-flex items-center justify-center whitespace-nowrap rounded-md text-sm font-medium "
                "hover:bg-accent hover:text-accent-foreground cursor-pointer "
                "h-9 px-4 py-2 has-[>svg]:px-3",
                props.disabled ? "pointer-events-none opacity-50" : "",
                props.class_
            )
        ) {
            if (!props.label.empty()) {
                HT_TAG("span") { HT_TEXT(props.label); }
            }
        }
    }

    HT_COMPONENT(ellipsis) {
        HT_TAG("span", class_ = "flex h-9 w-9 items-center justify-center") {
            HT_TEXT("...");
        }
    }
}
