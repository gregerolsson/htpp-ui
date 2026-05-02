#include "htpp.ui.hh"

using namespace htpp::attr;

namespace button {
    inline constexpr std::string_view button_base =
        "inline-flex items-center justify-center gap-2 whitespace-nowrap rounded-md text-sm font-medium transition-all "
        "disabled:pointer-events-none disabled:opacity-50 [&_svg]:pointer-events-none [&_svg:not([class*='size-'])]:size-4 shrink-0 [&_svg]:shrink-0 "
        "outline-none focus-visible:border-ring focus-visible:ring-ring/50 focus-visible:ring-[3px] "
        "aria-invalid:ring-destructive/20 dark:aria-invalid:ring-destructive/40 aria-invalid:border-destructive "
        "cursor-pointer";

    constexpr std::string_view variant_classes(variant v) {
        switch (v) {
            case variant::destructive:
                return "bg-destructive text-white shadow-xs hover:bg-destructive/90 "
                       "focus-visible:ring-destructive/20 dark:focus-visible:ring-destructive/40 dark:bg-destructive/60";
            case variant::outline:
                return "border bg-background shadow-xs hover:bg-accent hover:text-accent-foreground "
                       "dark:bg-input/30 dark:border-input dark:hover:bg-input/50";
            case variant::secondary:
                return "bg-secondary text-secondary-foreground shadow-xs hover:bg-secondary/80";
            case variant::ghost:
                return "hover:bg-accent hover:text-accent-foreground dark:hover:bg-accent/50";
            case variant::link:
                return "text-primary underline-offset-4 hover:underline";
            case variant::normal:
            default:
                return "bg-primary text-primary-foreground shadow-xs hover:bg-primary/90";
        }
    }

    constexpr std::string_view size_classes(size s) {
        switch (s) {
            case size::sm:   return "h-8 rounded-md gap-1.5 px-3 has-[>svg]:px-2.5";
            case size::lg:   return "h-10 rounded-md px-6 has-[>svg]:px-4";
            case size::icon: return "size-9";
            case size::medium:
            default:         return "h-9 px-4 py-2 has-[>svg]:px-3";
        }
    }

    constexpr std::string_view type_str(type_ t) {
        switch (t) {
            case type_::reset:  return "reset";
            case type_::submit: return "submit";
            case type_::btn:
            default:            return "button";
        }
    }

    HT_COMPONENT(button, const button::props &props) {
        auto cls = ui::merge(
            button_base,
            variant_classes(props.variant),
            size_classes(props.size),
            props.full_width ? "w-full" : "",
            props.class_
        );

        if (!props.href.empty() && !props.disabled) {
            HT_A(
                attr_if(!props.id.empty(), id = props.id),
                href = props.href,
                attr_if(!props.target.empty(), target = props.target),
                class_ = cls
            ) {
                HT_SLOT();
            }
        } else {
            HT_BUTTON(
                attr_if(!props.id.empty(), id = props.id),
                class_ = cls,
                type = type_str(props.type_),
                attr_if(!props.form.empty(), htpp::attr::form = props.form),
                attr_if(props.disabled, disabled)
            ) {
                HT_SLOT();
            }
        }
    }
}
