#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace alert {
    inline constexpr std::string_view alert_base =
        "relative w-full rounded-lg border px-4 py-3 text-sm "
        "grid has-[>svg]:grid-cols-[1rem_1fr] grid-cols-[0_1fr] has-[>svg]:gap-x-3 gap-y-0.5 items-start "
        "[&>svg]:size-4 [&>svg]:translate-y-0.5 [&>svg]:text-current ";

    inline constexpr std::string_view title_base =
        "col-start-2 line-clamp-1 min-h-4 font-medium tracking-tight";

    inline constexpr std::string_view description_base =
        "text-muted-foreground col-start-2 grid justify-items-start "
        "gap-1 text-sm [&_p]:leading-relaxed";

    constexpr std::string_view variant_classes(variant v) {
        switch (v) {
            case variant::normal:
                return "bg-card text-card-foreground";
            case variant::destructive:
                return "text-destructive bg-card [&>svg]:text-current *:data-[slot=alert-description]:text-destructive/90";
        }
        return "";
    }

    HT_COMPONENT(alert, const alert::props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                alert_base,
                variant_classes(props.variant),
                props.class_
            ),
            role = "alert"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(title, const title_props &props) {
        HT_H5(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(title_base, props.class_),
            "data-slot"_a = "alert-title"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(description, const description_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(description_base, props.class_),
            "data-slot"_a = "alert-description"
        ) {
            HT_SLOT();
        }
    }
}
