/*
** EPITECH PROJECT, 2019
** anim_towers
** File description:
** anim_towers
*/

#include "defender.h"

void anim_tower1(graph *s, int i, int j)
{
    sfVector2u size = sfTexture_getSize(s->obs[i][j]->tex);

    if (s->obs[i][j]->rect.left >= (float)(size.x / 5) &&
    s->obs[i][j]->rect.top >= (float)size.y / 2) {
        s->obs[i][j]->rect.top = 0;
        s->obs[i][j]->rect.left = 0;
    }
    else if (s->obs[i][j]->rect.left < (float)(size.x - size.x / 5))
        s->obs[i][j]->rect.left += size.x / 5;
    else if (s->obs[i][j]->rect.left >= (float)(size.x - size.x / 5)) {
        s->obs[i][j]->rect.top += size.y / 2;
        s->obs[i][j]->rect.left = 0;
    }
}

void anim_tower2(graph *s, int i, int j)
{
    sfVector2u size = sfTexture_getSize(s->obs[i][j]->tex);

    if (s->obs[i][j]->rect.left < (float)(size.x - size.x / 5))
        s->obs[i][j]->rect.left += size.x / 5;
    else if (s->obs[i][j]->rect.left >= (float)(size.x - size.x / 5) &&
    s->obs[i][j]->rect.top < (float)size.y / 2) {
        s->obs[i][j]->rect.top += size.y / 2;
        s->obs[i][j]->rect.left = 0;
    }
    else if (s->obs[i][j]->rect.left >= (float)(size.x - size.x / 5) &&
    s->obs[i][j]->rect.top >= (float)size.y / 2) {
        s->obs[i][j]->rect.top = 0;
        s->obs[i][j]->rect.left = 0;
    }
}

void anim_last_towers(graph *s, int i, int j)
{
    sfVector2u size = sfTexture_getSize(s->obs[i][j]->tex);

    if (s->obs[i][j]->rect.left >= (float)(size.x / 5) &&
    s->obs[i][j]->rect.top >= (float)size.y / 3) {
        s->obs[i][j]->rect.top = 0;
        s->obs[i][j]->rect.left = 0;
    }
    else if (s->obs[i][j]->rect.left < (float)(size.x - size.x / 5))
        s->obs[i][j]->rect.left += size.x / 5;
    else if (s->obs[i][j]->rect.left >= (float)(size.x - size.x / 5)) {
        s->obs[i][j]->rect.top += size.y / 3;
        s->obs[i][j]->rect.left = 0;
    }
}

void choose_anim_tower(graph *s, int i, int j)
{
    if (i == 0)
        anim_tower1(s, i, j);
    else if (i == 1)
        anim_tower2(s, i, j);
    else if (i == 2 || i == 3)
        anim_last_towers(s, i, j);
}
