/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mama
*/

#include "my.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

static int exit_eof(char **buffer, env_t *env)
{
    write(1, "\n", 1);
    free(*buffer);
    free_my_str_to_word_array(env->env);
    return 0;
}

static void print_prompt(env_t *env)
{
    int rank = find_rank("PWD", env->env);
    int i = 0;

    if (rank == -1) {
        my_putstr("[prompt] => ");
    } else {
        my_putstr("[prompt => ");
        while (env->env[rank][i] != '=') {
            i++;
        }
        i += 2;
        for (; env->env[rank][i]; i++) {
            my_putchar(env->env[rank][i]);
        }
    }
    my_putstr("]$> ");
}

int my_sh(env_t *env)
{
    size_t size = 0;
    char *buffer = NULL;
    char **command = NULL;

    while (1) {
        print_prompt(env);
        if (getline(&buffer, &size, stdin) == EOF)
            return exit_eof(&buffer, env);
        command = my_str_to_word_array(buffer);
        if (my_strcmp(command[0], "exit") == 0)
            break;
        command_manager(command, env);
        free_my_str_to_word_array(command);
    }
    free(buffer);
    free_command(command, env);
    return 0;
}
