#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(badge_destructive) {
    HT_USE(badge::badge, {.variant = badge::destructive}) {
        os << "Destructive";
    }
}
