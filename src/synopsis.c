/*
** EPITECH PROJECT, 2019
** synopsis
** File description:
** my_defender
*/

#include "defender.h"

void draw_synopsis(graph *s)
{
    manage_mouse(s);
    sfRenderWindow_drawText(s->window, s->text[1]->text, NULL);
    sfSprite_setTextureRect(s->menus[8]->sp, s->menus[8]->rect);
    sfRenderWindow_drawSprite(s->window, s->menus[8]->sp, NULL);
}

void synopsis(graph *s)
{
    static int k = 1;
    static bool how_begin = false;
    int error = 0;

    if (how_begin == false) {
        s->fd = open("text/synopsis.txt", O_RDONLY);
        how_begin = true;
    }
    if (sfTime_asMilliseconds
    (sfClock_getElapsedTime(s->clock->howtoplay)) >= 50 &&
    k <= 421) {
        sfClock_restart(s->clock->howtoplay);
        error = read(s->fd, s->text[1]->str + k - 1, 1);
        s->text[1]->str[k] = 0;
        k++;
    }
    sfText_setString(s->text[1]->text, s->text[1]->str);
    draw_synopsis(s);
}
