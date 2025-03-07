/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** criterion_lib_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_lib.h"

Test(my_strcmp, test_equal_strings) {
    cr_assert_eq(my_strcmp("hello", "hello"), 0);
}

Test(my_strcmp, test_different_strings) {
    cr_assert_neq(my_strcmp("hello", "world"), 0);
}

Test(my_strnum, test_positive_number) {
    char *result = my_strnum(12345);
    cr_assert_str_eq(result, "12345");
    free(result);
}

Test(my_strnum, test_zero) {
    char *result = my_strnum(0);
    cr_assert_str_eq(result, "0");
    free(result);
}

Test(my_put_nbr, test_positive_number) {
    cr_redirect_stdout();
    my_put_nbr(12345);
    cr_assert_stdout_eq_str("12345");
}

Test(my_put_nbr, test_negative_number) {
    cr_redirect_stdout();
    my_put_nbr(-12345);
    cr_assert_stdout_eq_str("-12345");
}

Test(my_strlowcase, test_mixed_case) {
    char str[] = "HeLLo WoRLd";
    cr_assert_str_eq(my_strlowcase(str), "hello world");
}

Test(my_strlen, test_non_empty_string) {
    cr_assert_eq(my_strlen("hello"), 5);
}

Test(my_strlen, test_empty_string) {
    cr_assert_eq(my_strlen(""), 0);
}

Test(my_strcpy, test_copy_string) {
    char dest[6];
    cr_assert_str_eq(my_strcpy(dest, "hello"), "hello");
}

Test(the_small_int, test_min_int) {
    cr_redirect_stdout();
    cr_assert_eq(the_small_int(-2147483648), 1);
    cr_assert_stdout_eq_str("-2147483648");
}

Test(the_small_int, test_not_min_int) {
    cr_assert_eq(the_small_int(-12345), 0);
}

Test(my_putchar, test_putchar) {
    cr_redirect_stdout();
    my_putchar('a');
    cr_assert_stdout_eq_str("a");
}

Test(my_putstr, test_putstr) {
    cr_redirect_stdout();
    my_putstr("hello");
    cr_assert_stdout_eq_str("hello");
}
