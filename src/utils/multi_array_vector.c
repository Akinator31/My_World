/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** multi_array_vector
*/

#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

void multi_array_vector(sfVector2f **array, float multi)
{
    for (int i = 0; array[i] != NULL; i++)
        for (int j = 0; array[j] != NULL; j++) {
            array[i][j].x = array[i][j].x * multi;
            array[i][j].y = array[i][j].y * multi;
        }
}
