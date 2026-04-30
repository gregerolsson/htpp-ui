#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(input_otp_custom_length) {
    HT_USE(inputotp::inputotp, {.id = "otp-custom-length"}) {
        HT_USE(inputotp::group, {}) {
            inputotp::slot(os, {.index = 0});
            inputotp::slot(os, {.index = 1});
            inputotp::slot(os, {.index = 2});
        }
    }
}
