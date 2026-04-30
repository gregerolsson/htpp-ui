#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(button_default) {
    HT_USE(button::button, {}) {
        os << "Button";
    }
}
