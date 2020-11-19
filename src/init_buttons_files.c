/*
** EPITECH PROJECT, 2019
** init_buttons_files
** File description:
** init_buttons_files
*/

#include "defender.h"

void init_buttons_files2(graph *s)
{
    s->menus[11]->file = my_strcpy(s->menus[11]->file,
    "pictures/menus/life.png");
    s->menus[12]->file = my_strcpy(s->menus[12]->file,
    "pictures/menus/retry.png");
    s->menus[13]->file = my_strcpy(s->menus[13]->file,
    "pictures/menus/board.png");
}

void init_buttons_files1(graph *s)
{
    s->menus[0]->file = my_strcpy(s->menus[0]->file, "pictures/menus/play.png");
    s->menus[1]->file = my_strcpy(s->menus[1]->file, "pictures/menus/how.png");
    s->menus[2]->file = my_strcpy(s->menus[2]->file, "pictures/menus/quit.png");
    s->menus[3]->file = my_strcpy(s->menus[3]->file,
    "pictures/menus/tower1.png");
    s->menus[4]->file = my_strcpy(s->menus[4]->file,
    "pictures/menus/tower2.png");
    s->menus[5]->file = my_strcpy(s->menus[5]->file,
    "pictures/menus/tower3.png");
    s->menus[6]->file = my_strcpy(s->menus[6]->file,
    "pictures/menus/tower4.png");
    s->menus[7]->file = my_strcpy(s->menus[7]->file,
    "pictures/menus/back.png");
    s->menus[8]->file = my_strcpy(s->menus[8]->file,
    "pictures/menus/next.png");
    s->menus[9]->file = my_strcpy(s->menus[9]->file,
    "pictures/menus/resume.png");
    s->menus[10]->file = my_strcpy(s->menus[10]->file,
    "pictures/menus/menu.png");
    init_buttons_files2(s);
}
