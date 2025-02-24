/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-secured-alexy.legrand
** File description:
** other_hash_function.c
*/
#include "../include/struct.h"
#include "../include/my.h"
#include <math.h>

int calcul_nb_pair(int temp, char *key, int i, int nbr)
{
    if (temp % 2 == 0) {
            temp = key[i] * i;
            temp *= (key[i] + key[i]);
            temp /= (i + 1);
            nbr += temp;
        }
        return nbr;
}

int hash(char *key, int len)
{
    int temp = 0;
    int nbr = 0;
    int k = 1;

    if (key == NULL)
        return 84;
    for (int i = 0; key[i] != '\0'; i++) {
        temp = key[i];
        if (temp % 2 != 0) {
            temp = key[i] * i;
            temp *= (key[i] + key[i]);
            temp /= (i + 1);
            nbr += temp;
        }
        nbr = calcul_nb_pair(temp, key, i, nbr);
        for (k; k <= len; k++)
            nbr *= (len * len);
    }
    nbr *= k;
    return nbr;
}
