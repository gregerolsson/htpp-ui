#include "htpp.hh"
#include "htpp.htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace tooltip {
    constexpr popover::placement position_to_placement(position p) {
        switch (p) {
            case position::right:  return popover::placement::right;
            case position::bottom: return popover::placement::bottom;
            case position::left:   return popover::placement::left;
            case position::top:
            default:               return popover::placement::top;
        }
    }

    HT_COMPONENT(script) {
    }

    HT_COMPONENT(tooltip, const tooltip::props &props) {
        HT_USE(popover::root, {.id = props.id, .class_ = props.class_}) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(trigger, const trigger_props &props) {
        HT_USE(popover::trigger, {
            .id           = props.id,
            .class_       = props.class_,
            .trigger_type = popover::trigger_type::hover,
        }) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(content, const content_props &props) {
        HT_USE(popover::content, {
            .id              = props.id,
            .class_          = ui::merge(
                "px-4 py-1 bg-foreground text-background "
                "[&_[data-tui-popover-arrow]]:!bg-foreground [&_[data-tui-popover-arrow]]:!border-0",
                props.class_
            ),
            .placement       = position_to_placement(props.position),
            .show_arrow      = props.show_arrow,
            .hover_delay     = props.hover_delay,
            .hover_out_delay = props.hover_out_delay,
        }) {
            HT_SLOT();
        }
    }
}
