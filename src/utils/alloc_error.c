/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** alloc_error
*/

#include <unistd.h>
#include "engine.h"
#include "utils.h"

int alloc_error(engine_t *engine, void *data)
{
    if (!data) {
        write(2, "A problem occurred during memory allocation\n", 45);
        engine->state = ERROR;
        return 1;
    }
    return 0;
}
