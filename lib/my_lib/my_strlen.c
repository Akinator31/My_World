/*
** EPITECH PROJECT, 2025
** my_strlen.c
** File description:
** task03
*/

int my_strlen(char const *str)
{
    int size = 0;

    for (int i = 0; str[i] != '\0'; str++)
        size++;
    return size;
}
