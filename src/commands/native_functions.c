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
#include <signal.h>

static char *get_command_name(char **command, char *path)
{
    char *command_name = NULL;

    if (path != NULL)
        command_name = my_concat_param_triple(path, "/", command[0]);
    else
        command_name = my_strcpy(command_name, command[0]);
    return command_name;
}

static void execute_execve(char *command_name, char **command, char **env)
{
    if (command_name == NULL || command == NULL)
        exit(84);
    if (execve(command_name, command, env) == -1)
        strerror(errno);
    exit(84);
}

static int exec_bin(char **command, char *path, env_t *env)
{
    char *command_name = get_command_name(command, path);
    pid_t child_pid = fork();
    int status = 0;

    if (child_pid == -1)
        return 0;
    if (child_pid == 0)
        execute_execve(command_name, command, env->env);
    else {
        waitpid(child_pid, &status, 0);
        if (status == 0) {
            free(command_name);
            return CMD_EXEC_SUCCESS;
        }
        free(command_name);
        return status;
    }
    return 84;
}

static int test_path(char **command, env_t *env, int path_rank)
{
    char *token = NULL;
    int exit_status = 0;
    char *line_path = get_value_var_env(env->env[path_rank]);

    token = strtok(line_path, ":");
    while (token != NULL) {
        exit_status = exec_bin(command, token, env);
        if (exit_status != CMD_NOT_FOUND)
            break;
        token = strtok(NULL, ":");
    }
    free(line_path);
    return exit_status;
}

static void print_error_message_execve(char **command, int exit_status,
    int path_rank)
{
    if (exit_status == CMD_SEGFAULT)
        my_puterror("Segmentation fault (core dumped)\n");
    if (exit_status == CMD_NOT_FOUND) {
        if (path_rank == -1)
            my_puterror("TERM environment variable not set.\n");
        else {
            my_puterror(command[0]);
            my_puterror(": Command not found.\n");
        }
    }
}

void launch_native_function(char **command, env_t *env)
{
    int path_rank = find_rank("PATH", env->env);
    int exit_status = 0;

    if (command[0] == NULL)
        return;
    if (path_rank != -1)
        exit_status = test_path(command, env, path_rank);
    else
        exit_status = exec_bin(command, "/bin", env);
    if (exit_status == CMD_NOT_FOUND)
        exit_status = exec_bin(command, ".", env);
    if (exit_status != CMD_EXEC_SUCCESS) {
        print_error_message_execve(command, exit_status, path_rank);
    }
}
