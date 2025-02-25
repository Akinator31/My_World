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

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfWhite};
    sfVertex vertex2 = {.position = *point2, .color = sfWhite};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

static int draw_vertex(engine_t *engine, int i, int j)
{
    if (i + 1 < engine->size_tab)
        sfRenderWindow_drawVertexArray(engine->window,
            create_line(&engine->map2D[i][j], &engine->map2D[i + 1][j]), NULL);
    if (j + 1 < engine->size_tab)
        sfRenderWindow_drawVertexArray(engine->window,
            create_line(&engine->map2D[i][j], &engine->map2D[i][j + 1]), NULL);
    return 0;
}

int draw_2d_map(engine_t *engine)
{
    if (engine->map2D == NULL) {
        printf("jepasse\n");
        return 84;
    }
    for (int i = 0; engine->map2D[i] != NULL; i++) {
        for (int j = 0; engine->map2D[j] != NULL; j++) {
            draw_vertex(engine, i, j);
        }
    }
    return 0;
}
