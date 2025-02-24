/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-organized-romeo.louvel
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>
    #include <stdio.h>
int flags(char nb1, va_list list, int *cpt);
int mini_printf(const char *format, ...);
int toprint(int a);
int my_put_nbr(int a);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
#endif
