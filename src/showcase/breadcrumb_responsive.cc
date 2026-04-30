#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(breadcrumb_responsive) {
    HT_DIV(class_ = "md:hidden") {
        HT_USE(breadcrumb::breadcrumb, {}) {
            HT_USE(breadcrumb::list, {}) {
                HT_USE(breadcrumb::item, {}) {
                    HT_USE(breadcrumb::link, {.href = "/"}) {
                        os << "Home";
                    }
                }
                breadcrumb::separator(os, {});
                HT_USE(breadcrumb::item, {}) {
                    HT_USE(breadcrumb::link, {.href = "#"}) {
                        os << "...";
                    }
                }
                breadcrumb::separator(os, {});
                HT_USE(breadcrumb::item, {}) {
                    HT_USE(breadcrumb::page, {.current = true}) {
                        os << "Current Page";
                    }
                }
            }
        }
    }
    HT_DIV(class_ = "hidden md:block") {
        HT_USE(breadcrumb::breadcrumb, {}) {
            HT_USE(breadcrumb::list, {}) {
                HT_USE(breadcrumb::item, {}) {
                    HT_USE(breadcrumb::link, {.href = "/"}) {
                        os << "Home";
                    }
                }
                breadcrumb::separator(os, {});
                HT_USE(breadcrumb::item, {}) {
                    HT_USE(breadcrumb::link, {.href = "/category"}) {
                        os << "Category";
                    }
                }
                breadcrumb::separator(os, {});
                HT_USE(breadcrumb::item, {}) {
                    HT_USE(breadcrumb::link, {.href = "/category/subcategory"}) {
                        os << "Subcategory";
                    }
                }
                breadcrumb::separator(os, {});
                HT_USE(breadcrumb::item, {}) {
                    HT_USE(breadcrumb::page, {.current = true}) {
                        os << "Current Page";
                    }
                }
            }
        }
    }
}
