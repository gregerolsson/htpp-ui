#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(icon_sizes) {
    HT_DIV(class_ = "flex flex-wrap gap-2") {
        HT_SPAN() { os << "icon::house"; }
        HT_SPAN() { os << "icon::house"; }
        HT_SPAN() { os << "icon::house"; }
    }
}
