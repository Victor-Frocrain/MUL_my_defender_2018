/*
** EPITECH PROJECT, 2019
** defender
** File description:
** display score board
*/

#include "defender.h"

char *write_new_best(graph *s, char *buff)
{
    int fd = open("score", O_RDWR | O_CREAT);
    char *score = convert_int_str(s->score);

    if (fd < 0)
        return (NULL);
    write(fd, score, my_strlen(score));
    my_putstr(score);
    buff = my_strcpy(buff, s->text[2]->str);
    close(fd);
    return (score);
}

void read_best(graph *s)
{
    char *buff;
    int fd = open("score", O_RDWR | O_CREAT);
    int red = 0;

    if (fd < 0)
        return;
    buff = malloc(sizeof(char) * 10);
    if (buff == NULL) {
        close(fd);
        return;
    }
    red = read(fd, buff, 9);
    close(fd);
    buff[red] = 0;
    if (my_getnbr(buff) < s->score)
        buff = write_new_best(s, buff);
    sfText_setString(s->text[8]->text, buff);
    s->text[8]->pos.x = 110;
    s->text[8]->pos.y = 320;
    sfText_setCharacterSize(s->text[8]->text, 100);
    sfText_setPosition(s->text[8]->text, s->text[8]->pos);
}

void display_score(graph *s)
{
    sfRenderWindow_drawText(s->window, s->text[2]->text, NULL);
    sfRenderWindow_drawText(s->window, s->text[8]->text, NULL);
}
