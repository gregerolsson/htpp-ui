#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(button_primary) {
    HT_USE(button::button, {}) {
        os << "Primary";
    }
}
