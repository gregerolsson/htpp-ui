#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(input_with_label) {
    HT_DIV(class_ = "w-full max-w-sm grid gap-2") {
        HT_USE(label::label, {.for_ = "email"}) {
            os << "Email";
        }
        input::input(os, {.id = "email", .type_ = input::email, .placeholder = "Email"});
    }
}
