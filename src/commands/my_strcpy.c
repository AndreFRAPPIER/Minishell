/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mama
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    dest = malloc(sizeof(char) * (my_strlen(src) + 2));
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
