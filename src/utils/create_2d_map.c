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

sfVector2f project_iso_point(int x, int y, map_t *map)
{
    sfVector2f point2d;

    point2d.x = (cos(map->angle_x * M_PI / 180) * x -
        cos(map->angle_x * M_PI / 180) * y) * map->zoom + map->offset_x;
    point2d.y = (sin(map->angle_y * M_PI / 180) * y +
        sin(map->angle_y * M_PI / 180) * x - map->map3D[x][y])
            * map->zoom + map->offset_y;
    return point2d;
}

sfVector2f **create_2d_map(map_t *map)
{
    sfVector2f **map2D = NULL;

    map2D = malloc(sizeof(sfVector2f *) * (map->size_tab + 1));
    map2D[map->size_tab] = NULL;
    for (int i = 0; i < map->size_tab; i++) {
        map2D[i] = malloc(sizeof(sfVector2f) * map->size_tab);
        for (int j = 0; j < map->size_tab; j++)
        map2D[i][j] = project_iso_point(i, j, map);
    }
    return map2D;
}

sfVector2f **change_2d_map(map_t *map)
{
    for (int i = 0; i < map->size_tab; i++) {
        for (int j = 0; j < map->size_tab; j++)
        map->map2D[i][j] = project_iso_point(i, j, map);
    }
    return map->map2D;
}
