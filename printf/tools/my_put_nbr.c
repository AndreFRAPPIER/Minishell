/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** Put number
*/

#include <stdio.h>
#include "../include/tools.h"

int my_put_nbr(long nb, char *char_base)
{
    int len = 0;
    int base = my_strlen(char_base);

    if (nb < 0) {
        my_putchar('-');
        return (1 + my_put_nbr(nb * -1, char_base));
    } else if (nb < base) {
        return (my_putchar(char_base[nb]));
    } else {
        len = my_put_nbr(nb / base, char_base);
        return (len + my_put_nbr(nb % base, char_base));
    }
}
