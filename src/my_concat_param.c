/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mama
*/

#include "my.h"

char *my_concat_param(char *a, char *b)
{
    char *str = malloc(sizeof(char) * ((my_strlen(a) + my_strlen(b)) + 1));
    int i = 0;
    int j = 0;

    while (a[i]) {
        str[j] = a[i];
        j++;
        i++;
    }
    i = 0;
    while (b[i]) {
        str[j] = b[i];
        i++;
        j++;
    }
    str[j] = '\0';
    return str;
}

char *my_concat_param_triple(char *a, char *b, char *c)
{
    char *temp = NULL;
    char *new = NULL;

    if (a == NULL || b == NULL || c == NULL) {
        return NULL;
    }
    temp = my_concat_param(a, b);
    new = my_concat_param(temp, c);
    free(temp);
    return new;
}
