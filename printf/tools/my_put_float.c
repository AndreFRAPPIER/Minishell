/*
** EPITECH PROJECT, 2023
** my_putflopat
** File description:
** mama
*/

#include "../include/tools.h"

static int my_float(int nb)
{
    int len = 0;

    if (nb >= 10) {
        len += my_float(nb / 10);
        my_putchar(nb % 10 + '0');
        len++;
    }
    if (nb < 10) {
        my_putchar(nb % 10 + '0');
        len++;
    }
    return len;
}

int my_put_float(float n)
{
    int nb = n;
    int count = 0;

    if (nb < 0) {
        my_putchar('-');
        count++;
        nb = nb * -1;
        n = n * -1;
    }
    count += my_float(nb);
    my_putchar('.');
    count++;
    for (int i = 0; i < 6; i++) {
        n = n * 10;
        nb = n;
        nb = nb % 10;
        count += my_float(nb);
    }
    return count;
}
