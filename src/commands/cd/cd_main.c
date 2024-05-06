/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mama
*/

#include "my.h"

void builtin_cd(char **command, env_t *env)
{
    int len = len_tab(command);

    if (len > 2) {
        my_puterror("cd: Too many arguments.\n");
        return;
    }
    if (len == 1 || (len == 2 && command[1][0] == '~')) {
        cd_home(env);
    } else if (len == 2 && command[1][0] == '-') {
        cd_last_directory(env);
    } else {
        change_directory(env, command[1]);
    }
}
