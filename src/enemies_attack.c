/*
** EPITECH PROJECT, 2019
** enemies_attack
** File description:
** enemies_attack
*/

#include "defender.h"

void enemies_player(graph *s, int ene)
{
    bool fight = false;

    if (s->characters[ene]->attack && sfTime_asMilliseconds
    (sfClock_getElapsedTime(s->characters[ene]->fight)) >= 1000 &&
    s->characters[ene]->attack) {
        fight = true;
        sfClock_restart(s->characters[ene]->fight);
    }
    if (fight && s->life >= s->characters[ene]->damage)
        s->life -= s->characters[ene]->damage;
    else if (fight && s->life < s->characters[ene]->damage)
        s->life = 0;
}

void enemies_damages(graph *s, int i, int j, int ene)
{
    bool fight = false;

    if (s->characters[ene]->attack && sfTime_asMilliseconds
    (sfClock_getElapsedTime(s->characters[ene]->fight)) >= 1000 &&
    s->characters[ene]->attack) {
        fight = true;
        sfClock_restart(s->characters[ene]->fight);
    }
    if (fight && s->obs[i][j]->life >= s->characters[ene]->damage &&
        s->obs[i][j]->pop)
        s->obs[i][j]->life -= s->characters[ene]->damage;
    else if (fight && s->obs[i][j]->life < s->characters[ene]->damage &&
    s->obs[i][j]->pop) {
        s->obs[i][j]->pop = false;
        s->obs[i][j]->attack = false;
        s->obs[i][j]->life = TOWER_LIFE;
    }
    if (!s->obs[i][j]->pop)
        s->characters[ene]->attack = false;
}

void enemies_attack(graph *s, int i, int j)
{
    sfFloatRect bounds_obs;
    sfFloatRect bounds_ene;

    for (int ene = 0; ene < CHARA; ene++) {
        bounds_obs = sfSprite_getGlobalBounds(s->obs[i][j]->sp);
        bounds_ene = sfSprite_getGlobalBounds(s->characters[ene]->sp);
        if ((s->characters[ene]->pos.x +
        bounds_ene.width <= s->obs[i][j]->pos.x && s->characters[ene]->pos.x
        + bounds_ene.width + SPEED >= s->obs[i][j]->pos.x &&
        s->characters[ene]->pos.y >= s->obs[i][j]->pos.y &&
        s->characters[ene]->pos.y + bounds_ene.height <=
        s->obs[i][j]->pos.y + bounds_obs.height)) {
            s->characters[ene]->attack = true;
            enemies_damages(s, i, j, ene);
        }
        if (s->characters[ene]->pos.x + bounds_ene.width >= WIDTH - 287) {
            s->characters[ene]->attack = true;
            enemies_player(s, ene);
        }
    }
}
