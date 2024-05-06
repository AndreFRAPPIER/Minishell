/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mama
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int val = 0;

    if (my_strlen(s1) < my_strlen(s2))
        return -1;
    if (my_strlen(s1) > my_strlen(s2))
        return 1;
    while (s1[i] && s2[i]) {
        val = (s1[i] - s2[i]);
        if (val != 0)
            return val;
        i++;
    }
    return 0;
}
