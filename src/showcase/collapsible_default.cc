#include "htpp.ico.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(collapsible_default) {
    HT_USE(collapsible::collapsible, {.class_ = "w-[350px] space-y-2"}) {
        HT_DIV(class_ = "flex items-center justify-between space-x-4 px-4") {
            HT_H4(class_ = "text-sm font-semibold") {
                os << "@axadrn";
                os << " starred 3 repositories";
            }
            HT_USE(collapsible::trigger, {}) {
                HT_USE(button::button, {.class_ = "size-8", .variant = button::ghost, .size = button::icon}) {
                    icon::icon(os, {.glyph = glyph::chevrons_up_down});
                    HT_SPAN(class_ = "sr-only") { os << "Toggle"; }
                }
            }
        }
        HT_DIV(class_ = "rounded-md border px-4 py-2 font-mono text-sm") {
            os << "github.com/a-h/templ";
        }
        HT_USE(collapsible::content, {.class_ = "space-y-2"}) {
            HT_DIV(class_ = "rounded-md border px-4 py-2 font-mono text-sm") {
                os << "github.com/charmbracelet/bubbletea";
            }
            HT_DIV(class_ = "rounded-md border px-4 py-2 font-mono text-sm") {
                os << "github.com/labstack/echo";
            }
        }
    }
}
