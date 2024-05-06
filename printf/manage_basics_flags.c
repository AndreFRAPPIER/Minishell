/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#include "include/lib.h"

static void print_mod(char const *format, ml_t *p)
{
    if (format[p->i] == '%') {
        my_putchar('%');
        p->i++;
        p->len++;
    }
}

void check_commun_flag(char const *format, va_list flag, ml_t *p)
{
    print_mod(format, p);
    flag_i(format, flag, p);
    flag_c(format, flag, p);
    flag_s(format, flag, p);
    flag_sup(format, flag, p);
    flag_f(format, flag, p);
    flag_x(format, flag, p);
    flag_xsup(format, flag, p);
    flag_b(format, flag, p);
    flag_o(format, flag, p);
    flag_e(format, flag, p);
    flag_esup(format, flag, p);
}
