/*
** EPITECH PROJECT, 2019
** button end file
** File description:
** defender
*/

#include "defender.h"

void check_click2(graph *s)
{
    s->scene->end = false;
    s->scene->main = true;
    s->tower = OBS;
    init_scales1(s);
    s->score = 0;
    reset_all(s);
    s->life = PLAYER_LIFE;
    sfMusic_stop(s->musica->fight);
    sfMusic_play(s->musica->game);
}

void check_click_end(int scene, graph *s)
{
    if (s->clicked == false) {
        if (scene == 12) {
            s->scene->end = false;
            s->scene->game = true;
            s->clicked = true;
            s->life = PLAYER_LIFE;
            s->tower = OBS;
            s->score = 0;
            sfMusic_play(s->musica->fight);
            init_scales1(s);
            reset_all(s);
        }
        if (scene == 10)
            check_click2(s);
        if (scene == 2)
            s->exit = true;
    }
}
