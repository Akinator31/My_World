/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** ressources_manager
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "structure.h"
#include "hashtable.h"
#include "ressources.h"
#include "utils.h"

static const assets_t assets[] = {
    {"background", "assets/images/main_menu/bg.png", TEXTURE},
    {"create_map_bg", "assets/images/creat_map_menu/create_map_bg.png",
        TEXTURE},
    {"start_button", "assets/images/main_menu/buttons/start_button.png",
        TEXTURE},
    {"start_button_hover", "assets/images/main_menu/buttons/hover/"
        "start_button_hover.png", TEXTURE},
    {"quit_button", "assets/images/main_menu/buttons/quit_button.png",
        TEXTURE},
    {"quit_button_hover", "assets/images/main_menu/buttons/hover/"
        "quit_button_hover.png", TEXTURE},
    {"settings_button", "assets/images/main_menu/buttons/"
        "settings_button.png", TEXTURE},
    {"settings_button_hover", "assets/images/main_menu/buttons/hover/"
        "settings_button_hover.png", TEXTURE},
    {"sound_on", "assets/images/settings_menu/buttons/sound_on.png", TEXTURE},
    {"sound_on_hover", "assets/images/settings_menu/buttons/hover/"
        "sound_on_hover.png", TEXTURE},
    {"sound_off", "assets/images/settings_menu/buttons/sound_off.png",
        TEXTURE},
    {"sound_off_hover", "assets/images/settings_menu/buttons/hover/"
        "sound_off_hover.png", TEXTURE},
    {"back", "assets/images/settings_menu/buttons/back_button.png", TEXTURE},
    {"back_hover", "assets/images/settings_menu/buttons/hover/"
        "back_button_hover.png", TEXTURE},
    {"settings_bg", "assets/images/settings_menu/settings_bg.png", TEXTURE},
    {"900", "assets/images/settings_menu/buttons/900.png", TEXTURE},
    {"1920", "assets/images/settings_menu/buttons/1920.png", TEXTURE},
    {"4k", "assets/images/settings_menu/buttons/4k.png", TEXTURE},
    {"900_hover", "assets/images/settings_menu/buttons/hover/"
        "900_hover.png", TEXTURE},
    {"1920_hover", "assets/images/settings_menu/buttons/hover/"
        "1920_hover.png", TEXTURE},
    {"4k_hover", "assets/images/settings_menu/buttons/hover/"
        "4k_hover.png", TEXTURE},
    {"game_bg", "assets/images/game_scene/game_bg.png", TEXTURE},
    {"pause", "assets/images/game_scene/buttons/pause.png", TEXTURE},
    {"pause_hover", "assets/images/game_scene/buttons/hover/"
        "pause_hover.png", TEXTURE},
    {"play", "assets/images/game_scene/buttons/play.png", TEXTURE},
    {"play_hover", "assets/images/game_scene/buttons/hover/"
        "play_hover.png", TEXTURE},
    {"chicken_sprite_sheet_1", "assets/images/game_scene/"
        "chicken_sprite_sheet_1.png", TEXTURE},
    {"menu_music", "assets/sounds/menu-music.ogg", MUSIC},
    {"game_music", "assets/sounds/game-music.ogg", MUSIC},
    {"BungeeSpice_Regular", "assets/fonts/BungeeSpice-Regular.ttf", FONT},
    {"icon", "assets/images/icon.png", IMAGE},
    {"10x10", "assets/images/creat_map_menu/buttons/10x10.png", TEXTURE},
    {"10x10_hover", "assets/images/creat_map_menu/"
        "buttons/hover/10x10_hover.png", TEXTURE},
    {"50x50", "assets/images/creat_map_menu/buttons/50x50.png", TEXTURE},
    {"50x50_hover", "assets/images/creat_map_menu/"
        "buttons/hover/50x50_hover.png", TEXTURE},
    {"100x100", "assets/images/creat_map_menu/buttons/100x100.png", TEXTURE},
    {"100x100_hover", "assets/images/creat_map_menu/"
        "buttons/hover/100x100_hover.png", TEXTURE},
    {"custom", "assets/images/creat_map_menu/buttons/custom.png", TEXTURE},
    {"custom_hover", "assets/images/creat_map_menu/"
        "buttons/hover/custom_hover.png", TEXTURE},
    {"load", "assets/images/creat_map_menu/buttons/load_button.png", TEXTURE},
    {"load_hover", "assets/images/creat_map_menu/buttons/hover/"
        "load_button_hover.png", TEXTURE},
    {"pen", "assets/images/game_scene/buttons/pen_button.png", TEXTURE},
    {"pen_hover", "assets/images/game_scene/buttons/hover/"
        "pen_button_hover.png", TEXTURE},
    {"up", "assets/images/game_scene/buttons/up_button.png", TEXTURE},
    {"up_hover", "assets/images/game_scene/buttons/hover/"
        "up_button_hover.png", TEXTURE},
    {"down", "assets/images/game_scene/buttons/down_button.png", TEXTURE},
    {"down_hover", "assets/images/game_scene/buttons/hover/"
        "down_button_hover.png", TEXTURE},
    {"flat", "assets/images/game_scene/buttons/flat_button.png", TEXTURE},
    {"flat_hover", "assets/images/game_scene/buttons/hover/"
        "flat_button_hover.png", TEXTURE},
    {"texture_map", "assets/images/game_scene/texture_map.png", TEXTURE},
    {"the_texture", "assets/images/game_scene/the_texture.png", TEXTURE},
    {NULL, NULL, 0},
};

static int create_texture_in_hashtable(engine_t *engine,
    ressource_manager_t *ressource, int asset_index)
{
    sfTexture *texture = sfTexture_createFromFile(
        assets[asset_index].path, NULL);

    if (!texture) {
        engine->state = ERROR;
        return 0;
    }
    ht_insert(ressource->hashtable, assets[asset_index].name, texture);
    return 1;
}

static int create_image_in_hashtable(engine_t *engine,
    ressource_manager_t *ressource, int asset_index)
{
    sfImage *image = sfImage_createFromFile(
        assets[asset_index].path);

    if (!image) {
        engine->state = ERROR;
        return 0;
    }
    ht_insert(ressource->hashtable, assets[asset_index].name, image);
    return 1;
}

static int create_music_in_hashtable(engine_t *engine,
    ressource_manager_t *ressource, int asset_index)
{
    sfMusic *music = sfMusic_createFromFile(
        assets[asset_index].path);

    if (!music) {
        engine->state = ERROR;
        return 0;
    }
    ht_insert(ressource->hashtable, assets[asset_index].name, music);
    return 1;
}

static int create_font_in_hashtable(engine_t *engine,
    ressource_manager_t *ressource, int asset_index)
{
    sfFont *font = sfFont_createFromFile(
        assets[asset_index].path);

    if (!font) {
        engine->state = ERROR;
        return 0;
    }
    ht_insert(ressource->hashtable, assets[asset_index].name, font);
    return 1;
}

ressource_manager_t *create_ressources(engine_t *engine)
{
    int result = 1;
    ressource_manager_t *ressources = malloc(sizeof(ressource_manager_t));
    hashtable_t *hashtable = new_hashtable(&hash, 30);

    if (alloc_error(engine, ressources) || alloc_error(engine, hashtable))
        return NULL;
    ressources->hashtable = hashtable;
    for (int i = 0; assets[i].name; i++) {
        if (assets[i].type == TEXTURE)
            result = create_texture_in_hashtable(engine, ressources, i);
        if (assets[i].type == MUSIC)
            result = create_music_in_hashtable(engine, ressources, i);
        if (assets[i].type == FONT)
            result = create_font_in_hashtable(engine, ressources, i);
        if (assets[i].type == IMAGE)
            result = create_image_in_hashtable(engine, ressources, i);
        if (!result)
            return ressources;
    }
    return ressources;
}

void destroy_ressources(ressource_manager_t *ressources)
{
    hashtable_t *table = NULL;

    if (!ressources)
        return;
    table = ressources->hashtable;
    for (int i = 0; assets[i].name; i++) {
        if (assets[i].type == TEXTURE)
            ht_delete(table, assets[i].name, CAST_VOID(sfTexture_destroy));
        if (assets[i].type == MUSIC)
            ht_delete(table, assets[i].name, CAST_VOID(sfMusic_destroy));
        if (assets[i].type == FONT)
            ht_delete(table, assets[i].name, CAST_VOID(sfFont_destroy));
        if (assets[i].type == IMAGE)
            ht_delete(table, assets[i].name, CAST_VOID(sfImage_destroy));
    }
    delete_hashtable(table);
}
