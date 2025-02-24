/*
** EPITECH PROJECT, 2025
** B-CPE-110-TLS-1-1-secured-alexy.legrand
** File description:
** my_strcmp
*/

int my_strcmpsize(char const *s1, char const *s2)
{
    int i = 0;
    int size1 = 0;
    int size2 = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    for (size1 = 0; s1[size1] != '\0'; size1++);
    for (size2 = 0; s2[size2] != '\0'; size2++);
    if (size1 < size2)
        return -1;
    if (size1 > size2)
        return 1;
    return (0);
}
