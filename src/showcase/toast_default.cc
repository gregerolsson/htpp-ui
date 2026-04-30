#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(toast_default) {
    HT_DIV() {
        HT_FORM(class_ = "flex flex-col gap-2", hx_post = "/docs/toast/demo", hx_trigger = "submit", hx_target = "#toast-container", hx_vals = R"({"title": "You have a new notification", "description": "Test Notification", "dismissible": "on"})") {
            HT_USE(button::button, {.variant = button::outline, .type_ = button::submit}) {
                os << "Show Toast";
            }
        }
        HT_DIV(id = "toast-container") {}
    }
}
