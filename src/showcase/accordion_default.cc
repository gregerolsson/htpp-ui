#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(accordion_default) {
    HT_DIV(class_ = "w-full max-w-sm") {
        HT_USE(accordion::accordion, {.class_ = "w-full"}) {
            HT_USE(accordion::item, {}) {
                HT_USE(accordion::trigger, {}) {
                    os << "Is it accessible?";
                }
                HT_USE(accordion::content, {}) {
                    os << "Yes. It adheres to the WAI-ARIA design pattern.";
                }
            }
            HT_USE(accordion::item, {}) {
                HT_USE(accordion::trigger, {}) {
                    os << "Is it styled?";
                }
                HT_USE(accordion::content, {}) {
                    os << "Yes. It comes with default styles that matches the other components aesthetic.";
                }
            }
            HT_USE(accordion::item, {}) {
                HT_USE(accordion::trigger, {}) {
                    os << "Is it animated?";
                }
                HT_USE(accordion::content, {}) {
                    os << "Yes. It is animated by default, but you can disable it if you prefer.";
                }
            }
        }
    }
}
