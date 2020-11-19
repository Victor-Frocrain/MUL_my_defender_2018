/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my_defender
*/

#include "defender.h"

void disp_help(graph *s)
{
    s->scene->howtoplay = true;
    s->scene->main = false;
}

void game_actions(graph *s)
{
    sfRenderWindow_clear(s->window, sfBlack);
    if (s->scene->main)
        draw_main(s);
    if (s->scene->howtoplay)
        how_to_play(s);
    if (s->scene->synopsis)
        synopsis(s);
    if (s->scene->game) {
        towers_attack(s);
        draw_elem(s);
    }
    if (s->scene->end)
        manage_end(s);
    sfRenderWindow_display(s->window);
}

void check_close(graph *s, sfEvent event)
{
    while (sfRenderWindow_pollEvent(s->window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(s->window);
}

int my_defender(int ac, char **av)
{
    sfEvent event;
    graph *s = init_graph(s);

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        disp_help(s);
    if (s == NULL || init_window(s) == false)
        return (MY_EXIT_ERROR);
    init_textures(s);
    init_sprites(s);
    init_text(s);
    init_music(s);
    init_player_life(s);
    while (sfRenderWindow_isOpen(s->window) && s->exit == false) {
        check_close(s, event);
        game_actions(s);
    }
    destroy_ressources(s);
    return (MY_EXIT_SUCCESS);
}
