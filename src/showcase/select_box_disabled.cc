#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(select_box_disabled) {
    HT_DIV(class_ = "space-y-2 w-full max-w-sm") {
        HT_USE(selectbox::selectbox, {}) {
            HT_USE(selectbox::trigger, {.disabled = true}) {
                selectbox::value(os, {.placeholder = "Select a fruit"});
            }
            HT_USE(selectbox::content, {}) {
                HT_USE(selectbox::label, {}) {
                    os << "Fruits";
                }
                HT_USE(selectbox::item, {.value = "apple"}) {
                    os << "Apple";
                }
                HT_USE(selectbox::item, {.value = "banana"}) {
                    os << "Banana";
                }
            }
        }
    }
}
