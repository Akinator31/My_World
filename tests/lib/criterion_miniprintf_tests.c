/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** criterion_miniprintf_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_printf.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(mini_printf, print_string, .init = redirect_all_std)
{
    mini_printf("Hello %s", "world");
    cr_assert_stdout_eq_str("Hello world");
}

Test(mini_printf, print_integer, .init = redirect_all_std)
{
    mini_printf("Number: %d", 42);
    cr_assert_stdout_eq_str("Number: 42");
}

Test(mini_printf, print_char, .init = redirect_all_std)
{
    mini_printf("Character: %c", 'A');
    cr_assert_stdout_eq_str("Character: A");
}

Test(mini_printf, print_percent, .init = redirect_all_std)
{
    mini_printf("Percent: %%");
    cr_assert_stdout_eq_str("Percent: %");
}

Test(mini_printf, print_multiple, .init = redirect_all_std)
{
    mini_printf("String: %s, Number: %d, Char: %c, Percent: %%", "test", 123, 'X');
    cr_assert_stdout_eq_str("String: test, Number: 123, Char: X, Percent: %");
}
