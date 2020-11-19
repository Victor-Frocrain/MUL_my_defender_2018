/*
** EPITECH PROJECT, 2019
** check_click
** File description:
** check_click
*/

#include "defender.h"

void check_click_synopsis(int scene, graph *s)
{
    if (s->clicked == false) {
        if (scene == 8) {
            s->scene->synopsis = false;
            s->scene->game = true;
            s->clicked = true;
            sfMusic_play(s->musica->fight);
        }
    }
}

void check_click_pause(int scene, graph *s)
{
    if (s->clicked == false) {
        if (scene == 9)
            s->scene->pause = false;
        if (scene == 10) {
            s->scene->pause = false;
            s->scene->game = false;
            s->scene->main = true;
            s->tower = OBS;
            init_scales1(s);
            s->score = 0;
            reset_all(s);
            s->life = PLAYER_LIFE;
            sfMusic_stop(s->musica->fight);
            sfMusic_play(s->musica->game);
        }
        if (scene == 2) {
            sfMusic_stop(s->musica->fight);
            s->exit = true;
        }
    }
}

void check_click_how(int scene, graph *s)
{
    if (s->clicked == false) {
        if (scene == 7) {
            s->scene->howtoplay = false;
            s->scene->main = true;
        }
        if (scene == 8) {
            s->scene->howtoplay = false;
            s->clicked = true;
            s->scene->synopsis = true;
            sfMusic_stop(s->musica->game);
        }
    }
}

void check_click_main(int scene, graph *s)
{
    if (s->clicked == false) {
        if (scene == 0) {
            s->scene->main = false;
            s->scene->synopsis = true;
            sfMusic_stop(s->musica->game);
        }
        if (scene == 1) {
            s->scene->main = false;
            s->scene->howtoplay = true;
        }
        if (scene == 2) {
            sfMusic_stop(s->musica->game);
            s->exit = true;
        }
    }
}

void check_click(int scene, graph *s)
{
    sfVector2u size;

    size = sfTexture_getSize(s->menus[scene]->tex);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (s->clicked == false)
            sfMusic_play(s->musica->clic);
        if (s->scene->main)
            check_click_main(scene, s);
        if (s->scene->howtoplay)
            check_click_how(scene, s);
        if (s->scene->synopsis)
            check_click_synopsis(scene, s);
        if (s->scene->pause)
            check_click_pause(scene, s);
        if (s->scene->game)
            check_click_tower(scene, s);
        if (s->scene->end)
            check_click_end(scene, s);
        s->menus[scene]->rect.top = size.y / 3 * 2;
    }
}
