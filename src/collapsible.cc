#include "htpp.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace collapsible {
    HT_COMPONENT(script) {
    }

    HT_COMPONENT(collapsible, const collapsible::props &props) {
        HT_DIV(
            id = props.id,
            class_ = ui::merge(props.class_),
            "data-tui-collapsible"_a = "root",
            "data-tui-collapsible-state"_a = (props.open ? "open" : "closed")
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(trigger, const trigger_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(props.class_),
            "data-tui-collapsible"_a = "trigger"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(content, const content_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "grid grid-rows-[0fr] transition-[grid-template-rows] duration-200 ease-out "
                "[&.tui-collapsible-open]:grid-rows-[1fr]",
                props.class_
            ),
            "data-tui-collapsible"_a = "content"
        ) {
            HT_DIV(class_ = "overflow-hidden") {
                HT_SLOT();
            }
        }
    }
}
