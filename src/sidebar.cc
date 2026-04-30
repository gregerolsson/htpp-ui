#include "htpp.hh"
#include "ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace sidebar {
    constexpr std::string_view side_str(side s) {
        return (s == side::right) ? "right" : "left";
    }

    constexpr std::string_view variant_str(variant v) {
        switch (v) {
            case variant::floating:       return "floating";
            case variant::inset_variant:  return "inset";
            case variant::sidebar_variant:
            default:                      return "sidebar";
        }
    }

    constexpr std::string_view collapsible_str(collapsible c) {
        switch (c) {
            case collapsible::icon:    return "icon";
            case collapsible::none:    return "none";
            case collapsible::offcanvas:
            default:                   return "offcanvas";
        }
    }

    constexpr std::string_view menu_button_size_str(menu_button_size s) {
        switch (s) {
            case menu_button_size::sm: return "sm";
            case menu_button_size::lg: return "lg";
            case menu_button_size::normal:
            default:                   return "default";
        }
    }

    HT_COMPONENT(script) {
    }

    HT_COMPONENT(layout, const layout_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "flex min-h-svh relative "
                "has-[[data-tui-sidebar-variant=inset]]:bg-sidebar",
                props.class_
            ),
            "data-tui-sidebar-layout"_a = ""
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(sidebar, const sidebar::props &props) {
        auto side_s = side_str(props.side);
        auto var_s  = variant_str(props.variant);
        auto col_s  = collapsible_str(props.collapsible);
        auto state_s = props.collapsed ? "collapsed" : "expanded";
        auto shortcut = props.keyboard_shortcut.empty() ? "b" : props.keyboard_shortcut;

        // Mobile sheet wrapper
        HT_DIV(
            "data-tui-dialog"_a = "",
            "data-tui-sheet"_a = "true",
            "data-tui-sheet-side"_a = side_s,
            "data-tui-dialog-open"_a = "false"
        ) {
        }

        // Desktop sidebar
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("group peer hidden md:block", props.class_),
            "data-tui-sidebar-state"_a = state_s,
            "data-tui-sidebar-collapsible"_a = col_s,
            "data-tui-sidebar-variant"_a = var_s,
            "data-tui-sidebar-side"_a = side_s,
            "data-tui-sidebar-wrapper"_a = "",
            "data-tui-sidebar-keyboard-shortcut"_a = shortcut
        ) {
            HT_DIV(class_ = "relative bg-transparent transition-[width] duration-200 ease-linear w-[var(--sidebar-width,16rem)]") {
            }
            HT_TAG("aside",
                class_ = "fixed inset-y-0 z-10 hidden h-svh transition-transform duration-200 ease-linear md:flex w-[var(--sidebar-width,16rem)]",
                "data-sidebar"_a = "sidebar"
            ) {
                HT_DIV(
                    class_ = "bg-sidebar flex h-full w-full flex-col",
                    "data-sidebar"_a = "sidebar"
                ) {
                    HT_DIV(class_ = "flex h-full w-full flex-col sidebar-content") {
                        HT_SLOT();
                    }
                }
            }
        }
    }

    HT_COMPONENT(trigger, const trigger_props &props) {
        HT_DIV(class_ = "hidden md:block") {
            HT_BUTTON(
                attr_if(!props.id.empty(), id = props.id),
                class_ = ui::merge("size-7", props.class_),
                type = "button",
                "data-tui-sidebar-trigger"_a = "",
                attr_if(!props.target.empty(), "data-tui-sidebar-target"_a = props.target)
            ) {
            }
        }
    }

    HT_COMPONENT(header, const header_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("flex flex-col gap-2 p-2", props.class_),
            "data-tui-sidebar"_a = "header"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(footer, const footer_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("mt-auto flex flex-col gap-2 p-2", props.class_),
            "data-tui-sidebar"_a = "footer"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(content, const content_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "flex min-h-0 flex-1 flex-col gap-2 overflow-auto "
                "group-data-[tui-sidebar-state=collapsed]:group-data-[tui-sidebar-collapsible=icon]:overflow-hidden",
                props.class_
            ),
            "data-tui-sidebar"_a = "content"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(group, const group_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("relative flex w-full min-w-0 flex-col p-2", props.class_),
            "data-tui-sidebar"_a = "group"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(group_label, const group_label_props &props) {
        HT_DIV(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "flex h-8 shrink-0 items-center rounded-md px-2 text-xs font-medium text-sidebar-foreground/70 "
                "ring-sidebar-ring outline-none transition-[margin,opacity] duration-200 ease-linear "
                "focus-visible:ring-2 [&>svg]:size-4 [&>svg]:shrink-0 "
                "group-data-[tui-sidebar-state=collapsed]:group-data-[tui-sidebar-collapsible=icon]:-mt-8 "
                "group-data-[tui-sidebar-state=collapsed]:group-data-[tui-sidebar-collapsible=icon]:opacity-0",
                props.class_
            ),
            "data-tui-sidebar"_a = "group-label"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(menu, const menu_props &props) {
        HT_UL(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("flex w-full min-w-0 flex-col gap-1", props.class_),
            "data-tui-sidebar"_a = "menu"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(menu_item, const menu_item_props &props) {
        HT_LI(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("group/menu-item relative", props.class_),
            "data-tui-sidebar"_a = "menu-item"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(menu_button, const menu_button_props &props) {
        auto size_s = menu_button_size_str(props.size);
        auto btn_cls = ui::merge(
            "flex w-full items-center gap-2 rounded-md p-2 text-left overflow-hidden "
            "hover:bg-sidebar-accent hover:text-sidebar-accent-foreground "
            "transition-[width,height,padding] "
            "data-[tui-sidebar-size=sm]:h-7 data-[tui-sidebar-size=sm]:text-xs "
            "data-[tui-sidebar-size=lg]:h-12 data-[tui-sidebar-size=lg]:text-sm "
            "data-[tui-sidebar-size=default]:h-8 data-[tui-sidebar-size=default]:text-sm "
            "data-[tui-sidebar-active=true]:bg-sidebar-accent data-[tui-sidebar-active=true]:text-sidebar-accent-foreground data-[tui-sidebar-active=true]:font-medium "
            "group-data-[tui-sidebar-state=collapsed]:group-data-[tui-sidebar-collapsible=icon]:!size-8 "
            "group-data-[tui-sidebar-state=collapsed]:group-data-[tui-sidebar-collapsible=icon]:!p-2 "
            "[&>span:last-child]:truncate [&>svg]:size-4 [&>svg]:shrink-0",
            props.class_
        );

        if (!props.href.empty()) {
            HT_A(
                attr_if(!props.id.empty(), id = props.id),
                href = props.href,
                class_ = btn_cls,
                "data-tui-sidebar"_a = "menu-button",
                "data-tui-sidebar-size"_a = size_s,
                attr_if(props.is_active, "data-tui-sidebar-active"_a = "true")
            ) {
                HT_SLOT();
            }
        } else {
            HT_BUTTON(
                attr_if(!props.id.empty(), id = props.id),
                type = "button",
                class_ = btn_cls,
                "data-tui-sidebar"_a = "menu-button",
                "data-tui-sidebar-size"_a = size_s,
                attr_if(props.is_active, "data-tui-sidebar-active"_a = "true")
            ) {
                HT_SLOT();
            }
        }
    }

    HT_COMPONENT(menu_badge, const menu_badge_props &props) {
        HT_TAG("span",
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "ml-auto flex h-5 min-w-5 items-center justify-center rounded-md px-1 text-xs font-medium "
                "bg-sidebar-accent text-sidebar-accent-foreground "
                "group-data-[tui-sidebar-state=collapsed]:group-data-[tui-sidebar-collapsible=icon]:hidden",
                props.class_
            ),
            "data-tui-sidebar"_a = "menu-badge"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(menu_sub, const menu_sub_props &props) {
        HT_UL(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "mx-3.5 flex min-w-0 translate-x-px flex-col gap-1 border-l border-sidebar-border px-2.5 py-0.5 "
                "group-data-[tui-sidebar-state=collapsed]:group-data-[tui-sidebar-collapsible=icon]:hidden",
                props.class_
            ),
            "data-tui-sidebar"_a = "menu-sub"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(menu_sub_item, const menu_sub_item_props &props) {
        HT_LI(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("group/menu-sub-item relative", props.class_),
            "data-tui-sidebar"_a = "menu-sub-item"
        ) {
            HT_SLOT();
        }
    }

    HT_COMPONENT(menu_sub_button, const menu_sub_button_props &props) {
        auto sub_cls = ui::merge(
            "flex items-center gap-2 rounded-md px-2 py-1.5 text-sm "
            "hover:bg-sidebar-accent hover:text-sidebar-accent-foreground "
            "transition-colors "
            "data-[tui-sidebar-active=true]:bg-sidebar-accent data-[tui-sidebar-active=true]:text-sidebar-accent-foreground data-[tui-sidebar-active=true]:font-medium",
            props.class_
        );

        if (!props.href.empty()) {
            HT_A(
                attr_if(!props.id.empty(), id = props.id),
                href = props.href,
                class_ = sub_cls,
                "data-tui-sidebar"_a = "menu-sub-button",
                attr_if(props.is_active, "data-tui-sidebar-active"_a = "true")
            ) {
                HT_SLOT();
            }
        } else {
            HT_BUTTON(
                attr_if(!props.id.empty(), id = props.id),
                type = "button",
                class_ = ui::merge("w-full text-left ", sub_cls),
                "data-tui-sidebar"_a = "menu-sub-button",
                attr_if(props.is_active, "data-tui-sidebar-active"_a = "true")
            ) {
                HT_SLOT();
            }
        }
    }

    HT_COMPONENT(separator, const separator_props &props) {
        HT_VOID("hr",
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge("mx-2 my-2 border-t border-sidebar-border", props.class_),
            "data-tui-sidebar"_a = "separator"
        );
    }

    HT_COMPONENT(inset, const inset_props &props) {
        HT_MAIN(
            attr_if(!props.id.empty(), id = props.id),
            class_ = ui::merge(
                "relative flex w-full flex-1 flex-col bg-background "
                "md:peer-data-[tui-sidebar-variant=inset]:m-2 "
                "md:peer-data-[tui-sidebar-variant=inset]:ml-0 "
                "md:peer-data-[tui-sidebar-variant=inset]:rounded-xl "
                "md:peer-data-[tui-sidebar-variant=inset]:shadow-sm",
                props.class_
            ),
            "data-tui-sidebar"_a = "inset"
        ) {
            HT_SLOT();
        }
    }
}
