/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mama
*/

#include "my.h"

static int is_builtin_function(char *str)
{
    if (my_strcmp(str, "env") == 0 ||
        my_strcmp(str, "setenv") == 0 ||
        my_strcmp(str, "unsetenv") == 0 ||
        my_strcmp(str, "cd") == 0) {
            return 0;
    }
    return -1;
}

int command_launcher(char **command, env_t *env)
{
    if (is_builtin_function(command[0]) == 0) {
        launch_builtin_function(command, env);
    } else {
        launch_native_function(command, env);
    }
    return 0;
}

int command_manager(char **command, env_t *env)
{
    int nb_separators = get_number_separator(command);

    if (nb_separators == 0)
        return command_launcher(command, env);
    if (nb_separators > 0) {
        return manage_separators(command, nb_separators, env);
    }
    return 84;
}
