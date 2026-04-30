#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace dropdown {
    constexpr std::string_view placement_str(placement p) {
        switch (p) {
            case placement::top:          return "top";
            case placement::top_start:    return "top-start";
            case placement::top_end:      return "top-end";
            case placement::right:        return "right";
            case placement::right_start:  return "right-start";
            case placement::right_end:    return "right-end";
            case placement::bottom:       return "bottom";
            case placement::bottom_start: return "bottom-start";
            case placement::bottom_end:   return "bottom-end";
            case placement::left:         return "left";
            case placement::left_start:   return "left-start";
            case placement::left_end:     return "left-end";
            default:                      return "bottom-start";
        }
    }

    HT_COMPONENT(script) {
    }

    HT_COMPONENT(dropdown, const dropdown::props &props) {
        HT_USE(popover::root, {.id = props.id}) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(trigger, const trigger_props &props) {
        HT_USE(popover::trigger, {
            .id           = props.id,
            .class_       = props.class_,
            .trigger_type = popover::trigger_type::click,
        }) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(content, const content_props &props) {
        auto pl = (props.placement == placement::bottom) ? placement::bottom_start : props.placement;
        HT_DIV(
            class_ = ui::merge(
                "z-50 rounded-md bg-popover p-1 shadow-md focus:outline-none overflow-auto "
                "border border-border "
                "min-w-[8rem] max-h-[300px]",
                props.class_
            ),
            "data-tui-popover-content"_a = "",
            "data-tui-popover-open"_a = "false",
            "data-tui-popover-placement"_a = placement_str(pl),
            "data-tui-popover-offset"_a = "4",
            "data-tui-popover-exclusive"_a = "true"
        ) {
            HT_DIV(class_ = "w-full overflow-hidden") {
                HT_SLOT();
            }
        }
    }

    HT_COMPONENT(group, const group_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("py-1", props.class_),
            role = "group"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(label, const label_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("px-2 py-1.5 text-sm font-semibold", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(item, const item_props &props) {
        auto item_cls = ui::merge(
            "flex text-left items-center justify-between px-2 py-1.5 text-sm rounded-sm",
            props.disabled
                ? "opacity-50 pointer-events-none"
                : "focus:bg-accent focus:text-accent-foreground hover:bg-accent hover:text-accent-foreground cursor-default",
            props.class_
        );

        if (!props.href.empty()) {
            HT_A(
                attr_if(!props.id.empty(), id = props.id),
                href = props.href,
                attr_if(!props.target.empty(), target = props.target),
                class_ = item_cls,
                role = "menuitem",
                "data-tui-dropdown-item"_a = "",
                attr_if(props.prevent_close, "data-tui-dropdown-prevent-close"_a = "true")
            ) {
                HT_SLOT();
            }
        } else {
            HT_BUTTON(
                attr_if(!props.id.empty(), id = props.id),
                class_ = ui::merge("w-full ", item_cls),
                role = "menuitem",
                "data-tui-dropdown-item"_a = "",
                attr_if(props.disabled, disabled),
                attr_if(props.prevent_close, "data-tui-dropdown-prevent-close"_a = "true"),
                type = "button"
            ) {
                HT_SLOT();
            }
        }
    }

    HT_COMPONENT(separator, const separator_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("h-px my-1 -mx-1 bg-muted", props.class_),
            role = "separator"
        ) {
        }
    }

    HT_COMPONENT(shortcut, const shortcut_props &props) {
        HT_TAG("span",
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("ml-auto text-xs tracking-widest opacity-60", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(sub, const sub_props &props) {
        HT_USE(popover::root, {.id = props.id, .class_ = props.class_}) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(sub_trigger, const sub_trigger_props &props) {
        HT_TAG("span",
            attr_if(!props.id.empty(), id = props.id),
            class_ = "contents",
            "data-tui-popover-trigger"_a = "",
            "data-tui-popover-type"_a = "hover"
        ) {
            HT_BUTTON(
                type = "button",
                "data-tui-dropdown-submenu-trigger"_a = "",
                class_ = ui::merge(
                    "w-full text-left flex items-center justify-between px-2 py-1.5 text-sm rounded-sm "
                    "focus:bg-accent focus:text-accent-foreground hover:bg-accent hover:text-accent-foreground cursor-default",
                    props.class_
                )
            ) {
                HT_TAG("span") { HT_SLOT(); }
            }
        }
    }

    HT_COMPONENT(sub_content, const sub_content_props &props) {
        HT_DIV(
            class_ = ui::merge(
                "z-[9999] min-w-[8rem] rounded-md border bg-popover p-1 shadow-lg",
                props.class_
            ),
            "data-tui-popover-content"_a = "",
            "data-tui-popover-open"_a = "false",
            "data-tui-popover-placement"_a = "right-start",
            "data-tui-popover-offset"_a = "-4",
            "data-tui-popover-hover-delay"_a = "100",
            "data-tui-popover-hover-out-delay"_a = "200"
        ) {
            HT_DIV(class_ = "w-full overflow-hidden") {
                HT_SLOT();
            }
        }
    }
}
