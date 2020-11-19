/*
** EPITECH PROJECT, 2019
** init_tabs
** File description:
** init_tabs
*/

#include "defender.h"

bool init_tabs3(graph *s)
{
    int j = 0;

    for (int i = 0; i < OBS && j < UNIT;) {
        s->obs[i][j] = malloc(sizeof(obstacle));
        if (s->obs[i][j] == NULL)
            return (false);
        s->obs[i][j]->fight = sfClock_create();
        s->obs[i][j]->life = TOWER_LIFE;
        s->obs[i][j]->damage = 5 * (i + 1);
        s->obs[i][j]->pop = false;
        j++;
        if (j >= UNIT) {
            j = 0;
            i++;
        }
    }
    return (true);
}

bool init_tabs2(graph *s)
{
    for (int i = 0; i < CHARA; i++) {
        s->characters[i] = malloc(sizeof(obstacle));
        if (s->characters[i] == NULL)
            return (false);
        s->characters[i]->life = MAX_LIFE;
        s->characters[i]->damage = DAMAGE;
        s->characters[i]->clink = sfMusic_createFromFile("sound/hache.ogg");
        s->characters[i]->fight = sfClock_create();
        s->characters[i]->attack = false;
    }
    return (init_tabs3(s));
}

bool init_tabs(graph *s)
{
    for (int i = 0; i < NB_MAP; i++) {
        s->map[i] = malloc(sizeof(entity));
        if (s->map[i] == NULL)
            return (false);
    }
    for (int i = 0; i < MENUS; i++) {
        s->menus[i] = malloc(sizeof(entity));
        if (s->menus[i] == NULL)
            return (false);
    }
    for (int i = 0; i < BACK; i++) {
        s->back[i] = malloc(sizeof(entity));
        if (s->back[i] == NULL)
            return (false);
    }
    return (init_tabs2(s));
}
