/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "include/lib.h"

void flag_c(char const *format, va_list flag, ml_t *p)
{
    if (format[p->i] == 'c') {
        p->len += my_putchar(va_arg(flag, int));
        p->i++;
    }
}

void flag_s(char const *format, va_list flag, ml_t *p)
{
    if (format[p->i] == 's') {
        p->len += my_putstr(va_arg(flag, char *));
        p->i++;
    }
}

void flag_sup(char const *format, va_list flag, ml_t *p)
{
    if (format[p->i] == 'S') {
        p->len += my_put_dtab(va_arg(flag, char **));
        p->i++;
    }
}
