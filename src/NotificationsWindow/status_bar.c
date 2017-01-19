
#include "status_bar.h"

Layer* statusbar;
TextLayer* statusClock;
char clockText[9];

void sb_paint(Layer* layer, GContext* ctx)
{
    GColor backgroundColor = GColorBlack;
    graphics_context_set_fill_color(ctx, backgroundColor);
    graphics_fill_rect(ctx, layer_get_frame(layer), 0, GCornerNone);
}

void sb_load(bool update) {
    statusbar = layer_create(GRect(0, 0, 144, STATUSBAR_Y_OFFSET));

    statusClock = text_layer_create(PBL_IF_ROUND_ELSE(GRect(0, 0, 144, 16), GRect(144 - 144, -12, 144, 100)));
    text_layer_set_background_color(statusClock, GColorClear);
    text_layer_set_text_color(statusClock, GColorWhite);
    text_layer_set_font(statusClock, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
    text_layer_set_text_alignment(statusClock, PBL_IF_ROUND_ELSE(GTextAlignmentCenter, GTextAlignmentRight));
    layer_add_child(statusbar, (Layer*) statusClock);

    if (update) {
        tick_timer_service_subscribe(SECOND_UNIT, (TickHandler) sb_update_clock);
    }
}

void sb_unload(bool update) {
    layer_destroy(statusbar);
    text_layer_destroy(statusClock);
    clockText[0] = 0;

    if (update) {
        tick_timer_service_unsubscribe();
    }
}

void sb_update_clock() {
    time_t now = time(NULL);
    struct tm* lTime = localtime(&now);

    char* formatString;
    if (clock_is_24h_style())
        formatString = "%H:%M";
    else
        formatString = "%I:%M %p";

    char tmpClockText[9];
    strftime(tmpClockText, 9, formatString, lTime);

    // remove leading zero
    if (tmpClockText[0] == '0') {
        for (int i = 0; i < 6; i++) {
            tmpClockText[i] = tmpClockText[i+1];
        }
    }

    //Only update screen when actual clock changes
    if (strcmp(tmpClockText, clockText) != 0)
    {
        strcpy(clockText, tmpClockText);
        text_layer_set_text(statusClock, clockText);
    }
}
