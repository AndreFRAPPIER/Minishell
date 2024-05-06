/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mama
*/

#include "my.h"
#include <errno.h>
#include <unistd.h>
#include <string.h>

char *get_value_var_env(char *str)
{
    char *path = malloc(sizeof(char) * (my_strlen(str) + 2));
    int i = 0;
    int j = 0;

    while (str[i] != '=')
        i++;
    i++;
    while (str[i]) {
        path[j] = str[i];
        j++;
        i++;
    }
    path[j] = '\0';
    return path;
}

char *change_env_line(char *key_word, char *src)
{
    char *dest = malloc(sizeof(char) *
    (my_strlen(key_word) + my_strlen(src) + 2));
    int i = 0;
    int j = 0;

    for (; key_word[i]; i++)
        dest[i] = key_word[i];
    dest[i] = '=';
    i++;
    while (src[j] != '=')
        j++;
    j++;
    for (; src[j]; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *change_env_line_with_path(char *key_word, char *src)
{
    char *dest = malloc(sizeof(char) *
    (my_strlen(key_word) + my_strlen(src) + 2));
    int i = 0;
    int j = 0;

    for (; key_word[i]; i++)
        dest[i] = key_word[i];
    dest[i] = '=';
    i++;
    for (; src[j]; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char **copy_env(char **env)
{
    char **new = malloc(sizeof(char *) * (len_tab(env) * 2));
    int i = 0;

    for (int j; env[i]; i++) {
        new[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 2));
        for (j = 0; env[i][j]; j++) {
            new[i][j] = env[i][j];
        }
        new[i][j] = '\0';
    }
    new[i] = NULL;
    return new;
}

static void make_new_env(env_t *env)
{
    char **new_env = malloc(sizeof(char *) * 2);
    char new_pwd[32000];

    if (getcwd(new_pwd, 32000) == NULL) {
        strerror(errno);
        return;
    }
    new_env[0] = NULL;
    env->env = new_env;
}

env_t init_env(char **save_env)
{
    env_t env;

    if (save_env[0] == NULL) {
        make_new_env(&env);
    } else
        env.env = copy_env(save_env);
    return env;
}
