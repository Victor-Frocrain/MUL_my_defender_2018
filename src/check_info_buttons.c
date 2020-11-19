/*
** EPITECH PROJECT, 2019
** check infos
** File description:
** defender
*/

#include "defender.h"

void text_info_buttons(graph *s, int i)
{
    if (i == 3)
        draw_text1(s);
    if (i == 4)
        draw_text2(s);
    if (i == 5)
        draw_text3(s);
    if (i == 6)
        draw_text4(s);
}

void position_info_buttons(graph *s, int i)
{
    sfFloatRect bounds = sfSprite_getGlobalBounds(s->menus[13]->sp);

    init_scales5(s);
    s->menus[13]->pos.x = (WIDTH - 400) - (bounds.width / 2);
    if (i == 3)
        s->menus[13]->pos.y = HEIGHT - 700;
    if (i == 4)
        s->menus[13]->pos.y = HEIGHT - 600;
    if (i == 5)
        s->menus[13]->pos.y = HEIGHT - 500;
    if (i == 6)
        s->menus[13]->pos.y = HEIGHT - 400;
    if (i == 3 || i == 4 || i == 5 || i == 6) {
        sfSprite_setPosition(s->menus[13]->sp, s->menus[13]->pos);
        sfRenderWindow_drawSprite(s->window, s->menus[13]->sp, NULL);
        text_info_buttons(s, i);
    }
}
