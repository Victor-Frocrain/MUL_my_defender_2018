/*
** EPITECH PROJECT, 2019
** how_to_play
** File description:
** defender
*/

#include "defender.h"

void draw_how_to_play(graph *s)
{
    manage_mouse(s);
    sfRenderWindow_drawText(s->window, s->text[0]->text, NULL);
    for (int i = 7; i < 9 && s->menus[i]; i++) {
        sfSprite_setTextureRect(s->menus[i]->sp, s->menus[i]->rect);
        sfRenderWindow_drawSprite(s->window, s->menus[i]->sp, NULL);
    }
}

void how_to_play(graph *s)
{
    static int k = 1;
    static bool how_begin = false;
    int error = 0;

    if (how_begin == false) {
        s->fd = open("text/how_to_play.txt", O_RDONLY);
        how_begin = true;
    }
    if (sfTime_asMilliseconds
    (sfClock_getElapsedTime(s->clock->howtoplay)) >= 50 &&
    k < 416) {
        sfClock_restart(s->clock->howtoplay);
        error = read(s->fd, s->text[0]->str + k - 1, 1);
        s->text[0]->str[k] = 0;
        k++;
    }
    sfText_setString(s->text[0]->text, s->text[0]->str);
    draw_how_to_play(s);
}
