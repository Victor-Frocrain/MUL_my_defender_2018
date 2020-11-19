/*
** EPITECH PROJECT, 2019
** init_text
** File description:
** defender
*/

#include "defender.h"

void draw_coin(graph *s)
{
    sfText_setPosition(s->text[3]->text, s->text[3]->pos);
    sfText_setString(s->text[3]->text, convert_int_str(s->coin));
}

void time_draw_coin(graph *s)
{
    int i = 3;
    
    if (sfTime_asSeconds
    (sfClock_getElapsedTime(s->clock->coin)) >= 2 &&
    s->scene->pause == false && s->coin < 200) {
        sfClock_restart(s->clock->coin);
        draw_coin(s);
        manage_prize(s, i);
        s->coin = s->coin + 10;
    }
    sfRenderWindow_drawText(s->window, s->text[3]->text, NULL);
}

void draw_score(graph *s)
{
    sfText_setPosition(s->text[2]->text, s->text[2]->pos);
    sfText_setString(s->text[2]->text, convert_int_str(s->score));
    sfRenderWindow_drawText(s->window, s->text[2]->text, NULL);
}

void init_text(graph *s)
{
    for (int i = 0; i < TEXT; i++) {
        s->text[i] = malloc(sizeof(strings));
        s->text[i]->text = sfText_create();
        s->text[i]->font = sfFont_createFromFile("font/PRViking.ttf");
        s->text[i]->pos.x = 15;
        s->text[i]->pos.y = 10;
        s->text[i]->str = malloc(sizeof(char) * 417);
        sfText_setFont(s->text[i]->text, s->text[i]->font);
        sfText_setPosition(s->text[i]->text, s->text[i]->pos);
        sfText_setCharacterSize(s->text[i]->text, 50);
    }
    s->text[3]->pos.x = 15;
    s->text[3]->pos.y = HEIGHT - 210;
}
