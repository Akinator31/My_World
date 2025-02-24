/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** my_world
*/

#ifndef INCLUDED_MY_WORLD_H
    #define INCLUDED_MY_WORLD_H
    #include <SFML/Graphics.h>
    #define WIDTH 1920
    #define HEIGTH 1080
    #define NAME "MY WORLD"

sfRenderWindow *create_window(unsigned int width,
    unsigned int heigth, char *window_title);

#endif
