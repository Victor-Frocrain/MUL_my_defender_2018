/*
** EPITECH PROJECT, 2019
** info
** File description:
** defender
*/

#include "defender.h"

void draw_text_info(graph *s, int i)
{
    for (i = 4; i < TEXT && s->text[i]->text; i++)
        sfRenderWindow_drawText(s->window, s->text[i]->text, NULL);
}

void draw_text1(graph *s)
{
    sfFloatRect bounds;
    bounds = sfSprite_getGlobalBounds(s->menus[13]->sp);

    s->text[4]->pos.x = (WIDTH - 400) - (bounds.width / 2) + 5;
    s->text[4]->pos.y = HEIGHT - 700;
    sfText_setPosition(s->text[4]->text, s->text[4]->pos);
    sfText_setCharacterSize(s->text[4]->text, 35);
    sfText_setColor(s->text[4]->text, sfRed);
    sfText_setString(s->text[4]->text, TEXT1);
    sfRenderWindow_drawText(s->window, s->text[4]->text, NULL);
}

void draw_text2(graph *s)
{
    sfFloatRect bounds;
    bounds = sfSprite_getGlobalBounds(s->menus[13]->sp);

    s->text[5]->pos.x = (WIDTH - 400) - (bounds.width / 2) + 5;
    s->text[5]->pos.y = HEIGHT - 600;
    sfText_setPosition(s->text[5]->text, s->text[5]->pos);
    sfText_setCharacterSize(s->text[5]->text, 35);
    sfText_setColor(s->text[5]->text, sfRed);
    sfText_setString(s->text[5]->text, TEXT2);
    sfRenderWindow_drawText(s->window, s->text[5]->text, NULL);
}

void draw_text3(graph *s)
{
    sfFloatRect bounds;
    bounds = sfSprite_getGlobalBounds(s->menus[13]->sp);

    s->text[6]->pos.x = (WIDTH - 400) - (bounds.width / 2) + 5;
    s->text[6]->pos.y = HEIGHT - 500;
    sfText_setPosition(s->text[6]->text, s->text[6]->pos);
    sfText_setCharacterSize(s->text[6]->text, 35);
    sfText_setColor(s->text[6]->text, sfRed);
    sfText_setString(s->text[6]->text, TEXT3);
    sfRenderWindow_drawText(s->window, s->text[6]->text, NULL);
}

void draw_text4(graph *s)
{
    sfFloatRect bounds;
    bounds = sfSprite_getGlobalBounds(s->menus[13]->sp);

    s->text[7]->pos.x = (WIDTH - 400) - (bounds.width / 2) + 5;
    s->text[7]->pos.y = HEIGHT - 400;
    sfText_setPosition(s->text[7]->text, s->text[7]->pos);
    sfText_setCharacterSize(s->text[7]->text, 35);
    sfText_setColor(s->text[7]->text, sfRed);
    sfText_setString(s->text[7]->text, TEXT4);
    sfRenderWindow_drawText(s->window, s->text[7]->text, NULL);
}
