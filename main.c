#include <SFML/Graphics.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define HEIGHT 420
#define WIDTH 680

sfCircleShape *pointMOD(int x, int y)
{
    sfVector2f position = {(float)x,(float)y};
    sfCircleShape *point = sfCircleShape_create();
    sfCircleShape_setRadius(point, 1);
    sfCircleShape_setFillColor(point, sfWhite);

    sfCircleShape_setPosition(point, position);

    return point;
}

int main()
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "learning csfml", sfResize | sfClose, NULL);
    sfEvent event;
    sfClock* clock = sfClock_create();

    sfRenderWindow_setFramerateLimit(window, 60);

    while (sfRenderWindow_isOpen(window))
    {while (sfRenderWindow_pollEvent(window, &event))
        {   
            if (event.type == sfEvtClosed)sfRenderWindow_close(window);
        }
        sfTime elapsed = sfClock_getElapsedTime(clock);
        sfInt64 milliseconds = sfTime_asMilliseconds(elapsed);

        sfRenderWindow_clear(window, sfBlack);

        for (size_t i = 0; i < 10; i++)
        {
            sfCircleShape *p = pointMOD(WIDTH/2+i*20, HEIGHT/2+sin((milliseconds/200    )+i)*40);
            sfRenderWindow_drawCircleShape(window, p, NULL);
        }
        sfRenderWindow_display(window);
    }    

    sfRenderWindow_destroy(window);
    printf("--NO FATAL ERROR--\n");
    return 0;
}