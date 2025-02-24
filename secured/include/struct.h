/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-alexy.legrand
** File description:
** include
*/

#ifndef INCLUDED_INCLUDE_H
    #define INCLUDED_INCLUDE_H

typedef struct data_s {
    int cripted_code;
    char *name;
    struct data_s *next;
} data_t;

typedef struct hash_s {
    int temp;
    int max_value;
    int j;
    int k;
    int final_value;
} hash_t;

#endif
