#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(pagination_with_helper) {
    HT_USE(pagination::pagination, {}) {
        HT_USE(pagination::content, {}) {
            HT_USE(pagination::item, {}) {
                pagination::previous(os, {.href = "?page=2", .disabled = false, .label = "Previous"});
            }
            HT_USE(pagination::item, {}) {
                HT_USE(pagination::link, {.href = "?page=1"}) {
                    os << "1";
                }
            }
            HT_USE(pagination::item, {}) {
                HT_USE(pagination::link, {.href = "?page=2"}) {
                    os << "2";
                }
            }
            HT_USE(pagination::item, {}) {
                HT_USE(pagination::link, {.href = "?page=3", .is_active = true}) {
                    os << "3";
                }
            }
            HT_USE(pagination::item, {}) {
                HT_USE(pagination::link, {.href = "?page=4"}) {
                    os << "4";
                }
            }
            HT_USE(pagination::item, {}) {
                pagination::next(os, {.href = "?page=4", .disabled = false, .label = "Next"});
            }
        }
    }
}
