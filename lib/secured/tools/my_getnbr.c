/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-secured-alexy.legrand
** File description:
** my_getnbr.c
*/

#include "hashtable.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0' && str[i] != ' ') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - '0';
        }
    i++;
    }
    return nb;
}
