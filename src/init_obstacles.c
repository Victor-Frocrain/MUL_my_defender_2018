/*
** EPITECH PROJECT, 2019
** init_obstacles
** File description:
** init_obstacles
*/

#include "defender.h"

void link_files_id(graph *s, int i, int j)
{
    if (i == 0)
        s->obs[i][j]->file = my_strcpy(s->obs[i][j]->file,
        "pictures/map/tower1.png");
    if (i == 1)
        s->obs[i][j]->file = my_strcpy(s->obs[i][j]->file,
        "pictures/map/tower2.png");
    if (i == 2)
        s->obs[i][j]->file = my_strcpy(s->obs[i][j]->file,
        "pictures/map/tower3.png");
    if (i == 3)
        s->obs[i][j]->file = my_strcpy(s->obs[i][j]->file,
        "pictures/map/tower4.png");
}

void init_files_obstacles(graph *s)
{
    int j = 0;

    for (int i = 0; i < OBS;) {
        link_files_id(s, i, j);
        j++;
        if (j >= UNIT) {
            i++;
            j = 0;
        }
    }
}

void init_textures_obstacles(graph *s)
{
    int j = 0;

    for (int i = 0; i < OBS;) {
        s->obs[i][j]->tex = sfTexture_createFromFile
        (s->obs[i][j]->file, NULL);
        j++;
        if (j >= UNIT) {
            i++;
            j = 0;
        }
    }
}

void init_sprites_obstacles(graph *s)
{
    int j = 0;

    for (int i = 0; i < OBS;) {
        s->obs[i][j]->sp = sfSprite_create();
        sfSprite_setTexture(s->obs[i][j]->sp, s->obs[i][j]->tex, sfFalse);
        j++;
        if (j >= UNIT) {
            i++;
            j = 0;
        }
    }
}
