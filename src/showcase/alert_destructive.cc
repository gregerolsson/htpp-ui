#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(alert_destructive) {
    HT_DIV(class_ = "w-full max-w-xl") {
        HT_USE(alert::alert, {.variant = alert::destructive}) {
            HT_SPAN() { os << "icon::triangle_alert"; }
            HT_USE(alert::title, {}) {
                os << "Error";
            }
            HT_USE(alert::description, {}) {
                os << "Your session has expired. Please log in again.";
            }
        }
    }
}
