#include "htpp.hh"
#include "ui.hh"

using namespace htpp::attr;

namespace card {
    HT_COMPONENT(card, const card::props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("w-full rounded-lg border bg-card text-card-foreground shadow-xs", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(header, const header_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("flex flex-col space-y-1.5 p-6 pb-0", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(title, const title_props &props) {
        HT_H3(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("text-lg font-semibold leading-none tracking-tight", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(description, const description_props &props) {
        HT_P(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("text-sm text-muted-foreground", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(content, const content_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("p-6", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(footer, const footer_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("flex items-center p-6 pt-0", props.class_)
        ) {
            HT_SLOT();
        }
    }
}
