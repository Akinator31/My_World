/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

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

typedef struct hashtable_s {
    data_t **hash_data;
    int len;
    int (*hash)(char *, int);
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destro table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
int mini_printf(const char *format, ...);
int my_nbrlen(int nbr);
int abs(int nbr);
int hash(char *key, int len);

#endif /* HASHTABLE_H */
