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

static char **up_cd_home(env_t *env, int pwd_rank,
    int oldpwd_rank, int home_rank)
{
    char **new_env = malloc(sizeof(char *) * (len_tab(env->env) + 2));
    char *pwd = my_strcpy(pwd, env->env[pwd_rank]);
    int status = 0;
    int i = 0;

    for (; env->env[i]; i++) {
        if (i == pwd_rank) {
            new_env[i] = change_env_line("PWD", env->env[home_rank]);
        }
        if (i == oldpwd_rank) {
            new_env[i] = change_env_line("OLDPWD", pwd);
        }
        if (i != pwd_rank && i != oldpwd_rank)
            new_env[i] = my_strcpy(new_env[i], env->env[i]);
    }
    new_env[i] = NULL;
    free(pwd);
    return new_env;
}

static char **up_cd_home_oldpwd(env_t *env, int pwd_rank, int home_rank)
{
    char **new_env = malloc(sizeof(char *) * (len_tab(env->env) + 3));
    char *pwd = my_strcpy(pwd, env->env[pwd_rank]);
    int i = 0;

    for (; env->env[i]; i++) {
        if (i == pwd_rank)
            new_env[i] = change_env_line("PWD", env->env[home_rank]);
        else
            new_env[i] = my_strcpy(new_env[i], env->env[i]);
        }
    new_env[i] = change_env_line("OLDPWD", pwd);
    i++;
    new_env[i] = NULL;
    free(pwd);
    return new_env;
}

void cd_home(env_t *env)
{
    int pwd_rank = find_rank("PWD", env->env);
    int oldpwd_rank = find_rank("OLDPWD", env->env);
    int home_rank = find_rank("HOME", env->env);
    char *path = get_value_var_env(env->env[home_rank]);
    char **environment = NULL;

    if (oldpwd_rank == -1)
        environment = up_cd_home_oldpwd(env, pwd_rank, home_rank);
    else
        environment = up_cd_home(env, pwd_rank, oldpwd_rank, home_rank);
    if (chdir(path) != 0) {
        strerror(errno);
        free(path);
        return;
    }
    free(path);
    free_my_str_to_word_array(env->env);
    env->env = environment;
}
