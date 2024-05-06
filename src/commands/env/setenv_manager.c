/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mama
*/

#include "my.h"

static void change_env_setenv(env_t *env, char *name, char *value)
{
    char **new_env = malloc(sizeof(char *) * (len_tab(env->env) + 2));
    char *new_line = NULL;
    int i = 0;

    if (value == NULL) {
        new_line = my_concat_param(name, "=");
    } else {
        new_line = my_concat_param_triple(name, "=", value);
    }
    for (; env->env[i]; i++) {
        new_env[i] = my_strcpy(new_env[i], env->env[i]);
    }
    new_env[i] = my_strcpy(new_env[i], new_line);
    i++;
    new_env[i] = NULL;
    free_my_str_to_word_array(env->env);
    env->env = new_env;
    free(new_line);
}

static void modify_env(env_t *env, char *name, char *value, int rank)
{
    char **new_env = malloc(sizeof(char *) * len_tab(env->env) + 2);
    char *new_line = NULL;
    int i = 0;

    if (value == NULL) {
        new_line = my_concat_param(name, "=");
    } else {
        new_line = my_concat_param_triple(name, "=", value);
    }
    for (; env->env[i]; i++) {
        if (i != rank)
            new_env[i] = my_strcpy(new_env[i], env->env[i]);
        else
            new_env[i] = my_strcpy(new_env[i], new_line);
    }
    new_env[i] = NULL;
    free_my_str_to_word_array(env->env);
    env->env = new_env;
}

static void check_env_line_exist(env_t *env, char *name, char *value)
{
    int rank = find_rank(name, env->env);

    if (rank == -1) {
        change_env_setenv(env, name, value);
    } else {
        modify_env(env, name, value, rank);
    }
}

void setenv_manager(char **command, env_t *env)
{
    int len = len_tab(command);

    if (len == 1) {
        my_printf("%S", env->env);
        return;
    }
    if (len > 3) {
        my_puterror("setenv: Too many arguments.\n");
        return;
    }
    if (len == 2) {
        check_env_line_exist(env, command[1], NULL);
        return;
    }
    if (len == 3) {
        check_env_line_exist(env, command[1], command[2]);
    }
}
