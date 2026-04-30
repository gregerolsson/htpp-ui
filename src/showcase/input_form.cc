#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(input_form) {
    HT_DIV(class_ = "w-full max-w-sm") {
        HT_USE(form::item, {}) {
            HT_USE(form::label, {.for_ = "email-form"}) {
                os << "Email";
            }
            input::input(os, {.id = "email-form", .type_ = input::email, .placeholder = "m@example.com", .has_error = true});
            HT_USE(form::description, {}) {
                os << "Enter your email address for notifications.";
            }
            HT_USE(form::message, {.variant = form::error}) {
                os << "Please enter a valid email address";
            }
        }
    }
}
