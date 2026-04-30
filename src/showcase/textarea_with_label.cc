#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(textarea_with_label) {
    HT_DIV(class_ = "space-y-2 w-full max-w-md") {
        HT_USE(label::label, {.for_ = "textarea-with-label"}) {
            os << "Your Message";
        }
        textarea::textarea(os, {.id = "textarea-with-label", .placeholder = "Type your message here...", .rows = 4});
    }
}
