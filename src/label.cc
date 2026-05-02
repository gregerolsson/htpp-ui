#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace label {
    HT_COMPONENT(script) {
    }

    HT_COMPONENT(label, const label::props &props) {
        HT_LABEL(
            attr_if(!props.id.empty(), id = props.id),
            attr_if(!props.for_.empty(), for_ = props.for_),
            class_ = ui::merge(
                "text-sm font-medium leading-none inline-block",
                props.error ? "text-destructive" : "",
                props.class_
            ),
            "data-tui-label-disabled-style"_a = "opacity-50 cursor-not-allowed"
        ) {
            HT_SLOT();
        }
    }
}
