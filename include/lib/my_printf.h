/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** task02
*/

#ifndef MY_H
    #define MY_H
    #define NB_FORMATTER 5
    #include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
char *my_strlowcase(char *str);
int mini_printf(const char *format, ...);

typedef struct format_specifier {
    char format_specifier;
    void (*f)(va_list *list, int *);
} format_specifier_t;

#endif
