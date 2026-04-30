#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(tooltip_positions) {
    HT_DIV(class_ = "flex gap-2") {
        HT_USE(tooltip::tooltip, {}) {
            HT_USE(tooltip::trigger, {}) {
                HT_USE(button::button, {.variant = button::outline}) {
                    os << "Top";
                }
            }
            HT_USE(tooltip::content, {.id = "top-tooltip", .show_arrow = true, .position = tooltip::top, .hover_delay = 500, .hover_out_delay = 100}) {
                os << "Tooltip on top";
            }
        }
        HT_USE(tooltip::tooltip, {}) {
            HT_USE(tooltip::trigger, {}) {
                HT_USE(button::button, {.variant = button::outline}) {
                    os << "Right";
                }
            }
            HT_USE(tooltip::content, {.id = "right-tooltip", .show_arrow = true, .position = tooltip::right, .hover_delay = 500, .hover_out_delay = 100}) {
                os << "Tooltip on right";
            }
        }
        HT_USE(tooltip::tooltip, {}) {
            HT_USE(tooltip::trigger, {}) {
                HT_USE(button::button, {.variant = button::outline}) {
                    os << "Bottom";
                }
            }
            HT_USE(tooltip::content, {.id = "bottom-tooltip", .show_arrow = true, .position = tooltip::bottom, .hover_delay = 500, .hover_out_delay = 100}) {
                os << "Tooltip on bottom";
            }
        }
        HT_USE(tooltip::tooltip, {}) {
            HT_USE(tooltip::trigger, {}) {
                HT_USE(button::button, {.variant = button::outline}) {
                    os << "Left";
                }
            }
            HT_USE(tooltip::content, {.id = "left-tooltip", .show_arrow = true, .position = tooltip::left, .hover_delay = 500, .hover_out_delay = 100}) {
                os << "Tooltip on left";
            }
        }
    }
}
