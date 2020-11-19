/*
** EPITECH PROJECT, 2019
** init_textures
** File description:
** init_textures
*/

#include "defender.h"

void init_files(graph *s)
{
    s->map[0]->file = my_strcpy(s->map[0]->file, "pictures/map/land.png");
    s->map[1]->file = my_strcpy(s->map[1]->file, "pictures/map/wall.png");
    init_buttons_files1(s);
    s->back[0]->file = my_strcpy(s->back[0]->file, "pictures/menus/main.png");
    s->back[1]->file = my_strcpy(s->back[1]->file, "pictures/menus/pause.png");
    s->back[2]->file = my_strcpy(s->back[2]->file, "pictures/menus/hud.png");
    s->back[3]->file = my_strcpy(s->back[3]->file,
    "pictures/menus/empty_life.png");
    s->back[4]->file = my_strcpy(s->back[4]->file,
    "pictures/menus/fill_life.png");
    s->back[5]->file = my_strcpy(s->back[5]->file,
    "pictures/menus/base_life.png");
    s->back[6]->file = my_strcpy(s->back[6]->file,
    "pictures/menus/score.jpg");
    for (int i = 0; i < CHARA; i++) {
        s->characters[i]->file = my_strcpy(s->characters[i]->file,
        "pictures/characters/viking.png");
    }
    init_files_obstacles(s);
}

void init_textures(graph *s)
{
    init_files(s);
    for (int i = 0; i < NB_MAP; i++)
        s->map[i]->tex = sfTexture_createFromFile(s->map[i]->file, NULL);
    for (int i = 0; i < MENUS; i++)
        s->menus[i]->tex = sfTexture_createFromFile(s->menus[i]->file, NULL);
    for (int i = 0; i < BACK; i++)
        s->back[i]->tex = sfTexture_createFromFile(s->back[i]->file, NULL);
    for (int i = 0; i < CHARA; i++)
        s->characters[i]->tex = sfTexture_createFromFile
        (s->characters[i]->file, NULL);
    init_textures_obstacles(s);
    init_rectangles(s);
    init_rectangles_obstacles(s);
}

void destroy_files(graph *s)
{
    for (int i = NB_MAP - 1; i >= 0 && s->map[i]->file; i--)
        free(s->map[i]->file);
    for (int i = MENUS - 1; i >= 0 && s->menus[i]->file; i--)
        free(s->menus[i]->file);
    for (int i = BACK - 1; i >= 0 && s->back[i]->file; i--)
        free(s->back[i]->file);
    for (int i = CHARA - 1; i >= 0 && s->characters[i]->file; i--)
        free(s->characters[i]->file);
    destroy_files_obstacles(s);
}

void destroy_textures(graph *s)
{
    destroy_files(s);
    for (int i = NB_MAP - 1; i >= 0 && s->map[i]->tex; i--)
        sfTexture_destroy(s->map[i]->tex);
    for (int i = MENUS - 1; i >= 0 && s->menus[i]->tex; i--)
        sfTexture_destroy(s->menus[i]->tex);
    for (int i = BACK - 1; i >= 0 && s->back[i]->tex; i--)
        sfTexture_destroy(s->back[i]->tex);
    for (int i = CHARA - 1; i >= 0 && s->characters[i]->tex; i--)
        sfTexture_destroy(s->characters[i]->tex);
    destroy_textures_obstacles(s);
}
