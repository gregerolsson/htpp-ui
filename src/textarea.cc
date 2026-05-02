#include "htpp.ui.hh"

#include <string>

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace textarea {
    HT_COMPONENT(script) {
    }

    HT_COMPONENT(textarea, const textarea::props &props) {
        HT_TEXTAREA(
            attr_if(!props.id.empty(), id = props.id),
            "data-tui-textarea"_a = "",
            attr_if(!props.name.empty(), name = props.name),
            attr_if(!props.form.empty(), "form"_a = props.form),
            attr_if(!props.placeholder.empty(), placeholder = props.placeholder),
            attr_if(props.rows > 0, rows = std::to_string(props.rows)),
            attr_if(props.disabled, disabled),
            attr_if(props.readonly, readonly),
            attr_if(props.has_error, "aria-invalid"_a = "true"),
            attr_if(props.auto_resize, "data-tui-textarea-auto-resize"_a = "true"),
            class_ = ui::merge(
                "flex w-full min-w-0 rounded-md border border-input bg-transparent px-3 py-1 text-base shadow-xs "
                "transition-[color,box-shadow] outline-none md:text-sm "
                "min-h-[80px] "
                "dark:bg-input/30 "
                "selection:bg-primary selection:text-primary-foreground "
                "placeholder:text-muted-foreground "
                "focus-visible:border-ring focus-visible:ring-ring/50 focus-visible:ring-[3px] "
                "disabled:pointer-events-none disabled:cursor-not-allowed disabled:opacity-50 "
                "aria-invalid:ring-destructive/20 aria-invalid:border-destructive dark:aria-invalid:ring-destructive/40",
                props.has_error ? "border-destructive ring-destructive/20 dark:ring-destructive/40" : "",
                props.auto_resize ? "overflow-hidden resize-none" : "",
                props.class_
            )
        ) {
            HT_TEXT(props.value);
        }
    }
}
