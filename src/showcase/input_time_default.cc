#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(input_time_default) {
    HT_DIV(class_ = "w-full max-w-sm") {
        input::input(os, {.type_ = input::time_, .value = "10:30"});
    }
}
