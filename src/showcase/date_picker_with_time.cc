#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(date_picker_with_time) {
    HT_DIV(class_ = "flex gap-4") {
        HT_DIV(class_ = "flex flex-col gap-3") {
            HT_USE(label::label, {.class_ = "px-1", .for_ = "date-picker"}) {
                os << "Date";
            }
            datepicker::datepicker(os, {.id = "date-picker"});
        }
        HT_DIV(class_ = "flex flex-col gap-3") {
            HT_USE(label::label, {.class_ = "px-1", .for_ = "time-picker"}) {
                os << "Time";
            }
            input::input(os, {.id = "time-picker", .class_ = "appearance-none [&::-webkit-calendar-picker-indicator]:hidden [&::-webkit-calendar-picker-indicator]:appearance-none", .type_ = input::time_, .value = "10:30:00"});
        }
    }
}
