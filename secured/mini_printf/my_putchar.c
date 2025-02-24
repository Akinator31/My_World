/*
** EPITECH PROJECT, 2024
** my_putchar.c
** File description:
** print char
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"


void my_putchar(char c)
{
    write(1, &c, 1);
}
