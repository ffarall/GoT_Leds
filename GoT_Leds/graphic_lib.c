#include "graphic_lib.h"

void image_to_display(ALLEGRO_BITMAP *bitmap, const char* filename, float dx, float dy, int flags) {
    bitmap = al_load_bitmap(filename);
    if(!bitmap) {
        fprintf(stderr, "failed to load image !\n");
    }
}
