/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** free_map
*/

#include <stdlib.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include "structure.h"

map_t *free_map(map_t *map)
{
    if (map == NULL)
        return NULL;
    for (int i = 0; i < map->size_tab; i++) {
        free(map->map2D[i]);
        free(map->map3D[i]);
    }
    free(map->map2D);
    free(map->map3D);
    free(map);
    return NULL;
}
