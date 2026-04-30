#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(textarea_disabled) {
    HT_DIV(class_ = "space-y-2 w-full max-w-md") {
        HT_USE(label::label, {.for_ = "textarea-disabled"}) {
            os << "Your Message";
        }
        textarea::textarea(os, {.id = "textarea-disabled", .disabled = true, .placeholder = "Type your message here..."});
    }
}
