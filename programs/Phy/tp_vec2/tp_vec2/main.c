#include "gfx/gfx.h"
#include "vec2/vec2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

double rand_dbl() {
    return 2.0 * ((double)rand()) / RAND_MAX - 0.5;
}

int main() {
    srand(time(NULL));
    struct gfx_context_t *ctxt =
        gfx_create("Vec2 demo", SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!ctxt) {
        fprintf(stderr, "Graphics initialization failed!\n");
        return EXIT_FAILURE;
    }

    vec2 center   = vec2_create(0.0, 0.0);
    double radius = 0.5;
    for (int i = 0; i < 250000; i++) {

        vec2 r = vec2_create(rand_dbl(), rand_dbl());

        // Draw pixel if in circle
        if (vec2_norm(vec2_sub(r, center)) < radius) {
            coordinates pixel =
                vec2_to_coordinates(r, SCREEN_WIDTH, SCREEN_HEIGHT);
            // Random color (not black)
            uint32_t color = rand() % 0xFFFFFF;

            gfx_putpixel(ctxt, pixel.column, pixel.row, color);
        }
    }

    gfx_present(ctxt);
    while (true) {
        if (gfx_keypressed() == SDLK_ESCAPE) {
            break;
        }
    }
    gfx_destroy(ctxt);
    return EXIT_SUCCESS;
}
