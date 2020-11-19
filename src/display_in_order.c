/*
** EPITECH PROJECT, 2019
** display_in_order.c
** File description:
** display_in_order
*/

#include "defender.h"

void disp_towers_order(graph *s, int y)
{
    int i = 0;

    for (int j = 0; i < OBS && j < UNIT;) {
        if (s->obs[i][j]->pos.y == y && s->obs[i][j]->pop)
            sfRenderWindow_drawSprite(s->window, s->obs[i][j]->sp, NULL);
        j++;
        if (j >= UNIT) {
            j = 0;
            i++;
        }
    }
    for (int j = 0; j < CHARA; j++) {
        if (s->characters[j]->pos.y == y && s->characters[j]->pop == false) {
            sfRenderWindow_drawSprite(s->window, s->characters[j]->sp, NULL);
            s->characters[j]->pop = true;
        }
    }
}

void detect_height(graph *s, obstacle *obs, int j, int y)
{
    sfFloatRect bounds_obs;
    sfFloatRect bounds_ene;

    if (obs->pop && s->characters[j]->pos.y == y) {
        bounds_obs = sfSprite_getGlobalBounds(obs->sp);
        bounds_ene = sfSprite_getGlobalBounds(s->characters[j]->sp);
        if (s->characters[j]->pos.y + bounds_ene.height <
        obs->pos.y + bounds_obs.height &&
        s->characters[j]->pos.x + bounds_ene.width >= obs->pos.x &&
        s->characters[j]->pos.x <= obs->pos.x + bounds_obs.width &&
        s->characters[j]->pop == false) {
            sfRenderWindow_drawSprite(s->window, s->characters[j]->sp, NULL);
            s->characters[j]->pop = true;
        }
    }
}

void disp_enemies_order(graph *s, int y)
{
    int i = 0;

    for (int k = 0; i < OBS && k < UNIT;) {
        for (int j = 0; j < CHARA; j++)
            detect_height(s, s->obs[i][k], j, y);
        k++;
        if (k >= UNIT) {
            k = 0;
            i++;
        }
    }
}

void display_in_order(graph *s)
{
    for (int y = 0; y < HEIGHT; y++)
        disp_enemies_order(s, y);
    for (int y = 0; y < HEIGHT; y++)
        disp_towers_order(s, y);
    for (int j = 0; j < CHARA; j++)
        s->characters[j]->pop = false;
}
