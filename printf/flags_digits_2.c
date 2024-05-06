/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "include/lib.h"

void flag_xsup(char const *format, va_list flag, ml_t *p)
{
    if (format[p->i] == 'X') {
        p->len += my_put_nbr(va_arg(flag, unsigned int), "0123456789ABCDEF");
        p->i++;
    }
}

void flag_e(char const *format, va_list flag, ml_t *p)
{
    if (format[p->i] == 'e') {
        p->len += print_scientific(va_arg(flag, double), 'e');
        p->i++;
    }
}

void flag_esup(char const *format, va_list flag, ml_t *p)
{
    if (format[p->i] == 'E') {
        p->len += print_scientific(va_arg(flag, double), 'E');
        p->i++;
    }
}
