/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mama
*/

#include "my.h"

static char **extract_second_command(char **source)
{
    char **command = malloc(sizeof(char *) * (len_tab(source) + 2));
    int i = 0;
    int j = 0;

    for (; source[i] != NULL; i++)
        if (my_strcmp(source[i], ";") == 0)
            break;
    i++;
    for (; source[i] != NULL; i++) {
        command[j] = my_strcpy(command[j], source[i]);
        j++;
    }
    command[j] = NULL;
    return command;
}

char **get_command(char **source, int nb_sep_to_ignore)
{
    char **command = malloc(sizeof(char *) * (len_tab(source) + 2));
    int i = 0;
    int j = 0;

    for (int nb_sep_encounter = 0; nb_sep_encounter < nb_sep_to_ignore; i++) {
        if (my_strcmp(source[i], ";") == 0 ||
            my_strcmp(source[i], "|") == 0) {
            nb_sep_encounter++;
        }
    }
    for (; source[i] != NULL; i++) {
        if (my_strcmp(source[i], ";") == 0 ||
            my_strcmp(source[i], "|") == 0)
            break;
        command[j] = my_strcpy(command[j], source[i]);
        j++;
    }
    command[j] = NULL;
    return command;
}
