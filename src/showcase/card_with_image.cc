#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(card_with_image) {
    HT_DIV(class_ = "w-full max-w-sm") {
        HT_USE(card::card, {}) {
            HT_DIV(class_ = "overflow-hidden w-full rounded-t-lg") {
                HT_USE(aspectratio::aspectratio, {.id = "top-media-aspect", .class_ = "h-full w-full", .ratio = aspectratio::video}) {
                    HT_IMG(src = "/assets/img/card_placeholder.jpeg", alt = "Card image", loading = "lazy", class_ = "h-full w-full object-cover");
                }
            }
            HT_USE(card::header, {}) {
                HT_USE(card::title, {}) {
                    os << "Featured Card";
                }
                HT_USE(card::description, {}) {
                    os << "With top image";
                }
            }
            HT_USE(card::content, {}) {
                HT_P() { os << "This card shows top image usage with lazy loading for better performance."; }
            }
            HT_USE(card::footer, {}) {
                HT_USE(button::button, {}) {
                    os << "Learn more";
                }
            }
        }
    }
}
