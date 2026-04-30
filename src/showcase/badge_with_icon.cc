#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(badge_with_icon) {
    HT_USE(badge::badge, {.class_ = "flex gap-2 items-center"}) {
        HT_SPAN() { os << "icon::rocket"; }
        os << "With Icon";
    }
}
