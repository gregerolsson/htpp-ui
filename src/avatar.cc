#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace avatar {
    HT_COMPONENT(script) {
    }

    HT_COMPONENT(avatar, const avatar::props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "relative flex h-10 w-10 shrink-0 overflow-hidden rounded-full",
                props.class_
            ),
            "data-tui-avatar"_a = ""
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(image, const image_props &props) {
        HT_IMG(
            attr_if(!props.id.empty(), id = props.id),
            attr_if(!props.src.empty(), src = props.src),
            alt = props.alt,
            class_ = ui::merge("aspect-square h-full w-full", props.class_),
            "data-tui-avatar-image"_a = ""
        );
    }

    HT_COMPONENT(fallback, const fallback_props &props) {
        HT_TAG("span",
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "flex h-full w-full items-center justify-center rounded-full bg-muted",
                props.class_
            ),
            "data-tui-avatar-fallback"_a = ""
        ) {
            HT_SLOT();
        }
    }
}
