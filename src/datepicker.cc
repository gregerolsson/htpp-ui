#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace datepicker {
    constexpr std::string_view format_str(format f) {
        switch (f) {
            case format::locale_short:  return "locale-short";
            case format::locale_medium: return "locale-medium";
            case format::locale_long:   return "locale-long";
            case format::locale_full:   return "locale-full";
            default:                    return "locale-medium";
        }
    }

    constexpr std::string_view locale_tag_str(locale_tag l) {
        switch (l) {
            case locale_tag::chinese:    return "zh-CN";
            case locale_tag::french:     return "fr-FR";
            case locale_tag::german:     return "de-DE";
            case locale_tag::italian:    return "it-IT";
            case locale_tag::japanese:   return "ja-JP";
            case locale_tag::portuguese: return "pt-PT";
            case locale_tag::spanish:    return "es-ES";
            case locale_tag::locale_default:
            default:                     return "en-US";
        }
    }

    HT_COMPONENT(script) {
    }

    HT_COMPONENT(datepicker, const datepicker::props &props) {
        auto placeholder = props.placeholder.empty() ? "Select a date" : props.placeholder;
        auto fmt_s       = format_str(props.format);
        auto loc_s       = locale_tag_str(props.locale);

        HT_DIV(
            class_ = "relative inline-block w-full",
            "data-tui-datepicker-root"_a = ""
        ) {
            HT_INPUT(
                type = "hidden",
                attr_if(!props.name.empty(), name = props.name),
                attr_if(!props.value.empty(), value = props.value),
                attr_if(!props.form.empty(), "form"_a = props.form),
                "data-tui-datepicker-hidden-input"_a = ""
            );
            HT_BUTTON(
                attr_if(!props.id.empty(), id = props.id),
                class_ = ui::merge(
                    "w-full h-9 px-3 py-1 text-base md:text-sm "
                    "flex items-center justify-between "
                    "rounded-md border border-input bg-transparent shadow-xs transition-[color,box-shadow] outline-none "
                    "dark:bg-input/30 "
                    "selection:bg-primary selection:text-primary-foreground "
                    "focus-visible:border-ring focus-visible:ring-ring/50 focus-visible:ring-[3px] "
                    "aria-invalid:ring-destructive/20 aria-invalid:border-destructive dark:aria-invalid:ring-destructive/40",
                    props.has_error ? "border-destructive ring-destructive/20 dark:ring-destructive/40" : "",
                    props.class_
                ),
                attr_if(props.disabled, disabled),
                "data-tui-datepicker"_a = "true",
                "data-tui-datepicker-display-format"_a = fmt_s,
                "data-tui-datepicker-locale-tag"_a = loc_s,
                "data-tui-datepicker-placeholder"_a = placeholder,
                attr_if(props.has_error, "aria-invalid"_a = "true"),
                type = "button"
            ) {
                HT_TAG("span",
                    "data-tui-datepicker-display"_a = "",
                    class_ = "text-left grow text-muted-foreground"
                ) {
                    HT_TEXT(placeholder);
                }
            }
        }
    }
}
