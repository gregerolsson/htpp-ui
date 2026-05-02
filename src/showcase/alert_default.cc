#include "htpp.ico.hh"
#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(alert_default) {
    HT_DIV(class_ = "w-full max-w-xl") {
        HT_USE(alert::alert, {}) {
            icon::icon(os, {.glyph = glyph::rocket});
            HT_USE(alert::title, {}) {
                os << "Note";
            }
            HT_USE(alert::description, {}) {
                os << "This is a default alert — check it out!";
            }
        }
    }
}
