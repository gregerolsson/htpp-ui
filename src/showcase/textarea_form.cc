#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(textarea_form) {
    HT_DIV(class_ = "w-full max-w-md") {
        HT_USE(form::item, {}) {
            HT_USE(form::label, {.for_ = "textarea-form"}) {
                os << "Your Message";
            }
            textarea::textarea(os, {.id = "textarea-form", .name = "message", .placeholder = "Type your message here..."});
            HT_USE(form::description, {}) {
                os << "Please type your message in the textarea.";
            }
            HT_USE(form::message, {.variant = form::error}) {
                os << "This message is required.";
            }
        }
    }
}
