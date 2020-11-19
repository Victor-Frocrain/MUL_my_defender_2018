/*
** EPITECH PROJECT, 2019
** display_life
** File description:
** display_life
*/

#include "defender.h"

void display_player_life(graph *s)
{
    sfIntRect size = {0, 0, 210, 210};
    sfVector2f pos = s->back[4]->pos;

    size.height = ((float)(s->life)) / PLAYER_LIFE * 210;
    size.top = 210 - size.height;
    pos.y += size.top;
    sfSprite_setTextureRect(s->back[4]->sp, size);
    sfSprite_setPosition(s->back[4]->sp, pos);
    for (int i = 3; i < 6; i++)
        sfRenderWindow_drawSprite(s->window, s->back[i]->sp, NULL);
}

void display_life(graph *s)
{
    sfIntRect size = {0, 0, 0, 7};

    for (int i = 0; i < CHARA; i++) {
        size.width = ((float)(s->characters[i]->life)) / MAX_LIFE * 110;
        s->menus[11]->pos.x = s->characters[i]->pos.x;
        s->menus[11]->pos.y = s->characters[i]->pos.y;
        sfSprite_setTextureRect(s->menus[11]->sp, size);
        sfSprite_setPosition(s->menus[11]->sp, s->menus[11]->pos);
        sfRenderWindow_drawSprite(s->window, s->menus[11]->sp, NULL);
    }
}

void display_tower_life(graph *s)
{
    sfIntRect size = {0, 0, 0, 7};
    int j = 0;

    for (int i = 0; i < OBS && j < UNIT;) {
        if (s->obs[i][j]->pop) {
            size.width = ((float)(s->obs[i][j]->life)) / TOWER_LIFE * 110;
            s->menus[11]->pos.x = s->obs[i][j]->pos.x;
            s->menus[11]->pos.y = s->obs[i][j]->pos.y;
            sfSprite_setTextureRect(s->menus[11]->sp, size);
            sfSprite_setPosition(s->menus[11]->sp, s->menus[11]->pos);
            sfRenderWindow_drawSprite(s->window, s->menus[11]->sp, NULL);
        }
        j++;
        if (j >= UNIT) {
            j = 0;
            i++;
        }
    }
}
