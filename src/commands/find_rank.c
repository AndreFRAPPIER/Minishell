/*
** EPITECH PROJECT, 2024
** mama
** File description:
** mama
*/

#include "my.h"

static int check_in_line(char *name, char *line)
{
    int i = 0;

    if (my_strlen(name) > my_strlen(line))
        return -1;
    for (; name[i]; i++) {
        if (name[i] != line[i])
            return -1;
    }
    if (line[i] != '=')
        return -1;
    return 0;
}

int find_rank(char *name, char **env)
{
    int i = 0;

    while (env[i]) {
        if (check_in_line(name, env[i]) == 0)
            return i;
        i++;
    }
    return -1;
}
