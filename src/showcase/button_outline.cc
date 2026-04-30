#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(button_outline) {
    HT_USE(button::button, {.variant = button::outline}) {
        os << "Outline";
    }
}
