/*
** EPITECH PROJECT, 2019
** destroy_obstacles
** File description:
** destroy_obstacles
*/

#include "defender.h"

void destroy_sprites_obstacles(graph *s)
{
    int j = UNIT - 1;

    for (int i = OBS - 1; i >= 0 && s->obs[i] && s->obs[i][j];) {
        sfSprite_destroy(s->obs[i][j]->sp);
        j--;
        if (j < 0) {
            i--;
            j = UNIT - 1;
        }
    }
}

void destroy_textures_obstacles(graph *s)
{
    int j = UNIT - 1;

    for (int i = OBS - 1; i >= 0 && s->obs[i] && s->obs[i][j];) {
        sfTexture_destroy(s->obs[i][j]->tex);
        j--;
        if (j < 0) {
            i--;
            j = UNIT - 1;
        }
    }
}

void destroy_files_obstacles(graph *s)
{
    int j = UNIT - 1;

    for (int i = OBS - 1; i >= 0 && s->obs[i] && s->obs[i][j];) {
        free(s->obs[i][j]->file);
        j--;
        if (j < 0) {
            i--;
            j = UNIT - 1;
        }
    }
}
