#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(tagsinput_suggestions) {
    HT_DIV(class_ = "w-full max-w-sm") {
        tagsinput::tagsinput(os, {.id = "tags-with-suggestions", .placeholder = "Add a tag...", .suggestions = {"Linux", "Windows", "macOS", "Ubuntu", "Debian", "Fedora", "Arch Linux", "CentOS", "FreeBSD"}});
    }
}
