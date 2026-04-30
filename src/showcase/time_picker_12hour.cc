#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(time_picker_12hour) {
    HT_DIV(class_ = "w-full max-w-sm") {
        timepicker::timepicker(os, {.use_12_hours = true});
    }
}
