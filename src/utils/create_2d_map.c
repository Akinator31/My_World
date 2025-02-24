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

#define angle_x 45
#define angle_y 35
#define tab_size 100
#define offset_x 1000
#define offset_y 100

sfVector2f project_iso_point(int x ,int y ,float z)
{
    sfVector2f point2d;

    point2d.x = (cos(angle_x * M_PI / 180) * x -
        cos(angle_x * M_PI / 180) * y) * tab_size + offset_x;
    point2d.y = (sin(angle_y * M_PI / 180) * y +
        sin(angle_y * M_PI / 180) * x - z) * tab_size + offset_y;
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
        map2D[i][j] = project_iso_point(i, j, map3D[i][j] / 1.5);
    }
    return map2D;    
}
