/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin [WSL : Ubuntu]
** File description:
** structure
*/

#ifndef INCLUDED_STRUCTURE_H
    #define INCLUDED_STRUCTURE_H
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include "my_list.h"
    #include "my_lib.h"
    #define POS(x, y) ((sfVector2f){(x), (y)})
    #define AREA(x, y) ((sfIntRect){(x), (y)})
    #define TX_CREATE(res, i) res = sfTexture_createFromFile(assets[i], NULL)
    #define MUSIC_CREATE(res, i) res = sfMusic_createFromFile(assets[i])
    #define GET_RES(name) engine->ressources->name
    #define GET_SPRITE() ((entity_t *)(temp->data))->sprite
    #define MOUSE_RELEASED() engine->event.type == sfEvtMouseButtonReleased
    #define MOUSE_PRESSED() engine->event.type == sfEvtMouseButtonPressed
    #define IS_ENTITY(entity_id) ((entity_t *)(temp->data))->id == entity_id
    #define IS_CLICK(sprite) is_mouse_on_sprite(engine, sprite)
    #define SF_VECTOR_2U(x, y) ((sfVector2u){(x), (y)})
    #define SF_VECTOR_2I(x, y) ((sfVector2i){(x), (y)})

typedef struct engine_s engine_t;
typedef struct scene_s scene_t;
typedef struct entity_s entity_t;
typedef struct ressource_manager_s ressource_manager_t;

enum entity_state {
    ACTIVE,
    TOUCH,
    OFF_SCREEN
};

enum game_state {
    RUNNING,
    PAUSED,
};

enum which_music {
    MENU_MUSIC,
    GAME_MUSIC,
    PAUSE,
};

enum music_state {
    PLAYING,
    STOPPED
};

struct engine_s {
    sfRenderWindow *window;
    sfClock *clock;
    scene_t *current_scene;
    linked_list_t *scenes_list;
    ressource_manager_t *ressources;
    sfEvent event;
    int state;
    float delta_time;
    int default_fps_framerate;
    int music_state;
    int music_selector;
    int score;
};

struct scene_s {
    int id;
    linked_list_t *entity_list;
    sfClock *clock;
    int (*scene_update)(scene_t *scene, engine_t *engine);
    void (*scene_render)(scene_t *scene, engine_t *engine);
    void (*scene_destroy)(scene_t *scene);
};

struct entity_s {
    sfSprite *sprite;
    sfVector2f pos;
    int velocity;
    double direction_angle;
    int id;
    int state;
    int is_text;
    sfText *text;
    sfClock *clock;
    void (*entity_init)(entity_t *entity, scene_t *scene, engine_t *engine);
    void (*entity_update)(entity_t *entity, scene_t *scene, engine_t *engine);
    void (*entity_render)(entity_t *entity, engine_t *engine);
    sfBool (*entity_check_collision)(entity_t *entity, entity_t *other);
    void (*entity_destroy)(entity_t *entity);
};

struct ressource_manager_s {
    sfTexture *background;
    sfTexture *play_button;
    sfTexture *play_button_hover;
    sfTexture *quit_button;
    sfTexture *quit_button_hover;
    sfTexture *settings_button;
    sfTexture *settings_button_hover;
    sfTexture *sound_on_button;
    sfTexture *sound_on_button_hover;
    sfTexture *sound_off_button;
    sfTexture *sound_off_button_hover;
    sfTexture *back_button;
    sfTexture *back_button_hover;
    sfTexture *settings_background;
    sfTexture *res_900;
    sfTexture *res_1920;
    sfTexture *res_4k;
    sfTexture *res_900_hover;
    sfTexture *res_1920_hover;
    sfTexture *res_4k_hover;
    sfTexture *game_background;
    sfTexture *pause_button;
    sfTexture *pause_button_hover;
    sfTexture *resume_button;
    sfTexture *resume_button_hover;
    sfTexture *chicken;
    sfTexture *special;
    sfMusic *menu_music;
    sfMusic *game_music;
    sfFont *font;
    void (*destroy_ressources)(ressource_manager_t *ressources);
};

#endif
