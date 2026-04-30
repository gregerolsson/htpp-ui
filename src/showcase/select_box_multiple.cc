#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(select_box_multiple) {
    HT_DIV(class_ = "w-full max-w-sm") {
        HT_USE(selectbox::selectbox, {}) {
            HT_USE(selectbox::trigger, {.multiple = true}) {
                selectbox::value(os, {.placeholder = "Select a fruit"});
            }
            HT_USE(selectbox::content, {}) {
                HT_USE(selectbox::group, {}) {
                    HT_USE(selectbox::label, {}) {
                        os << "Fruits";
                    }
                    HT_USE(selectbox::item, {.value = "apple"}) {
                        os << "Apple";
                    }
                    HT_USE(selectbox::item, {.value = "banana"}) {
                        os << "Banana";
                    }
                    HT_USE(selectbox::item, {.value = "blueberry"}) {
                        os << "Blueberry";
                    }
                    HT_USE(selectbox::item, {.value = "grapes"}) {
                        os << "Grapes";
                    }
                    HT_USE(selectbox::item, {.value = "pineapple"}) {
                        os << "Pineapple";
                    }
                }
            }
        }
    }
}
