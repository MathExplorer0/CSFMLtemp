#include <SFML/Graphics.h>
#include <math.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600


void drawPoint(sfRenderWindow *window, float x, float y) 
{
    sfCircleShape *point = sfCircleShape_create();
    sfCircleShape_setRadius(point, 1);
    sfCircleShape_setFillColor(point, sfWhite);
    sfCircleShape_setPosition(point, (sfVector2f){x, y});
    sfRenderWindow_drawCircleShape(window, point, NULL);
    sfCircleShape_destroy(point);
}

int main() 
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Draw Point", sfResize | sfClose, NULL);
    sfEvent event;
    
    sfRenderWindow_setFramerateLimit(window, 60);
    
    size_t counter = 1;

    while (sfRenderWindow_isOpen(window)) 
    {while (sfRenderWindow_pollEvent(window, &event)){
        if (event.type == sfEvtClosed)sfRenderWindow_close(window);}

        sfRenderWindow_clear(window, sfBlack);
        for (size_t i = 0; i < 300; i++)
        {
            drawPoint(window, 5*i, HEIGHT/2 + sin(counter*0.1 + i * 0.3) * 50);
        }
        sfRenderWindow_display(window);

        counter++;
        printf("%ld\n", counter);
    } 
    sfRenderWindow_destroy(window);
    return 0;
}