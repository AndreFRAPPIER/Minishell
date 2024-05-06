/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "../include/tools.h"

int my_put_dtab(char **str)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        count = count + my_putstr(str[i]);
        count = count + my_putchar('\n');
    }
    return count;
}
