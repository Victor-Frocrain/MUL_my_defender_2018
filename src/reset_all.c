/*
** EPITECH PROJECT, 2019
** reset
** File description:
** defender
*/

#include "defender.h"

void reset_all2(graph *s)
{
    s->text[2]->pos.x = 15;
    s->text[2]->pos.y = 10;
    sfText_setCharacterSize(s->text[2]->text, 50);
    s->coin = 0;
}

void reset_all(graph *s)
{
    int j = 0;
    sfVector2u size;

    for (int i = 0; i < CHARA; i++) {
        size = sfTexture_getSize(s->characters[i]->tex);
        s->characters[i]->pop = false;
        s->characters[i]->pos.x = -((float)(size.x)) / 10;
        s->characters[i]->life = MAX_LIFE;
        s->characters[i]->damage = DAMAGE;
    }
    for (int i = 0; i < OBS && j < UNIT;) {
        s->obs[i][j]->pop = false;
        s->obs[i][j]->life = TOWER_LIFE;
        j++;
        if (j >= UNIT) {
            j = 0;
            i++;
        }
    }
    reset_all2(s);
}

