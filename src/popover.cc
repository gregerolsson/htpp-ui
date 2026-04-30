#include "htpp.hh"
#include "htpp.ui.hh"

#include <string>

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace popover {
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
            default:                      return "bottom";
        }
    }

    constexpr std::string_view trigger_type_str(trigger_type t) {
        switch (t) {
            case trigger_type::hover:  return "hover";
            case trigger_type::manual: return "manual";
            case trigger_type::click:
            default:                   return "click";
        }
    }

    HT_COMPONENT(script) {
    }

    HT_COMPONENT(root, const root_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            "data-tui-popover-root"_a = "",
            class_ = ui::merge("contents", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(trigger, const trigger_props &props) {
        HT_TAG("span",
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("contents", props.class_),
            "data-tui-popover-trigger"_a = "",
            "data-tui-popover-type"_a = trigger_type_str(props.trigger_type)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(content, const content_props &props) {
        int offset = props.offset;
        if (offset == 0) {
            offset = props.show_arrow ? 8 : 4;
        }
        auto offset_str          = std::to_string(offset);
        auto hover_delay_str     = std::to_string(props.hover_delay);
        auto hover_out_delay_str = std::to_string(props.hover_out_delay);

        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            "popover"_a = "manual",
            "data-tui-popover-content"_a = "",
            "data-tui-popover-open"_a = "false",
            "data-tui-popover-placement"_a = placement_str(props.placement),
            "data-tui-popover-offset"_a = offset_str,
            "data-tui-popover-disable-clickaway"_a = (props.disable_click_away ? "true" : "false"),
            "data-tui-popover-disable-esc"_a = (props.disable_esc ? "true" : "false"),
            "data-tui-popover-show-arrow"_a = (props.show_arrow ? "true" : "false"),
            "data-tui-popover-hover-delay"_a = hover_delay_str,
            "data-tui-popover-hover-out-delay"_a = hover_out_delay_str,
            "data-tui-popover-exclusive"_a = (props.exclusive ? "true" : "false"),
            class_ = ui::merge(
                "bg-popover rounded-lg border text-popover-foreground text-sm shadow-lg pointer-events-auto "
                "fixed inset-auto top-0 left-0 m-0 max-w-[min(24rem,calc(100vw-2rem))] overflow-visible outline-none "
                "transition-opacity duration-150 ease-out "
                "data-[tui-popover-open=false]:opacity-0 data-[tui-popover-open=true]:opacity-100 "
                "motion-reduce:transition-none",
                props.class_
            )
        ) {
            HT_DIV(class_ = "w-full overflow-hidden") {
                HT_SLOT();
            }
            if (props.show_arrow) {
                HT_DIV(
                    "data-tui-popover-arrow"_a = "",
                    class_ = "absolute h-2.5 w-2.5 rotate-45 bg-popover border border-border"
                ) {
                }
            }
        }
    }
}
