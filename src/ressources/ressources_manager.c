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

static const char *assets[] = {
    "assets/images/main_menu/bg.png",
    "assets/images/main_menu/buttons/start_button.png",
    "assets/images/main_menu/buttons/hover/start_button_hover.png",
    "assets/images/main_menu/buttons/quit_button.png",
    "assets/images/main_menu/buttons/hover/quit_button_hover.png",
    "assets/images/main_menu/buttons/settings_button.png",
    "assets/images/main_menu/buttons/hover/settings_button_hover.png",
    "assets/images/settings_menu/buttons/sound_on.png",
    "assets/images/settings_menu/buttons/hover/sound_on_hover.png",
    "assets/images/settings_menu/buttons/sound_off.png",
    "assets/images/settings_menu/buttons/hover/sound_off_hover.png",
    "assets/images/settings_menu/buttons/back_button.png",
    "assets/images/settings_menu/buttons/hover/back_button_hover.png",
    "assets/images/settings_menu/settings_bg.png",
    "assets/images/settings_menu/buttons/900.png",
    "assets/images/settings_menu/buttons/1920.png",
    "assets/images/settings_menu/buttons/4k.png",
    "assets/images/settings_menu/buttons/hover/900_hover.png",
    "assets/images/settings_menu/buttons/hover/1920_hover.png",
    "assets/images/settings_menu/buttons/hover/4k_hover.png",
    "assets/images/game_scene/game_bg.png",
    "assets/images/game_scene/buttons/pause.png",
    "assets/images/game_scene/buttons/hover/pause_hover.png",
    "assets/images/game_scene/buttons/play.png",
    "assets/images/game_scene/buttons/hover/play_hover.png",
    "assets/images/game_scene/chicken_sprite_sheet_1.png",
    "assets/sounds/menu-music.ogg",
    "assets/sounds/game-music.ogg",
    "assets/fonts/BungeeSpice-Regular.ttf"
};

void destroy_secondary_ressources(ressource_manager_t *ressources)
{
    sfTexture_destroy(ressources->res_900);
    sfTexture_destroy(ressources->res_1920);
    sfTexture_destroy(ressources->res_4k);
    sfTexture_destroy(ressources->res_900_hover);
    sfTexture_destroy(ressources->res_1920_hover);
    sfTexture_destroy(ressources->res_4k_hover);
    sfTexture_destroy(ressources->game_background);
    sfTexture_destroy(ressources->pause_button);
    sfTexture_destroy(ressources->pause_button_hover);
    sfTexture_destroy(ressources->resume_button);
    sfTexture_destroy(ressources->resume_button_hover);
    sfTexture_destroy(ressources->chicken);
    sfFont_destroy(ressources->font);
}

void destroy_ressources(ressource_manager_t *ressources)
{
    sfTexture_destroy(ressources->background);
    sfTexture_destroy(ressources->play_button);
    sfTexture_destroy(ressources->play_button_hover);
    sfTexture_destroy(ressources->quit_button);
    sfTexture_destroy(ressources->quit_button_hover);
    sfTexture_destroy(ressources->settings_button);
    sfTexture_destroy(ressources->settings_button_hover);
    sfTexture_destroy(ressources->sound_on_button);
    sfTexture_destroy(ressources->sound_off_button);
    sfTexture_destroy(ressources->sound_on_button_hover);
    sfTexture_destroy(ressources->sound_off_button_hover);
    sfTexture_destroy(ressources->back_button);
    sfTexture_destroy(ressources->back_button_hover);
    sfTexture_destroy(ressources->settings_background);
    sfMusic_destroy(ressources->menu_music);
    sfMusic_destroy(ressources->game_music);
    destroy_secondary_ressources(ressources);
}

void create_secondary_ressources(ressource_manager_t *ressources)
{
    TX_CREATE(ressources->res_900, 14);
    TX_CREATE(ressources->res_1920, 15);
    TX_CREATE(ressources->res_4k, 16);
    TX_CREATE(ressources->res_900_hover, 17);
    TX_CREATE(ressources->res_1920_hover, 18);
    TX_CREATE(ressources->res_4k_hover, 19);
    TX_CREATE(ressources->game_background, 20);
    TX_CREATE(ressources->pause_button, 21);
    TX_CREATE(ressources->pause_button_hover, 22);
    TX_CREATE(ressources->resume_button, 23);
    TX_CREATE(ressources->resume_button_hover, 24);
    TX_CREATE(ressources->chicken, 25);
    MUSIC_CREATE(ressources->menu_music, 26);
    MUSIC_CREATE(ressources->game_music, 27);
    ressources->font = sfFont_createFromFile(assets[28]);
}

ressource_manager_t *create_ressources(void)
{
    ressource_manager_t *ressources = malloc(sizeof(ressource_manager_t));

    TX_CREATE(ressources->background, 0);
    TX_CREATE(ressources->play_button, 1);
    TX_CREATE(ressources->play_button_hover, 2);
    TX_CREATE(ressources->quit_button, 3);
    TX_CREATE(ressources->quit_button_hover, 4);
    TX_CREATE(ressources->settings_button, 5);
    TX_CREATE(ressources->settings_button_hover, 6);
    TX_CREATE(ressources->sound_on_button, 7);
    TX_CREATE(ressources->sound_on_button_hover, 8);
    TX_CREATE(ressources->sound_off_button, 9);
    TX_CREATE(ressources->sound_off_button_hover, 10);
    TX_CREATE(ressources->back_button, 11);
    TX_CREATE(ressources->back_button_hover, 12);
    TX_CREATE(ressources->settings_background, 13);
    create_secondary_ressources(ressources);
    ressources->destroy_ressources = &destroy_ressources;
    return ressources;
}
