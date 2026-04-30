#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(input_otp_custom_styling) {
    HT_USE(inputotp::inputotp, {.id = "otp-styled"}) {
        HT_USE(inputotp::group, {.class_ = "gap-3"}) {
            inputotp::slot(os, {.class_ = "w-12 h-14 bg-primary/10 border-primary text-lg font-bold", .index = 0});
            inputotp::slot(os, {.class_ = "w-12 h-14 bg-primary/10 border-primary text-lg font-bold", .index = 1});
            inputotp::slot(os, {.class_ = "w-12 h-14 bg-primary/10 border-primary text-lg font-bold", .index = 2});
            HT_USE(inputotp::separator, {.class_ = "text-2xl font-bold text-primary"}) {
                HT_SPAN() { os << ":"; }
            }
            inputotp::slot(os, {.class_ = "w-12 h-14 bg-primary/10 border-primary text-lg font-bold", .index = 3});
            inputotp::slot(os, {.class_ = "w-12 h-14 bg-primary/10 border-primary text-lg font-bold", .index = 4});
            inputotp::slot(os, {.class_ = "w-12 h-14 bg-primary/10 border-primary text-lg font-bold", .index = 5});
        }
    }
}
