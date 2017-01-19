
#ifndef NOTIFICATIONCENTER_STATUS_BAR_H
#define NOTIFICATIONCENTER_STATUS_BAR_H

#include <pebble.h>
#include "../NotificationCenter.h"

extern Layer* statusbar;
extern TextLayer* statusClock;
extern char clockText[9];

void sb_paint(Layer* layer, GContext* ctx);
void sb_load(bool update);
void sb_unload(bool update);
void sb_update_clock();

#endif //NOTIFICATIONCENTER_STATUS_BAR_H
