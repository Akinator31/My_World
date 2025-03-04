/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** get_input_on_map
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <math.h>
#include "engine.h"
#include "utils.h"
#include "structure.h"

static int error_on_flatten(map_t *map, int i, int j, int *rep)
{
    if (i >= 0 && i < map->size_tab && j >= 0 && j < map->size_tab) {
        *rep += 1;
        return map->map3D[i][j];
    }
    return 0;
}

static int flatten_map(map_t *map, int x, int y)
{
    float somme = 0.0;
    int rep = 0;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++)
            somme += error_on_flatten(map, i, j, &rep);
    }
    somme /= rep;
    return round(somme);
}

static void cmp_point_mouse(engine_t *engine, int *px, int *py, int x)
{
    float hypo = 0.0;
    map_t *map = engine->map;
    sfVector2i position = sfMouse_getPositionRenderWindow(engine->window);

    for (int y = 0; map->map2D[y] != NULL; y++) {
        hypo = sqrt(pow(map->map2D[x][y].x - position.x, 2)
            + pow(map->map2D[x][y].y - position.y, 2));
        if (hypo < HITBOX_RANGE) {
            *px = x;
            *py = y;
        }
    }
}

static void get_point_mouse(engine_t *engine, int *px, int *py)
{
    map_t *map = engine->map;
    int x = 0;

    for (x = 0; map->map2D[x] != NULL; x++)
        cmp_point_mouse(engine, px, py, x);
}

void key_pressed_on_map(engine_t *engine)
{
    map_t *map = engine->map;
    int x = -1;
    int y = -1;

    get_point_mouse(engine, &x, &y);
    if (!(x < map->size_tab && y < map->size_tab && x > -1 && y > -1))
        return;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        map->map3D[x][y]++;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        map->map3D[x][y]--;
    if (sfKeyboard_isKeyPressed(sfKeyF))
        map->map3D[x][y] = flatten_map(map, x, y);
    map->map2D[x][y] = project_iso_point(x, y, map);
}

void cmp_position(engine_t *engine)
{
    map_t *map = engine->map;
    int x = -1;
    int y = -1;

    if (MOUSE_PRESSED()) {
        get_point_mouse(engine, &x, &y);
        if (!(x < map->size_tab && y < map->size_tab && x > -1 && y > -1))
            return;
        if (engine->mouse_status == 0)
            map->map3D[x][y]++;
        if (engine->mouse_status == 1)
            map->map3D[x][y]--;
        if (engine->mouse_status == 2)
            map->map3D[x][y] = flatten_map(map, x, y);
        map->map2D[x][y] = project_iso_point(x, y, map);
    }
    return;
}

static void zoom_in(engine_t *engine, map_t *map)
{
    if (map->zoom < 5) {
        map->zoom = 5;
        return;
    }
    if (engine->event.mouseWheelScroll.delta < 0.0)
        map->zoom--;
    if (engine->event.mouseWheelScroll.delta > 0.0)
        map->zoom++;
    if (sfKeyboard_isKeyPressed(sfKeyP))
        map->zoom++;
    if (sfKeyboard_isKeyPressed(sfKeyM))
        map->zoom--;
}

static void change_angle(map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        map->angle_x++;
        map->angle_y++;
    }
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        map->angle_x--;
        map->angle_y--;
    }
}

void move_map_input(engine_t *engine)
{
    map_t *map = engine->map;

    if (!map)
        return;
    zoom_in(engine, map);
    change_angle(map);
    if (sfKeyboard_isKeyPressed(sfKeyI) || sfKeyboard_isKeyPressed(sfKeyUp))
        map->offset_y -= 10;
    if (sfKeyboard_isKeyPressed(sfKeyK) || sfKeyboard_isKeyPressed(sfKeyDown))
        map->offset_y += 10;
    if (sfKeyboard_isKeyPressed(sfKeyJ) || sfKeyboard_isKeyPressed(sfKeyRight))
        map->offset_x -= 10;
    if (sfKeyboard_isKeyPressed(sfKeyL) || sfKeyboard_isKeyPressed(sfKeyLeft))
        map->offset_x += 10;
    map->map2D = change_2d_map(map);
}
