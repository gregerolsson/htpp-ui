#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(button_link) {
    HT_USE(button::button, {.variant = button::link}) {
        os << "Link";
    }
}
