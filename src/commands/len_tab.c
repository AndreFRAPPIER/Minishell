/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mama
*/

#include "my.h"

int len_tab(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return -1;
    while (tab[i] != NULL)
        i++;
    return i;
}
