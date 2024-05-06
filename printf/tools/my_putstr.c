/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "../include/tools.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    return write(STDOUT_FILENO, str, my_strlen(str));
}
