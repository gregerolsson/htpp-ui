#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(time_picker_label) {
    HT_DIV(class_ = "flex flex-col gap-2 w-full max-w-sm") {
        HT_USE(label::label, {.for_ = "time-picker-label"}) {
            os << "Select a time";
        }
        timepicker::timepicker(os, {.id = "time-picker-label", .use_12_hours = true});
    }
}
