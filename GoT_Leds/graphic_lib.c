#include "graphic_lib.h"

int refresh_icons(ALLEGRO_DISPLAY* display, icon_t * icon)
 {
   icon_t * current_icon = icon;
   al_set_target_backbuffer(display);
   int targetbitmap;

  for(targetbitmap = 0; targetbitmap<8 && current_icon!=NULL  ; targetbitmap++)
  {
    if( bitGet('A',targetbitmap))
    {
      al_draw_tinted_scaled_bitmap(current_icon->bitmap, al_map_rgba_f(GOLD_FILTER), 0, 0, al_get_bitmap_width(current_icon->bitmap), al_get_bitmap_height(current_icon->bitmap),LEDS_POS_X+targetbitmap*(ICON_WIDTH+25), LEDS_POS_Y, ICON_WIDTH, ICON_HEIGHT, 0);
    }
    else
    {
      al_draw_tinted_scaled_bitmap(current_icon->bitmap, al_map_rgba_f(1, 1, 1, 1), 0, 0, al_get_bitmap_width(current_icon->bitmap), al_get_bitmap_height(current_icon->bitmap),LEDS_POS_X+targetbitmap*(ICON_WIDTH+25), LEDS_POS_Y, ICON_WIDTH, ICON_HEIGHT, 0);
    }
      current_icon = current_icon -> pNextIcon;
  }
    al_flip_display();
 }