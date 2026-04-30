#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(radio_default) {
    HT_DIV(class_ = "flex flex-col gap-6") {
        HT_DIV(class_ = "flex flex-col gap-3") {
            HT_DIV(class_ = "flex items-start gap-3") {
                radio::radio(os, {.id = "plan-1", .name = "options", .value = "free"});
                HT_DIV(class_ = "grid gap-2") {
                    HT_USE(label::label, {.for_ = "plan-1"}) {
                        os << "Free Plan";
                    }
                }
            }
            HT_DIV(class_ = "flex items-start gap-3") {
                radio::radio(os, {.id = "plan-2", .name = "options", .value = "pro", .checked = true});
                HT_DIV(class_ = "grid gap-2") {
                    HT_USE(label::label, {.for_ = "plan-2"}) {
                        os << "Pro Plan";
                    }
                    HT_P(class_ = "text-muted-foreground text-sm") {
                        os << "Unlock advanced features and priority support.";
                    }
                }
            }
        }
        HT_DIV(class_ = "flex items-center gap-3") {
            radio::radio(os, {.id = "enterprise-option", .name = "options", .value = "enterprise", .disabled = true});
            HT_USE(label::label, {.for_ = "enterprise-option"}) {
                os << "Enterprise Plan (Coming Soon)";
            }
        }
        HT_USE(label::label, {.class_ = "block cursor-pointer", .for_ = "card-option"}) {
            HT_USE(card::card, {.class_ = "hover:border-primary/50 has-[:checked]:ring-1 has-[:checked]:ring-primary has-[:checked]:border-primary transition-all"}) {
                HT_USE(card::content, {.class_ = "p-3 flex items-start gap-3"}) {
                    radio::radio(os, {.id = "card-option", .name = "options", .value = "premium"});
                    HT_DIV(class_ = "grid gap-1.5") {
                        HT_P(class_ = "text-sm leading-none font-medium") {
                            os << "Premium Features";
                        }
                        HT_P(class_ = "text-muted-foreground text-sm") {
                            os << "Access all premium features with unlimited usage.";
                        }
                    }
                }
            }
        }
    }
}
