/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** ressources
*/

#ifndef INCLUDED_RESSOURCES_H
    #define INCLUDED_RESSOURCES_H
    #include "my_world.h"
    #include "structure.h"
    #define CAST_VOID(f) (void (*)(void *)) f

ressource_manager_t *create_ressources(void);
void destroy_ressources(ressource_manager_t *ressources);

#endif
