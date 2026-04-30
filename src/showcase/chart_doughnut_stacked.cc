#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(chart_doughnut_stacked) {
    HT_USE(card::card, {.class_ = "max-w-sm"}) {
        HT_USE(card::content, {}) {
            chart::chart(os, {
                .variant = chart::doughnut,
                .data = {
                    .labels = {"Jan", "Feb", "March", "April", "May", "June"},
                    .datasets = {
                        {.label = "Mobile", .data = {3, 9, 3, 12, 7, 8}},
                        {.label = "Desktop", .data = {7, 16, 5, 20, 14, 15}},
                    }
                },
            });
        }
    }
}
