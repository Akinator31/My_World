/*
** EPITECH PROJECT, 2024
** mini_printf.c
** File description:
** print char and num
*/

#include <stdarg.h>
#include <stdio.h>
#include "include/my.h"

int flags(char nb1, va_list list, int *cpt)
{
    if (nb1 == 'd' || nb1 == 'i') {
        *cpt += my_put_nbr(va_arg(list, int));
    }
    if (nb1 == 's') {
        *cpt += my_putstr(va_arg(list, char *));
    }
    if (nb1 == 'c') {
        my_putchar(va_arg(list, int));
        *cpt += 1;
    }
    if (nb1 == '%') {
        my_putchar('%');
        *cpt += 1;
    }
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int i = 0;
    int cpt = 0;

    va_start(list, format);
    while (i < my_strlen(format)) {
        if (format[i] == '%') {
            flags(format[i + 1], list, &cpt);
            i += 1;
        } else {
            my_putchar(format[i]);
            cpt++;
        }
        i++;
    }
    va_end(list);
    return (cpt - 1);
}
