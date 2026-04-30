#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(time_picker_step) {
    HT_DIV(class_ = "w-full max-w-sm") {
        timepicker::timepicker(os, {.step = 15, .placeholder = "Select time (15 min intervals)"});
    }
}
