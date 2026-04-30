#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(badge_default) {
    HT_USE(badge::badge, {}) {
        os << "Badge";
    }
}
