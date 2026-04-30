#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(button_loading) {
    HT_USE(button::button, {.class_ = "flex items-center gap-2", .disabled = true}) {
        HT_SPAN() { os << "icon::loader_circle"; }
        os << "Please wait";
    }
}
