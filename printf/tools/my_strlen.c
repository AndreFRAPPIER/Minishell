/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "../include/tools.h"
#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL) {
        return -1;
    }
    while (str[i])
        i++;
    return i;
}
