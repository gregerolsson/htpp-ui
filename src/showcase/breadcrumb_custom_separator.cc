#include "htpp.ico.hh"
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
                    icon::icon(os, {
                        .class_ = "size-3.5 text-muted-foreground",
                        .glyph = glyph::slash
                    });
                }
                HT_USE(breadcrumb::link, {.href = "/products"}) {
                    os << "Products";
                }
            }
            HT_USE(breadcrumb::item, {}) {
                HT_USE(breadcrumb::separator, {.use_custom = true}) {
                    icon::icon(os, {
                        .class_ = "size-3.5 text-red-500",
                        .glyph = glyph::slash
                    });
                }
                HT_USE(breadcrumb::page, {.current = true}) {
                    os << "Category";
                }
            }
        }
    }
}
