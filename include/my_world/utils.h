/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** utils
*/

#ifndef INCLUDED_UTILS_H
    #define INCLUDED_UTILS_H
    #include <SFML/Graphics.h>
    #include "engine.h"
    #define ANGLE_X 45
    #define ANGLE_Y 35
    #define TAB_SIZE 100
    #define OFFSET_X 1000
    #define OFFSET_Y 100

sfRenderWindow *create_window(unsigned int width,
    unsigned int heigth, char *window_title);
void set_sprite_hover(sfSprite *sprite, engine_t *engine,
    sfTexture *new_texture, sfTexture *original_texture);
sfBool is_mouse_on_sprite(engine_t *engine,
    sfSprite *sprite);
scene_t *get_scene_by_id(engine_t *engine, int id);
void mute_or_unmute_music(engine_t *engine, int mute_or_unmute);
void switch_game_music(engine_t *engine);
void switch_menu_music(engine_t *engine);
void switch_pause_music(engine_t *engine);
int help(int ac, char **av);
sfVector2f get_random_pos(engine_t *engine);
int check_screen_size(engine_t *engine, sfVector2u request_size);

#endif
