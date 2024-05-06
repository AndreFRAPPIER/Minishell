/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "my.h"

int main(int argc, char **argv, char **environment)
{
    env_t env = init_env(environment);

    return my_sh(&env);
}
