/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** criterion_list_tests
*/

#include <criterion/criterion.h>
#include "my_list.h"

void clean_func(void *data)
{
    free(data);
}

Test(push_front_list, add_single_element)
{
    linked_list_t *list = new_list();
    int data = 42;

    list = push_front_list(list, &data);
    cr_assert_not_null(list);
    cr_assert_eq(*(int *)list->data, 42);
    clear_list(list);
}

Test(push_front_list_all, add_multiple_elements)
{
    linked_list_t *list = new_list();
    int data1 = 1, data2 = 2, data3 = 3;

    list = push_front_list_all(list, 3, &data1, &data2, &data3);
    cr_assert_not_null(list);
    cr_assert_eq(*(int *)list->data, 3);
    list = list->next;
    cr_assert_eq(*(int *)list->data, 2);
    list = list->next;
    cr_assert_eq(*(int *)list->data, 1);
    clear_list(list);
}

Test(push_back_list, add_single_element)
{
    linked_list_t *list = new_list();
    int data = 42;

    list = push_back_list(list, &data);
    cr_assert_not_null(list);
    cr_assert_eq(*(int *)list->data, 42);
    clear_list(list);
}
