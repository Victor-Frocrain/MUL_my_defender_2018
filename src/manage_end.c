/*
** EPITECH PROJECT, 2019
** defender
** File description:
** end
*/

#include "defender.h"

void manage_end(graph *s)
{
    if (s->scene->end) {
        init_scales6(s);
        manage_mouse(s);
        sfRenderWindow_drawSprite(s->window, s->back[6]->sp, NULL);
        display_score(s);
        draw_buttons_end(s);
    }
}
