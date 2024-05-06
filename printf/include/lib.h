/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#ifndef LIB_H
    #define LIB_H
    #include <stdarg.h>
    #include "tools.h"
    #include "struct.h"

void check_commun_flag(char const *format, va_list flag, ml_t *p);
int my_printf(char const *format, ...);
void flag_i(char const *format, va_list flag, ml_t *p);
void flag_f(char const *format, va_list flag, ml_t *p);
void flag_c(char const *format, va_list flag, ml_t *p);
void flag_s(char const *format, va_list flag, ml_t *p);
void flag_x(char const *format, va_list flag, ml_t *p);
void flag_xsup(char const *format, va_list flag, ml_t *p);
void flag_b(char const *format, va_list flag, ml_t *p);
void flag_o(char const *format, va_list flag, ml_t *p);
void flag_sup(char const *format, va_list flag, ml_t *p);
void flag_e(char const *format, va_list flag, ml_t *p);
void flag_esup(char const *format, va_list flag, ml_t *p);

#endif
