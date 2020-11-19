/*
** EPITECH PROJECT, 2019
** defender
** File description:
** prize manager 
*/

#include "defender.h"

bool manage_prize2(graph *s, int i, bool unity)
{
    if (i == 1 && s->coin >= 100 && unity) {
        s->coin -= 100;
        return (true);
    }
    if (i == 2 && s->coin >= 150 && unity) {
        s->coin -= 150;
        return (true);
    }
    if (i == 3 && s->coin >= 200 && unity) {
        s->coin -= 200;
        return (true);
    }
    return (false);
}

bool manage_prize(graph *s, int i)
{
    bool unity = false;

    for (int j = 0; i < OBS && j < UNIT; j++)
        if (s->obs[i][j]->pop == false) {
            unity = true;
            break;
        }
    if (i == 0 && s->coin >= 50 && unity) {
        s->coin -= 50;
        return (true);
    }
    return (manage_prize2(s, i, unity));
}
