#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(input_disabled) {
    HT_DIV(class_ = "w-full max-w-sm") {
        input::input(os, {.type_ = input::email, .placeholder = "Email", .disabled = true});
    }
}
