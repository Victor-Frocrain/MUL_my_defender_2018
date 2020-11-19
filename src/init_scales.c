/*
** EPITECH PROJECT, 2019
** init_scales
** File description:
** init_scales
*/

#include "defender.h"

void init_scales5(graph *s)
{
    sfVector2f info = {0.5, 0.5};

    sfSprite_setScale(s->menus[13]->sp, info);
}

void init_scales4(graph *s)
{
    sfVector2f buttons = {1.7, 1.7};
    sfFloatRect bounds;

    for (int i = 2; i < 11 && s->menus[i]->sp; i += 7) {
        sfSprite_setScale(s->menus[i]->sp, buttons);
        bounds = sfSprite_getGlobalBounds(s->menus[i]->sp);
        s->menus[i]->pos.x = (WIDTH / 2) - (bounds.width / 2);
        s->menus[i]->pos.y = HEIGHT - (i * 50) - 200;
        sfSprite_setPosition(s->menus[i]->sp, s->menus[i]->pos);
    }
    sfSprite_setScale(s->menus[10]->sp, buttons);
    bounds = sfSprite_getGlobalBounds(s->menus[10]->sp);
    s->menus[10]->pos.x = (WIDTH / 2) - (bounds.width / 2);
    s->menus[10]->pos.y = HEIGHT - (5.5 * 50) - 200;
    sfSprite_setPosition(s->menus[10]->sp, s->menus[10]->pos);
}

void init_scales3(graph *s)
{
    sfVector2f buttons = {1.7, 1.7};
    sfFloatRect bounds;

    for (int i = 7; i < 9 && s->menus[i]->sp; i++) {
        sfSprite_setScale(s->menus[i]->sp, buttons);
        bounds = sfSprite_getGlobalBounds(s->menus[i]->sp);
        s->menus[i]->pos.x = 400 + (i - 7) * 600;
        s->menus[i]->pos.y = 45 + 2 * 400;
        sfSprite_setPosition(s->menus[i]->sp, s->menus[i]->pos);
    }
}

void init_scales2(graph *s)
{
    sfVector2f buttons = {1.7, 1.7};
    sfFloatRect bounds;

    for (int i = 3; i < 7 && s->menus[i]->sp; i++) {
        sfSprite_setScale(s->menus[i]->sp, buttons);
        bounds = sfSprite_getGlobalBounds(s->menus[i]->sp);
        s->menus[i]->pos.x = 45 + 2 * 860;
        s->menus[i]->pos.y = 200 + (i - 2) * 150;
        sfSprite_setPosition(s->menus[i]->sp, s->menus[i]->pos);
    }
    init_scales3(s);
}

void init_scales1(graph *s)
{
    sfVector2f buttons = {1.7, 1.7};
    sfFloatRect bounds;

    for (int i = 0; i < 3 && s->menus[i]->sp; i++) {
        sfSprite_setScale(s->menus[i]->sp, buttons);
        bounds = sfSprite_getGlobalBounds(s->menus[i]->sp);
        s->menus[i]->pos.x = 250;
        s->menus[i]->pos.y = 250 + i * 200;
        sfSprite_setPosition(s->menus[i]->sp, s->menus[i]->pos);
    }
    s->map[1]->pos.x = WIDTH - 287;
    s->map[1]->pos.y = 0;
    sfSprite_setPosition(s->map[1]->sp, s->map[1]->pos);
    init_scales2(s);
}
