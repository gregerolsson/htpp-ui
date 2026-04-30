#include "htpp.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace chart {
    HT_COMPONENT(script) {
    }

    HT_COMPONENT(chart, const chart::props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("chart-container relative", props.class_)
        ) {
            HT_TAG("canvas", "data-tui-chart"_a = "") {
            }
        }
    }
}
