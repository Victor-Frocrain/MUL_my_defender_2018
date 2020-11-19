/*
** EPITECH PROJECT, 2019
** init
** File description:
** init
*/

#include "defender.h"

void init_values(graph *s)
{
    s->map[0]->rect.left = 0;
    s->map[0]->rect.width = 60;
    s->map[0]->rect.height = 60;
    s->map[0]->rect.top = 60;
    s->life = PLAYER_LIFE;
    s->tower = OBS;
    s->scene->end = false;
    s->scene->main = true;
    s->scene->game = false;
    s->scene->howtoplay = false;
    s->exit = false;
    s->scene->pause = false;
    s->escape = false;
    s->scene->synopsis = false;
}

graph *init_graph(graph *s)
{
    s = malloc(sizeof(graph));
    if (s == NULL)
        return (NULL);
    if (init_tabs(s) == false)
        return (NULL);
    s->clock = malloc(sizeof(times));
    s->scene = malloc(sizeof(sequence));
    if (s->clock) {
        s->clock->game = sfClock_create();
        s->clock->enemies = sfClock_create();
        s->clock->tower = sfClock_create();
        s->clock->howtoplay = sfClock_create();
        s->clock->coin = sfClock_create();
    }
    init_values(s);
    return (s);
}

bool init_window(graph *s)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    if (s == NULL)
        return (false);
    s->window = sfRenderWindow_create
    (mode, "VIKING INTRUSION", sfResize | sfClose, NULL);
    if (!s->window)
        return (false);
    sfRenderWindow_setVerticalSyncEnabled(s->window, sfTrue);
    sfRenderWindow_setFramerateLimit(s->window, 60);
    return (true);
}
