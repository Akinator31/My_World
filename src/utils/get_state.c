/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** get_state
*/

#include "utils.h"

sfRenderStates get_state(engine_t *engine)
{
    if (engine->is_strange_mode) {
        return (sfRenderStates){
            sfBlendAlpha, sfTransform_Identity,
            GET_RES("the_texture"), NULL
        };
    } else {
        return (sfRenderStates){
            sfBlendAlpha, sfTransform_Identity,
            GET_RES("texture_map"), NULL
        };
    }
}
