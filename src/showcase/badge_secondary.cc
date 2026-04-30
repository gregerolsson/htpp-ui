#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(badge_secondary) {
    HT_USE(badge::badge, {.variant = badge::secondary}) {
        os << "Secondary";
    }
}
