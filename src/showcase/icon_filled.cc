#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(icon_filled) {
    HT_SPAN() { os << "icon::triangle"; }
}
