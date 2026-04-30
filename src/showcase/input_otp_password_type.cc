#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(input_otp_password_type) {
    HT_USE(inputotp::inputotp, {.id = "otp-password"}) {
        HT_USE(inputotp::group, {}) {
            inputotp::slot(os, {.index = 0, .type = "password"});
            inputotp::slot(os, {.index = 1, .type = "password"});
            inputotp::slot(os, {.index = 2, .type = "password"});
            inputotp::separator(os, {});
            inputotp::slot(os, {.index = 3, .type = "password"});
            inputotp::slot(os, {.index = 4, .type = "password"});
            inputotp::slot(os, {.index = 5, .type = "password"});
        }
    }
}
