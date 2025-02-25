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
    #include "hashtable.h"
    #define POS(x, y) ((sfVector2f){(x), (y)})
    #define AREA(x, y) ((sfIntRect){(x), (y)})
    #define TX_CREATE(i) sfTexture_createFromFile(assets[i].path, NULL)
    #define MUSIC_CREATE(i) sfMusic_createFromFile(assets[i].path)
    #define FONT_CREATE(i) sfFont_createFromFile(assets[i].path)
    #define IS(n) e == n
    #define GET_RES(name) ht_search(engine->ressources->hashtable, name)
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
typedef struct assets_s assets_t;
typedef enum assets_type_s assets_type_t;

enum assets_type_s {
    IMAGE,
    MUSIC,
    FONT,
};

enum entity_state {
    ACTIVE,
    TOUCH,
    OFF_SCREEN,
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
    int **map3D;
    sfVector2f **map2D;
    int size_tab;
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
    hashtable_t *hashtable;
    void (*destroy)(ressource_manager_t *);
};

struct assets_s {
    char *name;
    char *path;
    assets_type_t type;
};

#endif
