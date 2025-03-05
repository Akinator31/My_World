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

static void draw_column(engine_t *engine)
{
    map_t *map = engine->map;
    int s_tab = map->size_tab - 1;
    sfVector2f point1 = {map->map2D[s_tab][0].x, engine->screen_size.y};
    sfVector2f point2 = {map->map2D[0][s_tab].x, engine->screen_size.y};
    sfVector2f point3 = {map->map2D[s_tab][s_tab].x, engine->screen_size.y};

    map->vertex_array = sfVertexArray_create();
    sfRenderWindow_drawVertexArray(engine->window, create_line(
        map->vertex_array, &map->map2D[s_tab][0], &point1), NULL);
    sfVertexArray_destroy(map->vertex_array);
    map->vertex_array = sfVertexArray_create();
    sfRenderWindow_drawVertexArray(engine->window, create_line(
        map->vertex_array, &map->map2D[0][s_tab], &point2), NULL);
    sfVertexArray_destroy(map->vertex_array);
    map->vertex_array = sfVertexArray_create();
    sfRenderWindow_drawVertexArray(engine->window, create_line(
        map->vertex_array, &map->map2D[s_tab][s_tab], &point3), NULL);
    sfVertexArray_destroy(map->vertex_array);
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
    sfVertex vertex1 = {.position = map->map2D[i][j], .color = sfMagenta};
    sfVertex vertex2 = {.position = map->map2D[i + 1][j], .color = sfMagenta};
    sfVertex vertex4 = {.position = map->map2D[i][j + 1], .color = sfMagenta};
    sfVertex vertex3 = {.position = map->map2D[i + 1][j + 1],
        .color = sfMagenta};

    if (map->map3D[i][j] == map->map3D[i + 1][j]
        && map->map3D[i][j + 1] == map->map3D[i + 1][j + 1]
        && map->map3D[i][j] == map->map3D[i][j + 1]) {
    vertex1.color = sfCyan;
    vertex2.color = sfCyan;
    vertex3.color = sfCyan;
    vertex4.color = sfCyan;
        }
    sfVertexArray_append(map->vertex_array, vertex1);
    sfVertexArray_append(map->vertex_array, vertex2);
    sfVertexArray_append(map->vertex_array, vertex3);
    sfVertexArray_append(map->vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(map->vertex_array, sfQuads);
    return map->vertex_array;
}

static sfVertexArray *quads_side(engine_t *engine, int size1, int size2)
{
    map_t *map = engine->map;
    int s_tab = map->size_tab - 1;
    sfVertex vertex1 = {.position = map->map2D[size1][size2],
        .color = sfMagenta};
    sfVertex vertex2 = {.position = {map->map2D[size1][size2].x,
        engine->screen_size.y + 1000}, .color = sfMagenta};
    sfVertex vertex4 = {.position = map->map2D[s_tab][s_tab],
        .color = sfMagenta};
    sfVertex vertex3 = {.position = {map->map2D[s_tab][s_tab].x,
        engine->screen_size.y + 1000}, .color = sfMagenta};

    sfVertexArray_append(map->vertex_array, vertex1);
    sfVertexArray_append(map->vertex_array, vertex4);
    sfVertexArray_append(map->vertex_array, vertex3);
    sfVertexArray_append(map->vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(map->vertex_array, sfQuads);
    return map->vertex_array;
}

static void draw_side(engine_t *engine)
{
    map_t *map = engine->map;

    map->vertex_array = sfVertexArray_create();
    sfRenderWindow_drawVertexArray(engine->window,
            quads_side(engine, map->size_tab - 1, 0), NULL);
    sfVertexArray_destroy(map->vertex_array);
    map->vertex_array = sfVertexArray_create();
    sfRenderWindow_drawVertexArray(engine->window,
            quads_side(engine, 0, map->size_tab - 1), NULL);
    sfVertexArray_destroy(map->vertex_array);
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
            draw_side(engine);
            draw_column(engine);
            draw_square(engine, i, j);
            draw_vertex(engine, i, j);
        }
    }
    return 0;
}
