#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(switch_default) {
    HT_DIV(class_ = "flex flex-col gap-6") {
        HT_DIV(class_ = "flex items-center gap-2") {
            switch_::switch_(os, {.id = "airplane-mode"});
            HT_USE(label::label, {.for_ = "airplane-mode"}) {
                os << "Airplane Mode";
            }
        }
        HT_DIV(class_ = "flex items-start gap-3") {
            switch_::switch_(os, {.id = "marketing", .checked = true});
            HT_DIV(class_ = "grid gap-1.5 leading-none") {
                HT_USE(label::label, {.for_ = "marketing"}) {
                    os << "Marketing emails";
                }
                HT_P(class_ = "text-sm text-muted-foreground") {
                    os << "Receive emails about new products, features, and more.";
                }
            }
        }
        HT_DIV(class_ = "flex items-center gap-2") {
            switch_::switch_(os, {.id = "disabled", .disabled = true});
            HT_USE(label::label, {.class_ = "opacity-50", .for_ = "disabled"}) {
                os << "Disabled Switch";
            }
        }
        HT_USE(label::label, {.class_ = "block cursor-pointer", .for_ = "notifications"}) {
            HT_USE(card::card, {.class_ = "hover:bg-muted/50 transition-colors"}) {
                HT_USE(card::content, {.class_ = "flex items-center justify-between p-4"}) {
                    HT_DIV(class_ = "space-y-0.5") {
                        HT_DIV(class_ = "text-sm font-medium") {
                            os << "Push Notifications";
                        }
                        HT_DIV(class_ = "text-sm text-muted-foreground") {
                            os << "Receive notifications about your account activity.";
                        }
                    }
                    switch_::switch_(os, {.id = "notifications"});
                }
            }
        }
    }
}
