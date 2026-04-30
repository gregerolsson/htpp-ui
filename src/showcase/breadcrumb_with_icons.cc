#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(breadcrumb_with_icons) {
    HT_USE(breadcrumb::breadcrumb, {}) {
        HT_USE(breadcrumb::list, {}) {
            HT_USE(breadcrumb::item, {}) {
                HT_USE(breadcrumb::link, {.href = "/"}) {
                    HT_SPAN() { os << "icon::house"; }
                    HT_SPAN(class_ = "ml-1") { os << "Home"; }
                }
            }
            HT_USE(breadcrumb::item, {}) {
                breadcrumb::separator(os, {});
                HT_USE(breadcrumb::link, {.href = "/docs"}) {
                    HT_SPAN() { os << "icon::file_text"; }
                    HT_SPAN(class_ = "ml-1") { os << "Documentation"; }
                }
            }
            HT_USE(breadcrumb::item, {}) {
                breadcrumb::separator(os, {});
                HT_USE(breadcrumb::page, {.current = true}) {
                    HT_SPAN() { os << "icon::component"; }
                    HT_SPAN(class_ = "ml-1") { os << "Components"; }
                }
            }
        }
    }
}
