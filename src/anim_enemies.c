/*
** EPITECH PROJECT, 2019
** anim_enemies
** File description:
** anim_enemies
*/

#include "defender.h"

void enemies_pop(graph *s, sfVector2u size)
{
    srand(sfTime_asMicroseconds
    (sfClock_getElapsedTime(s->clock->game)));
    for (int i = 0; i < CHARA && s->characters[i]; i++) {
        if (s->characters[i]->pos.x == -((float)(size.x)) / 10)
            s->characters[i]->pos.y = rand() % (HEIGHT - 250);
    }
}

void move_enemies(graph *s, sfVector2u size, int i)
{
    enemies_pop(s, size);
    if (s->characters[i]->attack == false)
        s->characters[i]->pos.x += SPEED;
    if (s->characters[i]->life <= 0) {
        s->characters[i]->pos.x = -((float)(size.x)) / 10;
        s->characters[i]->life = MAX_LIFE;
        s->characters[i]->attack = false;
        s->characters[i]->damage *= 1.1;
        s->score++;
    }
    if (s->characters[i]->attack && s->characters[i]->rect.left ==
        size.x - 5 * size.x / 10)
        sfMusic_play(s->characters[i]->clink);
    if (s->characters[i]->rect.left < size.x - 2 * size.x / 10)
        s->characters[i]->rect.left += size.x / 10;
    else
        s->characters[i]->rect.left = 0;
    sfSprite_setPosition(s->characters[i]->sp, s->characters[i]->pos);
}

void anim_enemies(graph *s)
{
    sfVector2u size;
    bool move;

    if (sfTime_asMilliseconds
    (sfClock_getElapsedTime(s->clock->enemies)) >= 100) {
        move = true;
        sfClock_restart(s->clock->enemies);
    }
    place_obstacles(s);
    for (int i = 0; i < CHARA && s->scene->game; i++) {
        size = sfTexture_getSize(s->characters[i]->tex);
        if (s->characters[i]->attack)
            s->characters[i]->rect.top = 0;
        else
            s->characters[i]->rect.top = size.y / 2;
        sfSprite_setTextureRect(s->characters[i]->sp,
        s->characters[i]->rect);
        if (move || s->characters[i]->life <= 0)
            move_enemies(s, size, i);
    }
}
