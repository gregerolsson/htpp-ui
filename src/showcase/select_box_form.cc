#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(select_box_form) {
    HT_DIV(class_ = "w-full max-w-sm") {
        HT_USE(form::item, {}) {
            HT_USE(form::label, {.for_ = "select-form"}) {
                os << "Fruit";
            }
            HT_USE(selectbox::selectbox, {}) {
                HT_USE(selectbox::trigger, {.id = "select-form", .name = "fruit", .has_error = true}) {
                    selectbox::value(os, {.placeholder = "Select a fruit"});
                }
                HT_USE(selectbox::content, {}) {
                    HT_USE(selectbox::item, {.value = "apple"}) {
                        os << "Apple";
                    }
                    HT_USE(selectbox::item, {.value = "banana"}) {
                        os << "Banana";
                    }
                    HT_USE(selectbox::item, {.value = "blueberry", .selected = true}) {
                        os << "Blueberry";
                    }
                    HT_USE(selectbox::item, {.value = "grapes"}) {
                        os << "Grapes";
                    }
                    HT_USE(selectbox::item, {.value = "pineapple", .disabled = true}) {
                        os << "Pineapple (out of stock)";
                    }
                }
            }
            HT_USE(form::description, {}) {
                os << "Select a fruit category.";
            }
            HT_USE(form::message, {.variant = form::error}) {
                os << "A fruit selection is required.";
            }
        }
    }
}
