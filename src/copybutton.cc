#include "htpp.hh"
#include "ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace copybutton {
    HT_COMPONENT(script) {
    }

    HT_COMPONENT(copybutton, const copybutton::props &props) {
        HT_DIV(
            "data-copy-button"_a = "",
            "data-target-id"_a = props.target_id,
            class_ = "inline-block"
        ) {
            HT_BUTTON(
                attr_if(!props.id.empty(), id = props.id),
                class_ = ui::merge(
                    "h-7 w-7 text-muted-foreground hover:text-accent-foreground",
                    props.class_
                ),
                type = "button"
            ) {
                HT_SPAN("data-copy-icon-clipboard"_a = "") {}
                HT_SPAN("data-copy-icon-check"_a = "", class_ = "hidden") {}
            }
        }
    }
}
