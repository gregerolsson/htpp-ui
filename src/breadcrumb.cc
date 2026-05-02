#include "htpp.ico.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;

namespace breadcrumb {
    HT_COMPONENT(breadcrumb, const breadcrumb::props &props) {
        HT_NAV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("flex", props.class_),
            aria_label = "Breadcrumb"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(list, const list_props &props) {
        HT_TAG("ol",
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("flex items-center flex-wrap gap-1 text-sm", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(item, const item_props &props) {
        HT_LI(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("flex items-center", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(link, const link_props &props) {
        HT_A(
            attr_if(!props.id.empty(), id = props.id),
            attr_if(!props.href.empty(), href = props.href),
            class_ = ui::merge(
                "text-muted-foreground hover:text-foreground hover:underline flex items-center gap-1.5 transition-colors",
                props.class_
            )
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(separator, const separator_props &props) {
        HT_TAG("span",
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("mx-2 text-muted-foreground", props.class_)
        ) {
            if (props.use_custom) {
                HT_SLOT();
            }
            else {
                icon::icon(os, {
                    .class_ = "size-3.5 text-muted-foreground",
                    .glyph = glyph::chevron_right
                });
            }
        }
    }

    HT_COMPONENT(page, const item_props &props) {
        HT_TAG("span",
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("font-medium text-foreground flex items-center gap-1.5", props.class_),
            aria_current = "page"
        ) {
            HT_SLOT();
        }
    }
}
