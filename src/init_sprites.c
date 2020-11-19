/*
** EPITECH PROJECT, 2019
** init_sprites
** File description:
** init_sprites
*/

#include "defender.h"

void init_sprites(graph *s)
{
    for (int i = 0; i < NB_MAP; i++) {
        s->map[i]->sp = sfSprite_create();
        sfSprite_setTexture(s->map[i]->sp, s->map[i]->tex, sfFalse);
    }
    for (int i = 0; i < MENUS; i++) {
        s->menus[i]->sp = sfSprite_create();
        sfSprite_setTexture(s->menus[i]->sp, s->menus[i]->tex, sfFalse);
    }
    for (int i = 0; i < BACK; i++) {
        s->back[i]->sp = sfSprite_create();
        sfSprite_setTexture(s->back[i]->sp, s->back[i]->tex, sfFalse);
    }
    for (int i = 0; i < CHARA; i++) {
        s->characters[i]->sp = sfSprite_create();
        sfSprite_setTexture(s->characters[i]->sp,
        s->characters[i]->tex, sfFalse);
    }
    init_sprites_obstacles(s);
    init_scales1(s);
}

void destroy_sprites(graph *s)
{
    for (int i = NB_MAP - 1; i >= 0 && s->map[i]->sp; i--)
        sfSprite_destroy(s->map[i]->sp);
    for (int i = MENUS - 1; i >= 0 && s->menus[i]->sp; i--)
        sfSprite_destroy(s->menus[i]->sp);
    for (int i = BACK - 1; i >= 0 && s->back[i]->sp; i--)
        sfSprite_destroy(s->back[i]->sp);
    for (int i = CHARA - 1; i >= 0 && s->characters[i]->sp; i--)
        sfSprite_destroy(s->characters[i]->sp);
    destroy_sprites_obstacles(s);
}
