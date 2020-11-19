/*
** EPITECH PROJECT, 2019
** towers_attack
** File description:
** towers_attack
*/

#include "../include/defender.h"

void towers_damages(graph *s, int i, int j, bool fight)
{
    sfFloatRect bounds_obs = sfSprite_getGlobalBounds(s->obs[i][j]->sp);
    sfFloatRect bounds_ene;

    for (int ene = 0; ene < CHARA; ene++) {
        bounds_ene = sfSprite_getGlobalBounds(s->characters[ene]->sp);
        if (fight && s->obs[i][j]->pop && s->obs[i][j]->attack &&
        s->characters[ene]->life > 0 &&
        s->characters[ene]->pos.x + bounds_ene.width >
        s->obs[i][j]->pos.x - 60 && s->characters[ene]->pos.x <
        s->obs[i][j]->pos.x + bounds_obs.width + 100 &&
        s->characters[ene]->pos.y + bounds_ene.height >
        s->obs[i][j]->pos.y - 50 && s->characters[ene]->pos.y + 50 <
        s->obs[i][j]->pos.y + bounds_obs.height) {
            s->characters[ene]->life -= s->obs[i][j]->damage;
        }
    }
}

void towers_fight(graph *s, int i, int j)
{
    bool fight = false;

    if (sfTime_asMilliseconds
    (sfClock_getElapsedTime(s->obs[i][j]->fight)) >= 1000 &&
    s->scene->pause == false) {
        fight = true;
        sfClock_restart(s->obs[i][j]->fight);
    }
    towers_damages(s, i, j, fight);
}

bool check_if_fight(graph *s, int i, int j, int ene)
{
    sfFloatRect bounds_obs = sfSprite_getGlobalBounds(s->obs[i][j]->sp);
    sfFloatRect bounds_ene = sfSprite_getGlobalBounds(s->characters[ene]->sp);

    if (s->scene->pause == false &&
    s->characters[ene]->pos.x + bounds_ene.width >
    s->obs[i][j]->pos.x - 60 && s->characters[ene]->pos.x <
    s->obs[i][j]->pos.x + bounds_obs.width + 100 &&
    s->characters[ene]->pos.y + bounds_ene.height >
    s->obs[i][j]->pos.y - 50 && s->characters[ene]->pos.y + 50 <
    s->obs[i][j]->pos.y + bounds_obs.height) {
        choose_anim_tower(s, i, j);
        s->obs[i][j]->attack = true;
        return (true);
    }
    return (false);
}

void detect_if_enemies(graph *s, int i, int j)
{
    bool fight = false;

    for (int ene = 0; ene < CHARA && fight == false; ene++)
        fight = check_if_fight(s, i, j, ene);
    if (fight == false && s->scene->pause == false) {
        s->obs[i][j]->rect.top = 0;
        s->obs[i][j]->rect.left = 0;
    }
    sfSprite_setTextureRect(s->obs[i][j]->sp, s->obs[i][j]->rect);
}

void towers_attack(graph *s)
{
    int i = 0;
    bool fight = false;

    if (sfTime_asMilliseconds
    (sfClock_getElapsedTime(s->clock->tower)) >= 150) {
        fight = true;
        sfClock_restart(s->clock->tower);
    }
    for (int j = 0; i < OBS && j < UNIT;) {
        if (s->obs[i][j]->pop && fight)
            detect_if_enemies(s, i, j);
        towers_fight(s, i, j);
        if (s->scene->pause == false)
            enemies_attack(s, i, j);
        j++;
        if (j >= UNIT) {
            j = 0;
            i++;
        }
    }
}
