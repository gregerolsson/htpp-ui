#include "htpp.ui.hh"

#include <string>

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace tagsinput {
    HT_COMPONENT(script) {
    }

    HT_COMPONENT(tagsinput, const tagsinput::props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), "id"_a = std::string(props.id) + "-container"),
            class_ = ui::merge(
                "flex flex-col gap-2 p-2 rounded-md border border-input bg-transparent shadow-xs transition-[color,box-shadow] outline-none "
                "dark:bg-input/30 "
                "focus-within:border-ring focus-within:ring-ring/50 focus-within:ring-[3px] "
                "w-full",
                props.disabled ? "opacity-50 cursor-not-allowed" : "",
                props.has_error ? "border-destructive ring-destructive/20 dark:ring-destructive/40" : "",
                props.class_
            ),
            "data-tui-tagsinput"_a = "",
            "data-tui-tagsinput-name"_a = props.name,
            "data-tui-tagsinput-form"_a = props.form
        ) {
            // Tags row
            HT_DIV(class_ = "flex flex-wrap gap-2 empty:hidden", "data-tui-tagsinput-chips"_a = "") {
                for (const auto &tag : props.value) {
                    HT_TAG("span", class_ = "inline-flex items-center rounded-md border px-2 py-0.5 text-xs font-medium", "data-tui-tagsinput-chip"_a = "") {
                        HT_TAG("span") { HT_TEXT(tag); }
                        HT_BUTTON(
                            type = "button",
                            class_ = "ml-1 text-current hover:text-destructive disabled:opacity-50 disabled:cursor-not-allowed cursor-pointer",
                            attr_if(props.disabled, disabled),
                            "data-tui-tagsinput-remove"_a = ""
                        ) {
                        }
                    }
                }
            }
            // Input row
            HT_DIV(class_ = "relative w-full") {
                HT_INPUT(
                    attr_if(!props.id.empty(), id = props.id),
                    class_ = "border-0 shadow-none focus-visible:ring-0 h-auto py-0 px-0 bg-transparent rounded-none min-h-0 w-full outline-none",
                    type = "text",
                    attr_if(!props.placeholder.empty(), placeholder = props.placeholder),
                    attr_if(props.disabled, disabled),
                    attr_if(props.readonly, readonly),
                    "data-tui-tagsinput-text-input"_a = ""
                );
            }
            // Hidden inputs
            HT_DIV(class_ = "hidden", "data-tui-tagsinput-hidden-inputs"_a = "") {
                for (const auto &tag : props.value) {
                    HT_INPUT(type = "hidden", name = props.name, value = tag);
                }
            }
        }
    }
}
