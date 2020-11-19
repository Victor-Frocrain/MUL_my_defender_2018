/*
** EPITECH PROJECT, 2019
** music file
** File description:
** defender
*/

#include "defender.h"

void init_music(graph *s)
{
    s->musica = malloc(sizeof(music));
    s->musica->game = sfMusic_createFromFile("sound/main.ogg");
    s->musica->fight = sfMusic_createFromFile("sound/battle.ogg");
    s->musica->clic = sfMusic_createFromFile("sound/clic.ogg");
    sfMusic_play(s->musica->game);
    sfMusic_setLoop(s->musica->fight, true);
}
