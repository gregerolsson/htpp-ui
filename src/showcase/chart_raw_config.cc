#include "htpp.ui.hh"

using namespace htpp::attr;
using namespace htpp::attr_literals;

HT_COMPONENT(chart_raw_config) {
    HT_USE(card::card, {.class_ = "w-full max-w-3xl"}) {
        HT_USE(card::content, {}) {
            chart::chart(os, {
                .class_ = "h-80",
                .raw_config = R"json({"type":"bar","data":{"labels":["Jan","Feb","Mar","Apr","May","Jun"],"datasets":[{"type":"bar","label":"Revenue","data":[18,22,19,27,31,29],"backgroundColor":"rgba(14, 165, 233, 0.25)","borderColor":"rgba(14, 165, 233, 1)","borderWidth":1,"borderRadius":8,"yAxisID":"y"},{"type":"line","label":"Conversion Rate","data":[2.4,2.8,2.6,3.1,3.6,3.4],"borderColor":"rgba(249, 115, 22, 1)","backgroundColor":"rgba(249, 115, 22, 0.18)","pointBackgroundColor":"rgba(249, 115, 22, 1)","pointBorderColor":"rgba(249, 115, 22, 1)","pointRadius":4,"pointHoverRadius":6,"tension":0.35,"fill":true,"yAxisID":"y1"}]},"options":{"responsive":true,"maintainAspectRatio":false,"interaction":{"mode":"index","intersect":false},"plugins":{"legend":{"position":"bottom"},"title":{"display":true,"text":"RawConfig Mixed Chart with Dual Axes"}},"scales":{"y":{"beginAtZero":true,"title":{"display":true,"text":"Revenue (kEUR)"}},"y1":{"beginAtZero":true,"position":"right","grid":{"drawOnChartArea":false},"title":{"display":true,"text":"Conversion Rate (%)"}}}}}})json",
            });
        }
    }
}
