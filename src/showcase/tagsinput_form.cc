#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(tagsinput_form) {
    HT_DIV(class_ = "w-full max-w-sm") {
        HT_USE(form::item, {}) {
            HT_USE(form::label, {.for_ = "tags-form"}) {
                os << "Net";
            }
            tagsinput::tagsinput(os, {.id = "tags-form", .placeholder = "Enter a network", .has_error = true});
            HT_USE(form::description, {}) {
                os << "Enter a network in format like '1.1.1.1/32'";
            }
            HT_USE(form::message, {.variant = form::error}) {
                os << "Please enter a valid network in format like '1.1.1.1/32'";
            }
        }
    }
}
