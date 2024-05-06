/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mama
*/

#include "my.h"
#include <string.h>

static int nb_word(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n') &&
        (str[i + 1] == ' ' || str[i + 1] == '\t'
        || str[i + 1] == '\n' || str[i + 1] == '\0'))
            count++;
    }
    count--;
    return count;
}

static int len_word(char *str, int i)
{
    int n = 0;

    while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i]) {
        n++;
        i++;
    }
    return n;
}

char **my_str_to_word_array(char *s)
{
    char **tab = malloc(sizeof(char *) * (nb_word(s) + 2));
    int i = 0;
    int j = 0;
    int k = 0;

    while (s[i] && s[i] != '\n') {
        for (; s[i] == ' ' || s[i] == '\t' || s[i] == '\n'; i++);
        if (s[i] == '\0' || s[i] == '\n')
            break;
        tab[k] = malloc(sizeof(char) * (my_strlen(s) + 1));
        for (; s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i]; i++) {
            tab[k][j] = s[i];
            j++;
        }
        tab[k][j] = '\0';
        k++;
        j = 0;
    }
    tab[k] = NULL;
    return tab;
}

void free_my_str_to_word_array(char **arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; arr[i]; i++) {
        free(arr[i]);
    }
    free(arr);
}
