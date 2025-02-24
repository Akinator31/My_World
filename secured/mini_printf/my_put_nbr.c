/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** put nbr
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"


int toprint(int a)
{
    int chi[100];
    int var = 0;
    int i;
    int tps;

    while (a != 0) {
        var++;
        chi[var] = a % 10 + 48;
        a = a / 10;
    }
    for (i = var; i > 0; i--) {
    tps = chi[i];
    write(1, &tps, 1);
    }
    return (var);
}

int my_put_nbr(int a)
{
    int m = 45;
    int var = 0;

    if (a < 0) {
        write(1, &m, 1);
        a = a* -1;
        var++;
    }
    if (a == 0) {
        m = 48;
        write(1, &m, 1);
        return (var + 1);
    } else {
        return (var + toprint(a));
    }
}
