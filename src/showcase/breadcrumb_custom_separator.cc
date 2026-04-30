#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(breadcrumb_custom_separator) {
    HT_USE(breadcrumb::breadcrumb, {}) {
        HT_USE(breadcrumb::list, {}) {
            HT_USE(breadcrumb::item, {}) {
                HT_USE(breadcrumb::link, {.href = "/"}) {
                    os << "Home";
                }
            }
            HT_USE(breadcrumb::item, {}) {
                HT_USE(breadcrumb::separator, {.use_custom = true}) {
                    HT_SPAN() { os << "icon::slash"; }
                }
                HT_USE(breadcrumb::link, {.href = "/products"}) {
                    os << "Products";
                }
            }
            HT_USE(breadcrumb::item, {}) {
                HT_USE(breadcrumb::separator, {.use_custom = true}) {
                    HT_SPAN() { os << "icon::slash"; }
                }
                HT_USE(breadcrumb::page, {.current = true}) {
                    os << "Category";
                }
            }
        }
    }
}
