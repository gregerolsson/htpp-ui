#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(time_picker_min_max) {
    HT_DIV(class_ = "w-full max-w-sm") {
        timepicker::timepicker(os, {.min_time = "09:00", .max_time = "17:00", .step = 30, .placeholder = "Business hours (9AM-5PM)"});
    }
}
