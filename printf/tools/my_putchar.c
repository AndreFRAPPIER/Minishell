/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include <unistd.h>
#include "../include/tools.h"

int my_putchar(char c)
{
    return write(STDOUT_FILENO, &c, 1);
}
