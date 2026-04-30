#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(icon_colored) {
    HT_SPAN() { os << "icon::heart"; }
}
