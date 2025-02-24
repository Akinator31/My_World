/*
** EPITECH PROJECT, 2024
** B-CPE-110-TLS-1-1-secured-alexy.legrand
** File description:
** other_hash_function.c
*/

#include <stdlib.h>
#include <math.h>
#include "hashtable.h"

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

void compute_power(int *nbr, int len, int *k)
{
    while (*k <= len) {
        *nbr *= (len * len);
        *k += 1;
    }
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
        compute_power(&nbr, len, &k);
    }
    nbr *= k;
    return nbr;
}
