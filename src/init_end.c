/*
** EPITECH PROJECT, 2019
** init scale buttons end
** File description:
** defender
*/

#include "defender.h"

void init_scales6(graph *s)
{
    sfVector2f buttons = {1.7, 1.7};
    sfFloatRect bounds;

    sfSprite_setScale(s->menus[12]->sp, buttons);
    bounds = sfSprite_getGlobalBounds(s->menus[12]->sp);
    s->menus[12]->pos.x = (WIDTH / 2) + 500;
    s->menus[12]->pos.y = HEIGHT - (5.5 * 145) + 10;
    sfSprite_setPosition(s->menus[12]->sp, s->menus[12]->pos);
    sfSprite_setScale(s->menus[10]->sp, buttons);
    bounds = sfSprite_getGlobalBounds(s->menus[10]->sp);
    s->menus[10]->pos.x = (WIDTH / 2) + 500;
    s->menus[10]->pos.y = HEIGHT - (5.5 * 110) + 10;
    sfSprite_setPosition(s->menus[10]->sp, s->menus[10]->pos);
    sfSprite_setScale(s->menus[2]->sp, buttons);
    bounds = sfSprite_getGlobalBounds(s->menus[2]->sp);
    s->menus[2]->pos.x = (WIDTH / 2) + 500;
    s->menus[2]->pos.y = HEIGHT - (5.5 * 75) + 10;
    sfSprite_setPosition(s->menus[2]->sp, s->menus[2]->pos);
}

void draw_buttons_end(graph *s)
{
    sfSprite_setTextureRect(s->menus[10]->sp, s->menus[10]->rect);
    sfRenderWindow_drawSprite(s->window, s->menus[10]->sp, NULL);
    sfSprite_setTextureRect(s->menus[12]->sp, s->menus[12]->rect);
    sfRenderWindow_drawSprite(s->window, s->menus[12]->sp, NULL);
    sfSprite_setTextureRect(s->menus[2]->sp, s->menus[2]->rect);
    sfRenderWindow_drawSprite(s->window, s->menus[2]->sp, NULL);
}
