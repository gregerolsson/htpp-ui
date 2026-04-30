#include "htpp.ui.hh"
#include <iostream>

using namespace htpp::attr;

struct layout_props {
    std::string_view name;
};

HT_COMPONENT_DECL(layout, const layout_props& props);

HT_COMPONENT(layout, const layout_props& props) {
    HT_DOCTYPE();
    HT_HTML(lang = "en") {
        HT_HEAD() {
            HT_META(charset = "utf-8");
            HT_TITLE() { os << props.name; }
        }
        HT_BODY() {
            HT_SLOT();
        }
    }
}

int main() {
    auto& os = std::cout;

    HT_USE(layout, {.name = "accordion.cc"}) {
        HT_USE(accordion::accordion, {}) {
            HT_USE(accordion::item, {}) {
				HT_USE(accordion::trigger, {}) {
					os << "Is it accessible?";
				}
				HT_USE(accordion::content, {}) {
					os << "Yes. It adheres to the WAI-ARIA design pattern.";
				}
			}
        }
    }
}
