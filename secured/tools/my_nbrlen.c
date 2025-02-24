/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myradar-romeo.louvel
** File description:
** my_nbrlen
*/


int my_nbrlen(int nbr)
{
    int size = 0;

    while (nbr >= 10) {
        size++;
        nbr /= 10;
    }
    return size + 1;
}
