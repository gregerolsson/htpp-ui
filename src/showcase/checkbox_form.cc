#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(checkbox_form) {
    HT_DIV(class_ = "w-full max-w-sm") {
        HT_USE(form::item, {}) {
            HT_USE(form::item_flex, {}) {
                checkbox::checkbox(os, {.id = "c1", .name = "interests", .value = "design", .checked = true});
                HT_USE(form::label, {.for_ = "c1"}) {
                    os << "Dessign and UX";
                }
            }
            HT_USE(form::item_flex, {}) {
                checkbox::checkbox(os, {.id = "c2", .name = "interests", .value = "development", .disabled = true});
                HT_USE(form::label, {.for_ = "c2"}) {
                    os << "Development (Coming Soon)";
                }
            }
            HT_USE(form::item_flex, {}) {
                checkbox::checkbox(os, {.id = "c3", .name = "interests", .value = "marketing"});
                HT_USE(form::label, {.for_ = "c3"}) {
                    os << "Business and Marketing";
                }
            }
            HT_USE(form::description, {}) {
                os << "Choose all areas that interest you.";
            }
            HT_USE(form::message, {.variant = form::error}) {
                os << "Please select at least one interest.";
            }
        }
    }
}
