#include <SFML/Graphics.h>
#include <math.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define AMPLITUDE 100
#define FREQUENCY 0.1
#define POINT_COUNT 800 // Number of points in the circular buffer

sfRenderWindow *window = NULL;
sfCircleShape *points[POINT_COUNT]; // Circular buffer for points
float xOffset = 0.0f; // Offset for moving the wave horizontally

void handleEvents() {
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void createPoint(sfCircleShape *point, float x, float y) {
    sfCircleShape_setRadius(point, 1);
    sfCircleShape_setFillColor(point, sfWhite);
    sfCircleShape_setPosition(point, (sfVector2f){x, y});
}

void updatePoints() {
    for (int i = 0; i < WIDTH; i++) {
        float x = i;
        float y = HEIGHT / 2 + sin((x + xOffset) * FREQUENCY) * AMPLITUDE;
        createPoint(points[i % POINT_COUNT], x, y); // Reuse points in the circular buffer
    }
    xOffset += 0.01f; // Adjust horizontal speed here
}

void drawSineWave() {
    sfRenderWindow_clear(window, sfBlack);
    for (int i = 0; i < POINT_COUNT; i++) {
        sfRenderWindow_drawCircleShape(window, points[i], NULL);
    }
    sfRenderWindow_display(window);
}

int main() {
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    window = sfRenderWindow_create(mode, "Smoothly Moving Sine Wave", sfResize | sfClose, NULL);
    if (!window) {
        // Window creation failed
        return EXIT_FAILURE;
    }

    // Initialize circular buffer with points
    for (int i = 0; i < POINT_COUNT; i++) {
        points[i] = sfCircleShape_create();
    }

    while (sfRenderWindow_isOpen(window)) {
        handleEvents();
        updatePoints();
        drawSineWave();
    }

    // Clean up resources
    for (int i = 0; i < POINT_COUNT; i++) {
        sfCircleShape_destroy(points[i]);
    }
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}
