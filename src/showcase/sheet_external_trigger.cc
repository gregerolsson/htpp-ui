#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(sheet_external_trigger) {
    HT_USE(sheet::sheet, {.id = "external-trigger-demo", .side = sheet::right}) {
        HT_USE(sheet::content, {}) {
            HT_USE(sheet::header, {}) {
                HT_USE(sheet::title, {}) {
                    os << "External Trigger";
                }
                HT_USE(sheet::description, {}) {
                    os << "This sheet has no internal trigger";
                }
            }
            HT_DIV(class_ = "flex-1 p-4") {
                HT_P(class_ = "text-sm text-muted-foreground") {
                    os << "The trigger button exists outside the Sheet component.";
                }
            }
            HT_USE(sheet::footer, {}) {
                HT_USE(sheet::close, {}) {
                    HT_USE(button::button, {.variant = button::outline}) {
                        os << "Close";
                    }
                }
            }
        }
    }
    HT_USE(sheet::trigger, {.for_ = "external-trigger-demo"}) {
        HT_USE(button::button, {.variant = button::outline}) {
            os << "Open Sheet";
        }
    }
}
