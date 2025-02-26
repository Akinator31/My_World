/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** create_array_int
*/

#include <stdlib.h>

int **create_array_int(int size)
{
    int **array = malloc(sizeof(int *) * (size + 1));

    array[size] = NULL;
    for (int i = 0; i < size; i++) {
        array[i] = malloc(sizeof(int) * (size + 1));
        for (int j = 0; j <= size; j++) {
            array[i][j] = 0;
        }
    }
    return array;
}
