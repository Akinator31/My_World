/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myradar-romeo.louvel
** File description:
** get_nbr_in_str
*/

int get_str_in_nbr(char *tmp)
{
    int returnnbr = 0;

    for (int i = 0; tmp[i] != '\0'; i++) {
    returnnbr += tmp[i] - '0';
    returnnbr *= 10;
    }
    if (returnnbr == 0)
        return 0;
    return returnnbr / 10;
}
