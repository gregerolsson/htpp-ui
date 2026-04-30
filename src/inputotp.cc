#include "htpp.hh"
#include "htpp.ui.hh"

#include <string>

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace inputotp {
    HT_COMPONENT(script) {
    }

    HT_COMPONENT(inputotp, const inputotp::props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), "id"_a = std::string(props.id) + "-container"),
            attr_if(!props.value.empty(), "data-tui-inputotp-value"_a = props.value),
            attr_if(!props.form.empty(), "form"_a = props.form),
            class_ = ui::merge("flex flex-row items-center gap-2 w-fit", props.class_),
            "data-tui-inputotp"_a = ""
        ) {
            HT_INPUT(
                type = "hidden",
                attr_if(!props.id.empty(), id = props.id),
                attr_if(!props.name.empty(), name = props.name),
                attr_if(props.has_error, "aria-invalid"_a = "true"),
                "data-tui-inputotp-value-target"_a = ""
            );
            HT_SLOT();
        }
    }

    HT_COMPONENT(group, const group_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("flex gap-2", props.class_)
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(slot, const slot_props &props) {
        auto idx_str = std::to_string(props.index);
        auto t       = props.type.empty() ? "text" : props.type;

        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = "relative"
        ) {
            HT_INPUT(
                type = t,
                inputmode = "numeric",
                attr_if(!props.placeholder.empty(), placeholder = props.placeholder),
                maxlength = "1",
                class_ = ui::merge(
                    "w-10 h-12 text-center rounded-md border border-input bg-transparent text-base shadow-xs "
                    "transition-[color,box-shadow] outline-none md:text-sm "
                    "dark:bg-input/30 "
                    "selection:bg-primary selection:text-primary-foreground "
                    "placeholder:text-muted-foreground "
                    "focus-visible:border-ring focus-visible:ring-ring/50 focus-visible:ring-[3px] "
                    "disabled:pointer-events-none disabled:cursor-not-allowed disabled:opacity-50 "
                    "aria-invalid:ring-destructive/20 aria-invalid:border-destructive dark:aria-invalid:ring-destructive/40",
                    props.has_error ? "border-destructive ring-destructive/20 dark:ring-destructive/40" : "",
                    props.class_
                ),
                attr_if(props.disabled, disabled),
                attr_if(props.has_error, "aria-invalid"_a = "true"),
                "data-tui-inputotp-index"_a = idx_str,
                "data-tui-inputotp-slot"_a = ""
            );
        }
    }

    HT_COMPONENT(separator, const separator_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("flex items-center text-muted-foreground text-xl", props.class_)
        ) {
            HT_TAG("span") { HT_TEXT("-"); }
        }
    }
}
