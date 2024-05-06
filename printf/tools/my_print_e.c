/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "../include/tools.h"

static int print_char(int count, int status)
{
    int len = 0;

    if (status == 1) {
        len += my_putchar('+');
    } else
        len += my_putchar('-');
    if (count < 10)
        len += my_putchar('0');
    return len + my_put_nbr(count, "0123456789");
}

int print_scientific(float nb, char e)
{
    int count = 0;
    int status = 1;
    int len = 0;

    while (nb > 10) {
        nb = nb / 10;
        count++;
    }
    while (nb < 1) {
        nb = nb * 10;
        count++;
        status = -1;
    }
    len += my_put_float(nb);
    len += my_putchar(e);
    len += print_char(count, status);
    return len;
}
