#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(input_time_styled) {
    HT_DIV(class_ = "w-full max-w-sm") {
        input::input(os, {.class_ = "appearance-none [&::-webkit-calendar-picker-indicator]:hidden [&::-webkit-calendar-picker-indicator]:appearance-none", .type_ = input::time_, .value = "10:30:00"});
    }
}
