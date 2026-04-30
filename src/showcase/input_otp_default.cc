#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(input_otp_default) {
    HT_USE(inputotp::inputotp, {}) {
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
