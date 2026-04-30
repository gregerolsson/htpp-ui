#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(input_otp_placeholder) {
    HT_USE(inputotp::inputotp, {}) {
        HT_USE(inputotp::group, {}) {
            inputotp::slot(os, {.index = 0, .placeholder = "•"});
            inputotp::slot(os, {.index = 1, .placeholder = "•"});
            inputotp::slot(os, {.index = 2, .placeholder = "•"});
            inputotp::separator(os, {});
            inputotp::slot(os, {.index = 3, .placeholder = "•"});
            inputotp::slot(os, {.index = 4, .placeholder = "•"});
            inputotp::slot(os, {.index = 5, .placeholder = "•"});
        }
    }
}
