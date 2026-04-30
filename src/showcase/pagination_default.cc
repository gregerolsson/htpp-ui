#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(pagination_default) {
    HT_USE(pagination::pagination, {.class_ = "mt-8"}) {
        HT_USE(pagination::content, {}) {
            HT_USE(pagination::item, {}) {
                pagination::previous(os, {.href = "?page=1", .disabled = false, .label = "Previous"});
            }
            HT_USE(pagination::item, {}) {
                HT_USE(pagination::link, {.href = "?page=1"}) {
                    os << "1";
                }
            }
            HT_USE(pagination::item, {}) {
                HT_USE(pagination::link, {.href = "?page=2", .is_active = true}) {
                    os << "2";
                }
            }
            HT_USE(pagination::item, {}) {
                HT_USE(pagination::link, {.href = "?page=3"}) {
                    os << "3";
                }
            }
            HT_USE(pagination::item, {}) {
                pagination::ellipsis(os);
            }
            HT_USE(pagination::item, {}) {
                pagination::next(os, {.href = "?page=3", .label = "Next"});
            }
        }
    }
}
