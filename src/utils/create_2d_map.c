/*
** EPITECH PROJECT, 2025
** BS
** File description:
** create_2d_map
*/

#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"

sfVector2f project_iso_point(int x, int y, float z, float size)
{
    sfVector2f point2d;

    point2d.x = (cos(ANGLE_X * M_PI / 180) * x -
        cos(ANGLE_X * M_PI / 180) * y) * (TAB_SIZE / size) + OFFSET_X;
    point2d.y = (sin(ANGLE_Y * M_PI / 180) * y +
        sin(ANGLE_Y * M_PI / 180) * x - z) * (TAB_SIZE / size) + OFFSET_Y;
    return point2d;
}

sfVector2f **create_2d_map(int **map3D)
{
    sfVector2f **map2D = NULL;
    int size = 0;

    for (size = 0; map3D[size] != NULL; size++);
    map2D = malloc(sizeof(sfVector2f *) * (size + 1));
    map2D[size] = NULL;
    for (int i = 0; map3D[i] != NULL; i++) {
        map2D[i] = malloc(sizeof(sfVector2f) * size);
        for (int j = 0; map3D[j] != NULL; j++)
        map2D[i][j] = project_iso_point(i, j, map3D[i][j] / 1.5, size / 10 + 1);
    }
    return map2D;
}
