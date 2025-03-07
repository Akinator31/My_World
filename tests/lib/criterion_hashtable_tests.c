/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** criterion_hashtable_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "hashtable.h"

int hash_function(char *key, int len) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash = (hash + key[i]) % len;
    }
    return hash;
}

void destroy_value(void *value) {
    free(value);
}

Test(hashtable, create_and_delete) {
    hashtable_t *ht = new_hashtable(hash_function, 10);
    cr_assert_not_null(ht);
    cr_assert_eq(ht->len, 10);
    cr_assert_not_null(ht->hash_data);
    delete_hashtable(ht);
}

Test(hashtable, insert_and_search) {
    hashtable_t *ht = new_hashtable(hash_function, 10);
    char *key = "test";
    char *value = strdup("value");

    cr_assert_eq(ht_insert(ht, key, value), 0);
    char *result = ht_search(ht, key);
    cr_assert_str_eq(result, "value");

    delete_hashtable(ht);
}

Test(hashtable, insert_and_delete) {
    hashtable_t *ht = new_hashtable(hash_function, 10);
    char *key = "test";
    char *value = strdup("value");

    cr_assert_eq(ht_insert(ht, key, value), 0);
    cr_assert_eq(ht_delete(ht, key, destroy_value), 0);
    cr_assert_null(ht_search(ht, key));

    delete_hashtable(ht);
}
