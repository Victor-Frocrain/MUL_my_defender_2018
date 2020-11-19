/*
** EPITECH PROJECT, 2019
** display
** File description:
** display
*/

#include "defender.h"

void fill_land(graph *s)
{
    int total = (WIDTH / 60) * (HEIGHT / 60);
    int i = 0;

    srand(sfTime_asMicroseconds
    (sfClock_getElapsedTime(s->clock->game)));
    s->land = malloc(sizeof(char) * (total + 1));
    s->init_land = true;
    if (s->land == NULL)
        return;
    for (i = 0; i < total; i++) {
        if (rand() % 12 == 11)
            s->land[i] = 'A';
        else
            s->land[i] = 'B';
    }
    s->land[i] = 0;
}

void display_land(graph *s)
{
    s->map[0]->pos.x = 0;
    s->map[0]->pos.y = 0;
    if (s->init_land == false)
        fill_land(s);
    for (int i = 0; s->map[0]->pos.y < HEIGHT ||
    s->map[0]->pos.x < WIDTH; i++) {
        if (s->land && s->land[i] == 'A')
            s->map[0]->rect.top = 0;
        else
            s->map[0]->rect.top = 60;
        sfSprite_setTextureRect(s->map[0]->sp, s->map[0]->rect);
        sfSprite_setPosition(s->map[0]->sp, s->map[0]->pos);
        sfRenderWindow_drawSprite(s->window, s->map[0]->sp, NULL);
        if (s->map[0]->pos.x >= WIDTH) {
            s->map[0]->pos.x = 0;
            s->map[0]->pos.y += 60;
        }
        else
            s->map[0]->pos.x += 60;
    }
}

void draw_main(graph *s)
{
    manage_mouse(s);
    sfRenderWindow_drawSprite(s->window, s->back[0]->sp, NULL);
    for (int i = 0; i < 3 && s->menus[i]; i++) {
        sfSprite_setTextureRect(s->menus[i]->sp, s->menus[i]->rect);
        sfRenderWindow_drawSprite(s->window, s->menus[i]->sp, NULL);
    }
}
