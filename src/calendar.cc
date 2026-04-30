#include "htpp.hh"
#include "htpp.ui.hh"

#include <string>

using namespace htpp::attr;
using namespace htpp::attr_literals;

namespace calendar {
    constexpr std::string_view locale_tag_str(locale_tag l) {
        switch (l) {
            case locale_tag::chinese:    return "zh-CN";
            case locale_tag::french:     return "fr-FR";
            case locale_tag::german:     return "de-DE";
            case locale_tag::italian:    return "it-IT";
            case locale_tag::japanese:   return "ja-JP";
            case locale_tag::portuguese: return "pt-PT";
            case locale_tag::spanish:    return "es-ES";
            case locale_tag::locale_default:
            default:                     return "en-US";
        }
    }

    constexpr std::string_view weekday_str(weekday w) {
        switch (w) {
            case weekday::sunday:    return "0";
            case weekday::monday:    return "1";
            case weekday::tuesday:   return "2";
            case weekday::wednesday: return "3";
            case weekday::thursday:  return "4";
            case weekday::friday:    return "5";
            case weekday::saturday:  return "6";
            default:                 return "1";
        }
    }

    HT_COMPONENT(script) {
    }

    HT_COMPONENT(calendar, const calendar::props &props) {
        auto month_str = std::to_string(props.initial_month);
        auto year_str  = std::to_string(props.initial_year);
        auto sow_str   = weekday_str(props.start_of_week);

        HT_DIV(
            class_ = ui::merge("inline-flex flex-col [--cell-size:2rem]", props.class_),
            "data-tui-calendar-wrapper"_a = "true"
        ) {
            if (!props.hide_hidden_input) {
                HT_INPUT(
                    type = "hidden",
                    attr_if(!props.name.empty(), name = props.name),
                    attr_if(!props.value.empty(), value = props.value),
                    "data-tui-calendar-hidden-input"_a = ""
                );
            }
            HT_DIV(
                attr_if(!props.id.empty(), id = props.id),
                class_ = "inline-flex flex-col",
                "data-tui-calendar-container"_a = "true",
                "data-tui-calendar-locale-tag"_a = locale_tag_str(props.locale),
                "data-tui-calendar-initial-month"_a = month_str,
                "data-tui-calendar-initial-year"_a = year_str,
                "data-tui-calendar-selected-date"_a = props.value,
                "data-tui-calendar-start-of-week"_a = sow_str
            ) {
                HT_DIV(class_ = "flex w-full items-center gap-2 mb-4") {
                    HT_BUTTON(
                        type = "button",
                        "data-tui-calendar-prev"_a = "",
                        class_ = "inline-flex items-center justify-center rounded-md text-sm font-medium h-7 w-7 hover:bg-accent hover:text-accent-foreground focus:outline-none disabled:opacity-50 shrink-0"
                    ) {
                    }
                    HT_DIV(class_ = "flex gap-2 flex-1 min-w-0") {
                        HT_DIV(class_ = "relative flex-1 has-[:focus]:border-ring border border-input shadow-xs has-[:focus]:ring-ring/50 has-[:focus]:ring-[3px] rounded-md") {
                            HT_SELECT(
                                "data-tui-calendar-month-select"_a = "",
                                class_ = "absolute inset-0 opacity-0 cursor-pointer w-full bg-card",
                                aria_label = "Choose the Month"
                            ) {
                            }
                            HT_TAG("span", class_ = "select-none font-medium rounded-md px-2 flex items-center justify-center gap-1 text-sm h-7 pointer-events-none", aria_hidden = "true") {
                            }
                        }
                        HT_DIV(class_ = "relative flex-1 has-[:focus]:border-ring border border-input shadow-xs has-[:focus]:ring-ring/50 has-[:focus]:ring-[3px] rounded-md") {
                            HT_SELECT(
                                "data-tui-calendar-year-select"_a = "",
                                class_ = "absolute inset-0 opacity-0 cursor-pointer w-full bg-card",
                                aria_label = "Choose the Year"
                            ) {
                            }
                            HT_TAG("span", class_ = "select-none font-medium rounded-md px-2 flex items-center justify-center gap-1 text-sm h-7 pointer-events-none", aria_hidden = "true") {
                            }
                        }
                    }
                    HT_BUTTON(
                        type = "button",
                        "data-tui-calendar-next"_a = "",
                        class_ = "inline-flex items-center justify-center rounded-md text-sm font-medium h-7 w-7 hover:bg-accent hover:text-accent-foreground focus:outline-none disabled:opacity-50 shrink-0"
                    ) {
                    }
                }
                HT_DIV("data-tui-calendar-weekdays"_a = "", class_ = "inline-grid grid-cols-[repeat(7,var(--cell-size))] gap-1 mb-1 place-items-center") {
                }
                HT_DIV("data-tui-calendar-days"_a = "", class_ = "inline-grid grid-cols-[repeat(7,var(--cell-size))] gap-1 place-items-center") {
                }
            }
        }
    }
}
