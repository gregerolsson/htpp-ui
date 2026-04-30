#include "htpp.hh"
#include "ui.hh"

using namespace htpp::attr;

namespace skeleton {
    HT_COMPONENT(skeleton, const skeleton::props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("animate-pulse rounded bg-muted", props.class_)
        ) {
        }
    }
}
