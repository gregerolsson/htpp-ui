#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(input_otp_with_label) {
    HT_DIV(class_ = "w-full max-w-sm flex flex-col gap-2") {
        HT_USE(label::label, {.for_ = "otp-with-label"}) {
            os << "Verification Code";
        }
        HT_USE(inputotp::inputotp, {.id = "otp-with-label", .has_error = true}) {
            HT_USE(inputotp::group, {}) {
                inputotp::slot(os, {.index = 0});
                inputotp::slot(os, {.index = 1});
                inputotp::slot(os, {.index = 2});
                inputotp::slot(os, {.index = 3});
                inputotp::slot(os, {.index = 4});
                inputotp::slot(os, {.index = 5});
            }
        }
    }
}
