/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mama
*/

#include "my.h"

void launch_builtin_function(char **command, env_t *env)
{
    if (my_strcmp(command[0], "env") == 0) {
        my_printf("%S", env->env);
    }
    if (my_strcmp(command[0], "cd") == 0) {
        builtin_cd(command, env);
    }
    if (my_strcmp(command[0], "setenv") == 0) {
        setenv_manager(command, env);
    }
    if (my_strcmp(command[0], "unsetenv") == 0) {
        unsetenv_manager(command, env);
    }
}
