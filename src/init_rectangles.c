/*
** EPITECH PROJECT, 2019
** init_rectangles
** File description:
** init_rectangles
*/

#include "defender.h"

void init_rectangles_obstacles(graph *s)
{
    int nb = 2;
    sfVector2u size;

    for (int i = 0; i < OBS && s->obs[i]; i++) {
        if (i >= 2)
            nb = 3;
        for (int j = 0; j < UNIT && s->obs[i][j]; j++) {
            size = sfTexture_getSize(s->obs[i][j]->tex);
            s->obs[i][j]->rect.left = 0;
            s->obs[i][j]->rect.width = size.x / 5;
            s->obs[i][j]->rect.height = size.y / nb;
            s->obs[i][j]->rect.top = 0;
        }
    }
}

void init_rectangles(graph *s)
{
    sfVector2u size;

    for (int i = 0; i < 13; i++) {
        size = sfTexture_getSize(s->menus[i]->tex);
        s->menus[i]->rect.left = 0;
        s->menus[i]->rect.width = size.x;
        s->menus[i]->rect.height = size.y / 3;
        s->menus[i]->rect.top = size.y / 3;
    }
    for (int i = 0; i < CHARA; i++) {
        size = sfTexture_getSize(s->characters[i]->tex);
        s->characters[i]->rect.left = (rand() % 10) * (size.x / 10);
        s->characters[i]->rect.width = size.x / 10;
        s->characters[i]->rect.height = size.y / 2;
        s->characters[i]->rect.top = size.y / 2;
        s->characters[i]->pos.x = -((float)(size.x)) / 10;
    }
}
