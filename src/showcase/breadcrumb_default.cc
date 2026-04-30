#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(breadcrumb_default) {
    HT_USE(breadcrumb::breadcrumb, {}) {
        HT_USE(breadcrumb::list, {}) {
            HT_USE(breadcrumb::item, {}) {
                HT_USE(breadcrumb::link, {.href = "/"}) {
                    os << "Home";
                }
            }
            HT_USE(breadcrumb::item, {}) {
                breadcrumb::separator(os, {});
                HT_USE(breadcrumb::link, {.href = "/docs"}) {
                    os << "Documentation";
                }
            }
            HT_USE(breadcrumb::item, {}) {
                breadcrumb::separator(os, {});
                HT_USE(breadcrumb::page, {.current = true}) {
                    os << "Components";
                }
            }
        }
    }
}
