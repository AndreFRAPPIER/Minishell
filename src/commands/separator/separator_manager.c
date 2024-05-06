/*
** EPITECH PROJECT, 2024
** mam
** File description:
** mama
*/

#include "my.h"

int get_number_separator(char **command)
{
    int nb_sep = 0;

    for (int i = 0; command[i] != NULL; i++) {
        if (my_strcmp(command[i], ";") == 0 || my_strcmp(command[i], "|") == 0)
            nb_sep++;
    }
    return nb_sep;
}

int manage_separators(char **command, int nb_separators, env_t *env)
{
    char **extracted_command = NULL;

    for (int i = 0; i <= nb_separators; i++) {
        extracted_command = get_command(command, i);
        command_launcher(extracted_command, env);
        free_my_str_to_word_array(extracted_command);
    }
    return 0;
}
