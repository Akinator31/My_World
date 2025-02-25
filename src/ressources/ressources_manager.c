/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** ressources_manager
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "my_world.h"
#include "structure.h"
#include "hashtable.h"
#include "ressources.h"

static const assets_t assets[] = {
    {"background", "assets/images/main_menu/bg.png", IMAGE},
    {"start_button", "assets/images/main_menu/buttons/start_button.png",
        IMAGE},
    {"start_button_hover", "assets/images/main_menu/buttons/hover/"
        "start_button_hover.png", IMAGE},
    {"quit_button", "assets/images/main_menu/buttons/quit_button.png", IMAGE},
    {"quit_button_hover", "assets/images/main_menu/buttons/hover/"
        "quit_button_hover.png", IMAGE},
    {"settings_button", "assets/images/main_menu/buttons/"
        "settings_button.png", IMAGE},
    {"settings_button_hover", "assets/images/main_menu/buttons/hover/"
        "settings_button_hover.png", IMAGE},
    {"sound_on", "assets/images/settings_menu/buttons/sound_on.png", IMAGE},
    {"sound_on_hover", "assets/images/settings_menu/buttons/hover/"
        "sound_on_hover.png", IMAGE},
    {"sound_off", "assets/images/settings_menu/buttons/sound_off.png", IMAGE},
    {"sound_off_hover", "assets/images/settings_menu/buttons/hover/"
        "sound_off_hover.png", IMAGE},
    {"back", "assets/images/settings_menu/buttons/back_button.png", IMAGE},
    {"back_hover", "assets/images/settings_menu/buttons/hover/"
        "back_button_hover.png", IMAGE},
    {"settings_bg", "assets/images/settings_menu/settings_bg.png", IMAGE},
    {"900", "assets/images/settings_menu/buttons/900.png", IMAGE},
    {"1920", "assets/images/settings_menu/buttons/1920.png", IMAGE},
    {"4k", "assets/images/settings_menu/buttons/4k.png", IMAGE},
    {"900_hover", "assets/images/settings_menu/buttons/hover/"
        "900_hover.png", IMAGE},
    {"1920_hover", "assets/images/settings_menu/buttons/hover/"
        "1920_hover.png", IMAGE},
    {"4k_hover", "assets/images/settings_menu/buttons/hover/"
        "4k_hover.png", IMAGE},
    {"game_bg", "assets/images/game_scene/game_bg.png", IMAGE},
    {"pause", "assets/images/game_scene/buttons/pause.png", IMAGE},
    {"pause_hover", "assets/images/game_scene/buttons/hover/"
        "pause_hover.png", IMAGE},
    {"play", "assets/images/game_scene/buttons/play.png", IMAGE},
    {"play_hover", "assets/images/game_scene/buttons/hover/"
        "play_hover.png", IMAGE},
    {"chicken_sprite_sheet_1", "assets/images/game_scene/"
        "chicken_sprite_sheet_1.png", IMAGE},
    {"menu_music", "assets/sounds/menu-music.ogg", MUSIC},
    {"game_music", "assets/sounds/game-music.ogg", MUSIC},
    {"BungeeSpice_Regular", "assets/fonts/BungeeSpice-Regular.ttf", FONT},
    {"button_10", "assets/images/creat_map_menu/buttons/10.png", IMAGE},
    {"button_10_hover", "assets/images/creat_map_menu/"
        "buttons/hover/10_hover.png", IMAGE},
    {"button_50", "assets/images/creat_map_menu/buttons/50.png", IMAGE},
    {"button_50_hover", "assets/images/creat_map_menu/"
        "buttons/hover/50_hover.png", IMAGE},
    {"button_100", "assets/images/creat_map_menu/buttons/100.png", IMAGE},
    {"button_100_hover", "assets/images/creat_map_menu/"
        "buttons/hover/100_hover.png", IMAGE},
    {"button_load", "assets/images/creat_map_menu/buttons/load.png", IMAGE},
    {"button_load_hover", "assets/images/creat_map_menu/"
        "buttons/hover/load_hover.png", IMAGE},
    {NULL, NULL, 0},
};

ressource_manager_t *create_ressources(void)
{
    ressource_manager_t *ressources = malloc(sizeof(ressource_manager_t));

    ressources->hashtable = new_hashtable(&hash, 30);
    for (int i = 0; assets[i].name; i++) {
        switch (assets[i].type) {
        case IMAGE:
            ht_insert(ressources->hashtable, assets[i].name, TX_CREATE(i));
            break;
        case MUSIC:
            ht_insert(ressources->hashtable, assets[i].name, MUSIC_CREATE(i));
            break;
        case FONT:
            ht_insert(ressources->hashtable, assets[i].name, FONT_CREATE(i));
            break;
        default:
            break;
        }
    }
    return ressources;
}

void destroy_ressources(ressource_manager_t *ressources)
{
    hashtable_t *table = ressources->hashtable;

    for (int i = 0; assets[i].name; i++) {
        switch (assets[i].type) {
        case IMAGE:
            ht_delete(table, assets[i].name, CAST_VOID(sfTexture_destroy));
            break;
        case MUSIC:
            ht_delete(table, assets[i].name, CAST_VOID(sfMusic_destroy));
            break;
        case FONT:
            ht_delete(table, assets[i].name, CAST_VOID(sfFont_destroy));
        default:
            break;
        }
    }
    delete_hashtable(table);
}
