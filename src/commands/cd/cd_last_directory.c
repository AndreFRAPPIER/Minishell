/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mama
*/

#include "my.h"
#include <unistd.h>
#include <string.h>
#include <errno.h>

static char **change_pwd_cd_last_dir(env_t *env, int pwd_rank, int oldpwd_rank)
{
    char **new_env = malloc(sizeof(char *) * (len_tab(env->env) + 2));
    char *pwd = my_strcpy(pwd, env->env[pwd_rank]);
    char *oldpwd = my_strcpy(oldpwd, env->env[oldpwd_rank]);
    int i = 0;

    for (; env->env[i] != NULL; i++) {
        if (i == pwd_rank)
            new_env[i] = change_env_line("PWD", oldpwd);
        if (i == oldpwd_rank)
            new_env[i] = change_env_line("OLDPWD", pwd);
        if (i != pwd_rank && i != oldpwd_rank)
            new_env[i] = my_strcpy(new_env[i], env->env[i]);
    }
    new_env[i] = NULL;
    free(oldpwd);
    free(pwd);
    return new_env;
}

void cd_last_directory(env_t *env)
{
    char **new_env = NULL;
    int pwd_rank = find_rank("PWD", env->env);
    int oldpwd_rank = find_rank("OLDPWD", env->env);
    char *oldpwd = NULL;

    if (oldpwd_rank == -1) {
        my_puterror("cd: « OLDPWD » not define.\n");
    } else {
        oldpwd = get_value_var_env(env->env[oldpwd_rank]);
        if (chdir(oldpwd) != 0) {
            strerror(errno);
            free(oldpwd);
            return;
        }
        free(oldpwd);
        new_env = change_pwd_cd_last_dir(env, pwd_rank, oldpwd_rank);
        free_my_str_to_word_array(env->env);
        env->env = copy_env(new_env);
        free_my_str_to_word_array(new_env);
    }
}
