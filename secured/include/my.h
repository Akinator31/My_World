/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** my.h
*/

#include "hashtable.h"
#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
int my_strcmpsize(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
int mini_printf(const char *format, ...);
char *nbr_in_str(int nbr);
int my_nbrlen(int nbr);
int abs(int nbr);
int get_str_in_nbr(char *tmp);
int my_getnbr(char const *str);
int define_struct(hash_t *h);
int hash(char *key, int len);

#endif
