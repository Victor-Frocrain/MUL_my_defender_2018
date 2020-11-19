/*
** EPITECH PROJECT, 2019
** init_player_life
** File description:
** init_player_life
*/

#include "defender.h"

void init_player_life(graph *s)
{
    sfFloatRect bounds;

    for (int i = 3; i < 5; i++) {
        bounds = sfSprite_getGlobalBounds(s->back[i]->sp);
        s->back[i]->pos.x = WIDTH / 2 - bounds.width / 2;
        s->back[i]->pos.y = HEIGHT - 320;
        sfSprite_setPosition(s->back[i]->sp, s->back[i]->pos);
    }
    bounds = sfSprite_getGlobalBounds(s->back[5]->sp);
    s->back[5]->pos.x = WIDTH / 2 - bounds.width / 2;
    s->back[5]->pos.y = HEIGHT - 330;
    sfSprite_setPosition(s->back[5]->sp, s->back[5]->pos);
}
