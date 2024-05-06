/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mama
*/

#include "my.h"
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

static void print_error_chdir(int error_status, char *path)
{
    if (error_status == ENOTDIR) {
        my_puterror(path);
        my_puterror(": Not a directory.\n");
    }
    if (error_status == ENOENT) {
        my_puterror(path);
        my_puterror(": No such file or directory.\n");
    }
    if (error_status == EACCES) {
        my_puterror(path);
        my_puterror(": Permission denied.\n");
    }
}

static char **change_env_sec(env_t *env, int pwd_rank, char *path)
{
    char **new_env = malloc(sizeof(char *) * (len_tab(env->env) + 2));
    char *pwd = get_value_var_env(env->env[pwd_rank]);
    int i = 0;

    for (; env->env[i]; i++) {
        if (i == pwd_rank) {
            new_env[i] = change_env_line_with_path("PWD", path);
        } else
            new_env[i] = my_strcpy(new_env[i], env->env[i]);
    }
    new_env[i] = my_concat_param_triple("OLDPWD", "=", pwd);
    i++;
    new_env[i] = NULL;
    free(pwd);
    return new_env;
}

static char **change_env(env_t *env, int pwd_rank, int oldpwd_rank, char *path)
{
    char **new_env = malloc(sizeof(char *) * (len_tab(env->env) + 2));
    char *pwd = my_strcpy(pwd, env->env[pwd_rank]);
    int i = 0;

    for (; env->env[i]; i++) {
        if (i == pwd_rank)
            new_env[i] = change_env_line_with_path("PWD", path);
        if (i == oldpwd_rank)
            new_env[i] = change_env_line("OLDPWD", pwd);
        if (i != pwd_rank && i != oldpwd_rank)
            new_env[i] = my_strcpy(new_env[i], env->env[i]);
    }
    new_env[i] = NULL;
    free(pwd);
    return new_env;
}

static char **return_new_environment(int oldpwd_rank,
    int pwd_rank, char *new_pwd, env_t *env)
{
    char **environment = NULL;

    if (oldpwd_rank == -1)
        environment = change_env_sec(env, pwd_rank, new_pwd);
    else
        environment = change_env(env, pwd_rank, oldpwd_rank, new_pwd);
    return environment;
}

void change_directory(env_t *env, char *path)
{
    char *new_pwd = NULL;
    int pwd_rank = find_rank("PWD", env->env);
    int oldpwd_rank = find_rank("OLDPWD", env->env);
    char **environment = NULL;

    if (chdir(path) == -1) {
        print_error_chdir(errno, path);
        return;
    }
    new_pwd = getcwd(new_pwd, 0);
    if (new_pwd == NULL) {
        return;
    }
    environment = return_new_environment(oldpwd_rank, pwd_rank, new_pwd, env);
    free(new_pwd);
    free_my_str_to_word_array(env->env);
    env->env = copy_env(environment);
    free_my_str_to_word_array(environment);
}
