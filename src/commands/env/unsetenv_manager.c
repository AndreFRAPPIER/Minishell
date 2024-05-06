/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mama
*/

#include "my.h"

static void change_env_unsetenv(env_t *env, char *name)
{
    char **new_env = malloc(sizeof(char *) * (len_tab(env->env) + 2));
    int i = 0;
    int j = 0;
    int rank_to_delete = find_rank(name, env->env);

    if (rank_to_delete == -1)
        return;
    while (env->env[i]) {
        if (i == rank_to_delete) {
            i++;
        } else {
            new_env[j] = my_strcpy(new_env[j], env->env[i]);
            i++;
            j++;
        }
    }
    new_env[j] = NULL;
    free_my_str_to_word_array(env->env);
    env->env = copy_env(new_env);
    free_my_str_to_word_array(new_env);
}

void unsetenv_manager(char **command, env_t *env)
{
    int len = len_tab(command);

    if (len < 2) {
        my_puterror("unsetenv: Too few arguments.\n");
        return;
    } else {
        for (int i = 1; command[i]; i++) {
            change_env_unsetenv(env, command[i]);
        }
    }
}
