#include "htpp.ico.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(breadcrumb_with_icons) {
    HT_USE(breadcrumb::breadcrumb, {}) {
        HT_USE(breadcrumb::list, {}) {
            HT_USE(breadcrumb::item, {}) {
                HT_USE(breadcrumb::link, {.href = "/"}) {
                    icon::icon(os, {
                        .class_ = "size-4",
                        .glyph = glyph::house
                    });
                    HT_SPAN(class_ = "ml-1") { os << "Home"; }
                }
            }
            HT_USE(breadcrumb::item, {}) {
                breadcrumb::separator(os, {});
                HT_USE(breadcrumb::link, {.href = "/docs"}) {
                    icon::icon(os, {
                        .class_ = "size-4",
                        .glyph = glyph::file_text
                    });
                    HT_SPAN(class_ = "ml-1") { os << "Documentation"; }
                }
            }
            HT_USE(breadcrumb::item, {}) {
                breadcrumb::separator(os, {});
                HT_USE(breadcrumb::page, {.current = true}) {
                    icon::icon(os, {
                        .class_ = "size-4",
                        .glyph = glyph::component
                    });
                    HT_SPAN(class_ = "ml-1") { os << "Components"; }
                }
            }
        }
    }
}
