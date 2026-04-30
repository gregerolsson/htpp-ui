#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(checkbox_default) {
    HT_DIV(class_ = "flex flex-col gap-6") {
        HT_DIV(class_ = "flex items-center gap-3") {
            checkbox::checkbox(os, {.id = "terms", .name = "agreements", .value = "terms"});
            HT_USE(label::label, {.for_ = "terms"}) {
                os << "Accept terms and conditions";
            }
        }
        HT_DIV(class_ = "flex items-start gap-3") {
            checkbox::checkbox(os, {.id = "newsletter", .name = "agreements", .value = "newsletter", .checked = true});
            HT_DIV(class_ = "grid gap-2") {
                HT_USE(label::label, {.for_ = "newsletter"}) {
                    os << "Subscribe to newsletter";
                }
                HT_P(class_ = "text-muted-foreground text-sm") {
                    os << "Get notified about new features and updates.";
                }
            }
        }
        HT_DIV(class_ = "flex items-center gap-3") {
            checkbox::checkbox(os, {.id = "cookies", .name = "agreements", .value = "cookies", .disabled = true});
            HT_USE(label::label, {.for_ = "cookies"}) {
                os << "Use essential cookies only";
            }
        }
        HT_USE(label::label, {.class_ = "block cursor-pointer", .for_ = "premium"}) {
            HT_USE(card::card, {.class_ = "hover:border-primary/50 has-[:checked]:ring-1 has-[:checked]:ring-primary has-[:checked]:border-primary transition-all"}) {
                HT_USE(card::content, {.class_ = "p-3 flex items-start gap-3"}) {
                    checkbox::checkbox(os, {.id = "premium", .name = "agreements", .value = "premium"});
                    HT_DIV(class_ = "grid gap-1.5") {
                        HT_P(class_ = "text-sm leading-none font-medium") {
                            os << "Enable premium features";
                        }
                        HT_P(class_ = "text-muted-foreground text-sm") {
                            os << "Unlock advanced functionality and priority support.";
                        }
                    }
                }
            }
        }
    }
}
