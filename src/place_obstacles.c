/*
** EPITECH PROJECT, 2019
** place_obstacles
** File description:
** place_obstacles
*/

#include "defender.h"

void display_obstacles(graph *s, sfVector2i mouse, int i)
{
    bool place = manage_prize(s, i);

    for (int j = 0; j < UNIT && s->obs[i] && s->obs[i][j];) {
        if (s->obs[i][j]->pop == false && place == true) {
            s->obs[i][j]->pos.x = mouse.x;
            s->obs[i][j]->pos.y = mouse.y;
            sfSprite_setPosition(s->obs[i][j]->sp, s->obs[i][j]->pos);
            sfSprite_setTextureRect(s->obs[i][j]->sp, s->obs[i][j]->rect);
            s->obs[i][j]->pop = true;
            break;
        }
        else
            j++;
    }
}

void check_click_tower(int scene, graph *s)
{
    if (s->clicked == false) {
        if (scene == 3)
            s->tower = 0;
        if (scene == 4)
            s->tower = 1;
        if (scene == 5)
            s->tower = 2;
        if (scene == 6)
            s->tower = 3;
    }
}

void place_obstacles(graph *s)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(s->window);

    if (sfMouse_isButtonPressed(sfMouseLeft) && s->clicked == false &&
        mouse.x >= 0 && mouse.x < WIDTH - 287 &&
        mouse.y >= 0 && mouse.y < HEIGHT && s->tower < OBS)
        display_obstacles(s, mouse, s->tower);
}
