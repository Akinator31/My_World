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

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

static int draw_vertex(engine_t *engine, int i, int j)
{
    map_t *map = engine->map;

    if (i + 1 < map->size_tab) {
        map->vertex_array = sfVertexArray_create();
        sfRenderWindow_drawVertexArray(engine->window,
            create_line(map->vertex_array, &map->map2D[i][j],
                &map->map2D[i + 1][j]), NULL);
        sfVertexArray_destroy(map->vertex_array);
    }
    if (j + 1 < map->size_tab) {
        map->vertex_array = sfVertexArray_create();
        sfRenderWindow_drawVertexArray(engine->window,
            create_line(map->vertex_array, &map->map2D[i][j],
                &map->map2D[i][j + 1]), NULL);
        sfVertexArray_destroy(map->vertex_array);
    }
    return 0;
}

static sfVertexArray *create_quads(map_t *map, int i, int j)
{
    sfVertex vertex1 = {.position = map->map2D[i][j], .color = sfBlack};
    sfVertex vertex2 = {.position = map->map2D[i + 1][j], .color = sfBlack};
    sfVertex vertex4 = {.position = map->map2D[i][j + 1], .color = sfBlack};
    sfVertex vertex3 = {.position = map->map2D[i + 1][j + 1],
        .color = sfWhite};

    if (map->map3D[i][j] == map->map3D[i + 1][j]
        && map->map3D[i][j + 1] == map->map3D[i + 1][j + 1]
        && map->map3D[i][j] == map->map3D[i][j + 1]) {
    vertex1.color = sfColor_fromRGB(156, 156, 156);
    vertex2.color = sfColor_fromRGB(156, 156, 156);
    vertex3.color = sfColor_fromRGB(156, 156, 156);
    vertex4.color = sfColor_fromRGB(156, 156, 156);
        }
    sfVertexArray_append(map->vertex_array, vertex1);
    sfVertexArray_append(map->vertex_array, vertex2);
    sfVertexArray_append(map->vertex_array, vertex3);
    sfVertexArray_append(map->vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(map->vertex_array, sfQuads);
    return map->vertex_array;
}

static void draw_square(engine_t *engine, int i, int j)
{
    map_t *map = engine->map;

    if (i + 1 < map->size_tab && j + 1 < map->size_tab) {
        map->vertex_array = sfVertexArray_create();
        sfRenderWindow_drawVertexArray(engine->window,
            create_quads(map, i, j), NULL);
        sfVertexArray_destroy(map->vertex_array);
    }
}

int draw_2d_map(engine_t *engine)
{
    map_t *map = engine->map;

    if (map == NULL || map->map2D == NULL)
        return 84;
    for (int i = 0; map->map2D[i] != NULL; i++) {
        for (int j = 0; map->map2D[j] != NULL; j++) {
            draw_square(engine, i, j);
            draw_vertex(engine, i, j);
        }
    }
    return 0;
}
