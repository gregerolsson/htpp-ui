#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(tooltip_default) {
    HT_USE(tooltip::tooltip, {}) {
        HT_USE(tooltip::trigger, {}) {
            HT_USE(button::button, {.variant = button::outline}) {
                os << "Hover Me";
            }
        }
        HT_USE(tooltip::content, {.id = "tooltip-default", .position = tooltip::top, .hover_delay = 500, .hover_out_delay = 100}) {
            os << "Add to cart";
        }
    }
}
