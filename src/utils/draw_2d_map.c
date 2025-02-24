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

sfVertexArray *create_line(sfVector2f *point1 , sfVector2f *point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create(); 
    sfVertex vertex1 = {*point1, sfWhite};
    sfVertex vertex2 = {*point2, sfWhite};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

static int draw_vertex(sfVector2f **map2D, sfRenderWindow *window, int i, int j)
{
    if (i + 1 < 6)
        sfRenderWindow_drawVertexArray(window,
            create_line(&map2D[i][j], &map2D[i + 1][j]), NULL);
    if (j + 1 < 6)
        sfRenderWindow_drawVertexArray(window,
            create_line(&map2D[i][j], &map2D[i][j + 1]), NULL);

}

int draw_2d_map(sfRenderWindow *window, sfVector2f **map2D)
{
    for (int i = 0; map2D[i] != NULL; i++)
        for (int j = 0; map2D[j] != NULL; j++) {
            draw_vertex(map2D, window, i, j);
        }
}
 