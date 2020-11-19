/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** copy str
*/

#include "my.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src && src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}
