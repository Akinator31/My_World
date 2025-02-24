/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** print string
*/

#include <unistd.h>
#include "include/my.h"

int my_putstr(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    write(1, str, i);
    return (i);
}
