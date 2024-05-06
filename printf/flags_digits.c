/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "include/lib.h"

void flag_i(char const *format, va_list flag, ml_t *p)
{
    if (format[p->i] == 'd' || format[p->i] == 'i') {
        p->len += my_put_nbr(va_arg(flag, int), "0123456789");
        p->i++;
    }
}

void flag_f(char const *format, va_list flag, ml_t *p)
{
    if (format[p->i] == 'f') {
        p->len += my_put_float(va_arg(flag, double));
        p->i++;
    }
}

void flag_x(char const *format, va_list flag, ml_t *p)
{
    if (format[p->i] == 'x') {
        p->len += my_put_nbr(va_arg(flag, unsigned int), "0123456789abcdef");
        p->i++;
    }
}

void flag_b(char const *format, va_list flag, ml_t *p)
{
    if (format[p->i] == 'b') {
        p->len += my_put_nbr(va_arg(flag, unsigned int), "01");
        p->i++;
    }
}

void flag_o(char const *format, va_list flag, ml_t *p)
{
    if (format[p->i] == 'o') {
        p->len += my_put_nbr(va_arg(flag, unsigned int), "01234567");
        p->i++;
    }
}
