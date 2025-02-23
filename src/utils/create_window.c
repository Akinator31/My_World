/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** create_window
*/

#include "my_world.h"

sfRenderWindow *create_window(unsigned int width,
    unsigned int heigth, char *window_title)
{
    sfVideoMode video_mode = {width, heigth, 32};
    sfRenderWindow *window = sfRenderWindow_create(
        video_mode, window_title, sfClose, NULL);

    return window;
}
