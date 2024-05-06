/*
** EPITECH PROJECT, 2024
** mama*
** File description:
** mama
*/

#include "my.h"

void free_command(char **str, env_t *env)
{
    free_my_str_to_word_array(str);
    free_my_str_to_word_array(env->env);
}
