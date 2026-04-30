#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(badge_outline) {
    HT_USE(badge::badge, {.variant = badge::outline}) {
        os << "Outline";
    }
}
