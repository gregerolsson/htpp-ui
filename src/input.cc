#include "htpp.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace input {
    constexpr std::string_view type_str(type_ t) {
        switch (t) {
            case type_::password:  return "password";
            case type_::email:     return "email";
            case type_::number:    return "number";
            case type_::tel:       return "tel";
            case type_::url:       return "url";
            case type_::search:    return "search";
            case type_::date:      return "date";
            case type_::date_time: return "datetime-local";
            case type_::time_:     return "time";
            case type_::file:      return "file";
            case type_::color:     return "color";
            case type_::week:      return "week";
            case type_::month:     return "month";
            case type_::text:
            default:               return "text";
        }
    }

    HT_COMPONENT(script) {
    }

    HT_COMPONENT(input, const input::props &props) {
        auto t = props.type_;
        bool is_password = (t == type_::password);

        HT_DIV(class_ = "relative w-full") {
            HT_INPUT(
                attr_if(!props.id.empty(), id = props.id),
                type = type_str(t),
                attr_if(!props.name.empty(), name = props.name),
                attr_if(!props.placeholder.empty(), placeholder = props.placeholder),
                attr_if(!props.value.empty(), value = props.value),
                attr_if(t == type_::file && !props.file_accept.empty(), accept = props.file_accept),
                attr_if(!props.form.empty(), "form"_a = props.form),
                attr_if(props.disabled, disabled),
                attr_if(props.readonly, readonly),
                attr_if(props.required, required),
                attr_if(props.has_error, "aria-invalid"_a = "true"),
                class_ = ui::merge(
                    "flex h-9 w-full min-w-0 rounded-md border border-input bg-transparent px-3 py-1 text-base shadow-xs "
                    "transition-[color,box-shadow] outline-none md:text-sm "
                    "dark:bg-input/30 "
                    "selection:bg-primary selection:text-primary-foreground "
                    "placeholder:text-muted-foreground "
                    "file:inline-flex file:h-7 file:border-0 file:bg-transparent file:text-sm file:font-medium file:text-foreground "
                    "focus-visible:border-ring focus-visible:ring-ring/50 focus-visible:ring-[3px] "
                    "disabled:pointer-events-none disabled:cursor-not-allowed disabled:opacity-50 "
                    "aria-invalid:ring-destructive/20 aria-invalid:border-destructive dark:aria-invalid:ring-destructive/40",
                    props.has_error ? "border-destructive ring-destructive/20 dark:ring-destructive/40" : "",
                    (is_password && !props.no_toggle_password) ? "pr-8" : "",
                    props.class_
                )
            );
            if (is_password && !props.no_toggle_password) {
                HT_BUTTON(
                    class_ = "absolute right-0 top-1/2 -translate-y-1/2 opacity-50 cursor-pointer",
                    "data-tui-input-toggle-password"_a = props.id,
                    type = "button"
                ) {
                    HT_TAG("span", class_ = "icon-open block") {
                    }
                    HT_TAG("span", class_ = "icon-closed hidden") {
                    }
                }
            }
        }
    }
}
