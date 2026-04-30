#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(date_picker_disabled) {
    HT_DIV(class_ = "w-full max-w-sm") {
        datepicker::datepicker(os, {.disabled = true});
    }
}
