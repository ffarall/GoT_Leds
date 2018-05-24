#include "graphic_lib.h"

void image_to_display(ALLEGRO_BITMAP *bitmap, const char* filename, float dx, float dy, int flags) {
    bitmap = al_load_bitmap(filename);
    if(!bitmap) {
        fprintf(stderr, "failed to load image !\n");
    }
    
    al_draw_bitmap(bitmap, dx, dy, flags);
    al_flip_display();
}

icon_t init_icon(float dx, float dy, int flags) {
    icon_t icon;
    icon.coordinates[0] = dx;
    icon.coordinates[1] = dy;
    icon.flags = flags;
}
