#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(input_otp_form) {
    HT_USE(form::item, {}) {
        HT_USE(form::label, {.for_ = "otp-form"}) {
            os << "Verification Code";
        }
        HT_USE(inputotp::inputotp, {.id = "otp-form", .has_error = true}) {
            HT_USE(inputotp::group, {}) {
                inputotp::slot(os, {.index = 0});
                inputotp::slot(os, {.index = 1});
                inputotp::slot(os, {.index = 2});
                inputotp::separator(os, {});
                inputotp::slot(os, {.index = 3});
                inputotp::slot(os, {.index = 4});
                inputotp::slot(os, {.index = 5});
            }
        }
        HT_USE(form::description, {}) {
            os << "Enter the 6-digit code sent to your phone";
        }
        HT_USE(form::message, {.variant = form::error}) {
            os << "Invalid verification code.";
        }
    }
}
