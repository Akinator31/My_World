/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-alexy.legrand
** File description:
** my_nbr_to_str
*/

#include <stdlib.h>
#include "hashtable.h"

char *nbr_in_str(int nbr)
{
    int size = my_nbrlen(nbr);
    int i = 0;
    char *str = malloc(sizeof(char) * (size + 1));

    for (i = size - 1; i != - 1; i--) {
        str[i] = (nbr % 10) + '0';
        nbr /= 10;
    }
    str[size] = '\0';
    return str;
}
