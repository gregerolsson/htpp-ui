#include "htpp.ui.hh"

using namespace htpp::attr;

namespace form {
    constexpr std::string_view message_variant_class(message_variant v) {
        switch (v) {
            case message_variant::error: return "text-red-500";
            case message_variant::info:  return "text-blue-500";
            default:                     return "";
        }
    }

    HT_COMPONENT(item, const item_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("space-y-2", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(item_flex, const item_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("items-center flex space-x-2", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(label, const label_props &props) {
        HT_LABEL(
            attr_if(!props.id.empty(), id = props.id),
            attr_if(!props.for_.empty(), for_ = props.for_),
            class_ = ui::merge(
                "text-sm font-medium leading-none inline-block",
                props.class_
            )
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

    HT_COMPONENT(message, const message_props &props) {
        HT_P(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "text-[0.8rem] font-medium",
                message_variant_class(props.variant),
                props.class_
            )
        ) {
            HT_SLOT();
        }
    }
}
