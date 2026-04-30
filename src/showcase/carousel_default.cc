#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

void carousel_slide(std::ostream& os, std::string_view title, std::string_view desc) {
    HT_USE(card::card, {}) {
        HT_USE(card::content, {}) {
            HT_DIV(class_ = "w-full h-96 flex items-center justify-center") {
                HT_DIV(class_ = "text-center") {
                    HT_H2(class_ = "text-3xl font-bold mb-2") { os << title; }
                    HT_P(class_ = "text-xl") { os << desc; }
                }
            }
        }
    }
}

HT_COMPONENT(carousel_default) {
    HT_USE(carousel::carousel, {.class_ = "rounded-md"}) {
        HT_USE(carousel::content, {}) {
            HT_USE(carousel::item, {}) {
                carousel_slide(os, "Slide 1", "This is the first slide");
            }
            HT_USE(carousel::item, {}) {
                carousel_slide(os, "Slide 2", "This is the second slide");
            }
            HT_USE(carousel::item, {}) {
                carousel_slide(os, "Slide 3", "This is the third slide");
            }
        }
        carousel::previous(os, {});
        carousel::next(os, {});
        carousel::indicators(os, {.count = 3});
    }
}
