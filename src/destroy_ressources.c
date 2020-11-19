/*
** EPITECH PROJECT, 2019
** destroy_ressources
** File description:
** destroy_ressources
*/

#include "defender.h"

void destroy_clocks(graph *s)
{
    if (s->clock && s->clock->game)
        sfClock_destroy(s->clock->game);
    if (s->clock)
        free(s->clock);
}

void destroy_music(graph *s)
{
    for (int i = 0; i < CHARA; i++)
        sfMusic_destroy(s->characters[i]->clink);
    if (s->musica && s->musica->game)
        sfMusic_destroy(s->musica->game);
    if (s->musica && s->musica->fight)
        sfMusic_destroy(s->musica->fight);
    if (s->musica && s->musica->clic)
        sfMusic_destroy(s->musica->clic);
    if (s->musica)
        free(s->musica);
}

void destroy_ressources(graph *s)
{
    destroy_sprites(s);
    destroy_textures(s);
    if (s->land)
        free(s->land);
    for (int i = NB_MAP - 1; i >= 0 && s->map[i]; i--)
        free(s->map[i]);
    for (int i = MENUS - 1; i >= 0 && s->map[i]; i--)
        free(s->menus[i]);
    destroy_clocks(s);
    destroy_music(s);
    sfRenderWindow_destroy(s->window);
    if (s)
        free(s);
}
