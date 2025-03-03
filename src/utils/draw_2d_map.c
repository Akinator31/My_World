/*
** EPITECH PROJECT, 2025
** BS
** File description:
** draw_2d_map
*/

#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structure.h"
#include "utils.h"

sfVertexArray *create_line(sfVertexArray *vertex_array, sfVector2f *point1,
    sfVector2f *point2)
{
    sfVertex vertex1 = {.position = *point1, .color = sfWhite};
    sfVertex vertex2 = {.position = *point2, .color = sfWhite};

    vertex_array = sfVertexArray_create();
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

static int draw_vertex(engine_t *engine, int i, int j, map_t *map)
{
    sfVertexArray *vertex_array_left = sfVertexArray_create();
    sfVertexArray *vertex_array_right = sfVertexArray_create();

    if (i + 1 < map->size_tab)
        sfRenderWindow_drawVertexArray(engine->window,
            create_line(vertex_array_left, &map->map2D[i][j],
                &map->map2D[i + 1][j]), NULL);
    if (j + 1 < map->size_tab)
        sfRenderWindow_drawVertexArray(engine->window,
            create_line(vertex_array_right, &map->map2D[i][j],
                &map->map2D[i][j + 1]), NULL);
    sfVertexArray_destroy(vertex_array_left);
    sfVertexArray_destroy(vertex_array_right);
    return 0;
}

int draw_2d_map(engine_t *engine)
{
    map_t *map = engine->map;

    if (map->map2D == NULL)
        return 84;
    for (int i = 0; map->map2D[i] != NULL; i++) {
        for (int j = 0; map->map2D[j] != NULL; j++) {
            draw_vertex(engine, i, j, map);
        }
    }
    return 0;
}
