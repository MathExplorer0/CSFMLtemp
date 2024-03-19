#include "main.h"

int main()
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "learning csfml", sfResize | sfClose, NULL);
    sfEvent event;

    int count = 1;

    sfRenderWindow_setFramerateLimit(window, 60);

    while (sfRenderWindow_isOpen(window))
    {while (sfRenderWindow_pollEvent(window, &event))
        {   
            if (event.type == sfEvtClosed)sfRenderWindow_close(window);
        }

        sfRenderWindow_clear(window, sfBlack);

        for (size_t i = 0; i < 10; i++)
        {
            sfCircleShape *p = pointMOD(WIDTH/2+i*20, HEIGHT/2+sin((count)+i)*40);
            sfRenderWindow_drawCircleShape(window, p, NULL);
        }
        sfRenderWindow_display(window);
        count++;
    }    

    sfRenderWindow_destroy(window);
    printf("--NO FATAL ERROR--\n");
    return 0;
}

sfCircleShape *pointMOD(int x, int y)
{
    sfVector2f position = {(float)x,(float)y};
    sfCircleShape *point = sfCircleShape_create();
    sfCircleShape_setRadius(point, 1);
    sfCircleShape_setFillColor(point, sfWhite);

    sfCircleShape_setPosition(point, position);

    return point;
}

