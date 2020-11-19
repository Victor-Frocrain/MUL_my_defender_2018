/*
** EPITECH PROJECT, 2019
** draw_elems
** File description:
** draw_elems
*/

#include "defender.h"

void draw_elem3(graph *s)
{
    if (s->scene->pause)
        draw_pause(s);
    else {
        for (int i = 3; i < 7 && s->menus[i]; i++) {
            sfSprite_setTextureRect(s->menus[i]->sp, s->menus[i]->rect);
            sfRenderWindow_drawSprite(s->window, s->menus[i]->sp, NULL);
        }
    }
}

void draw_elem2(graph *s)
{
    draw_coin(s);
    draw_score(s);
    if (s->life <= 0) {
        s->scene->game = false;
        s->scene->end = true;
        read_best(s);
        s->text[2]->pos.x = 650;
        s->text[2]->pos.y = 330;
        sfText_setCharacterSize(s->text[2]->text, 100);
        sfText_setPosition(s->text[2]->text, s->text[2]->pos);
        sfMusic_stop(s->musica->fight);
    }
    draw_elem3(s);
}

void draw_elem(graph *s)
{
    check_if_pause(s);
    display_land(s);
    if (s->scene->pause == false)
        anim_enemies(s);
    display_in_order(s);
    sfRenderWindow_drawSprite(s->window, s->map[1]->sp, NULL);
    display_life(s);
    display_tower_life(s);
    display_player_life(s);
    sfRenderWindow_drawSprite(s->window, s->back[2]->sp, NULL);
    manage_mouse(s);
    time_draw_coin(s);
    draw_elem2(s);
}
