#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(time_picker_custom_placeholder) {
    HT_DIV(class_ = "w-full max-w-sm") {
        timepicker::timepicker(os, {.placeholder = "When do you want to meet?"});
    }
}
