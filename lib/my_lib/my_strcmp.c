/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** task06
*/

#include "my_lib.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int result = 0;

    for (; (s1[i] != '\0') || (s2[i] != '\0'); i++) {
        if (s1[i] != s2[i]) {
            result = s1[i] - s2[i];
            return result;
        }
    }
    result = s1[i] != s2[i];
    return result;
}
