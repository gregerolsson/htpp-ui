#include "htpp.hh"
#include "ui.hh"

using namespace htpp::attr;

namespace badge {
    inline constexpr std::string_view badge_base =
        "inline-flex items-center justify-center rounded-md border px-2 py-0.5 text-xs font-medium w-fit whitespace-nowrap shrink-0 "
        "[&>svg]:size-3 gap-1 [&>svg]:pointer-events-none "
        "focus-visible:border-ring focus-visible:ring-ring/50 focus-visible:ring-[3px] "
        "aria-invalid:ring-destructive/20 dark:aria-invalid:ring-destructive/40 aria-invalid:border-destructive "
        "transition-[color,box-shadow] overflow-hidden";

    constexpr std::string_view variant_classes(variant v) {
        switch (v) {
            case variant::destructive:
                return "border-transparent bg-destructive text-white [a&]:hover:bg-destructive/90 "
                       "focus-visible:ring-destructive/20 dark:focus-visible:ring-destructive/40 dark:bg-destructive/60";
            case variant::outline:
                return "text-foreground [a&]:hover:bg-accent [a&]:hover:text-accent-foreground";
            case variant::secondary:
                return "border-transparent bg-secondary text-secondary-foreground [a&]:hover:bg-secondary/90";
            case variant::normal:
            default:
                return "border-transparent bg-primary text-primary-foreground [a&]:hover:bg-primary/90";
        }
    }

    HT_COMPONENT(badge, const badge::props &props) {
        HT_TAG("span",
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(badge_base, variant_classes(props.variant), props.class_)
        ) {
            HT_SLOT();
        }
    }
}
