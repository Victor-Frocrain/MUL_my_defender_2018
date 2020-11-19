/*
** EPITECH PROJECT, 2019
** defender
** File description:
** pause
*/

#include "defender.h"

void draw_pause(graph *s)
{
    init_scales4(s);
    sfRenderWindow_drawSprite(s->window, s->back[1]->sp, NULL);
    for (int i = 2; i < 10 && s->menus[i]; i += 7) {
        sfSprite_setTextureRect(s->menus[i]->sp, s->menus[i]->rect);
        sfRenderWindow_drawSprite(s->window, s->menus[i]->sp, NULL);
    }
    sfSprite_setTextureRect(s->menus[10]->sp, s->menus[10]->rect);
    sfRenderWindow_drawSprite(s->window, s->menus[10]->sp, NULL);
}

void check_escape_button(graph *s)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        s->escape = true;
    else
        s->escape = false;
}

void check_if_pause(graph *s)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && s->escape == false &&
        s->scene->pause == false)
        s->scene->pause = true;
    else if (sfKeyboard_isKeyPressed(sfKeyEscape) && s->escape == false &&
        s->scene->pause)
        s->scene->pause = false;
    check_escape_button(s);
}
