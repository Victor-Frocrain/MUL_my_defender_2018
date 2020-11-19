/*
** EPITECH PROJECT, 2019
** manage_mouse
** File description:
** manage_mouse
*/

#include "defender.h"

void check_mouse_button(graph *s)
{
    if (sfMouse_isButtonPressed(sfMouseLeft))
        s->clicked = true;
    else
        s->clicked = false;
}

void mouse_buttons(sfVector2i mouse, graph *s)
{
    sfFloatRect bounds;

    for (int i = 0; i < 13 && s->menus[i]; i++) {
        bounds = sfSprite_getGlobalBounds(s->menus[i]->sp);
        if (mouse.x >= s->menus[i]->pos.x &&
        mouse.x <= s->menus[i]->pos.x + bounds.width &&
        mouse.y >= s->menus[i]->pos.y &&
        mouse.y <= s->menus[i]->pos.y + bounds.height) {
            position_info_buttons(s, i);
            s->menus[i]->rect.top = 0;
            check_click(i, s);
        }
        else
            s->menus[i]->rect.top = sfTexture_getSize(s->menus[i]->tex).y / 3;
        sfSprite_setTextureRect(s->menus[i]->sp, s->menus[i]->rect);
    }
    check_mouse_button(s);
}

void manage_mouse(graph *s)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(s->window);

    mouse_buttons(mouse, s);
}
