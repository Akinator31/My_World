/*
** EPITECH PROJECT, 2025
** G-ING-200-TLS-2-1-myworld-pavel.de-wavrechin
** File description:
** help_display
*/

#include <unistd.h>
#include "structure.h"
#include "my_lib.h"
#include "utils.h"

static const char *help_message =
    "=============================\n"
    "       PAVEL WORLD       \n"
    "=============================\n"
    "\n"
    "DESCRIPTION:\n"
    "  In PAVEL WORLD, you are Pavel the leader of this world.\n"
    "  You can do everything you want because Pavel is the suprem leader.\n"
    "  Pavel is watching you!\n"
    "\n"
    "USAGE:\n"
    "  ./my_world\n"
    "\n"
    "OPTIONS:\n"
    "  -h      Show this help message.\n"
    "\n"
    "CONTROLS:\n"
    "  Mouse   Aim.\n"
    "  Up      move map up.\n"
    "  Down    move map down.\n"
    "  Left    move map left.\n"
    "  Right   move map right.\n"
    "  P       zoom in.\n"
    "  M       zoom out.\n""  A       rotate up.\n"
    "  E       rotate down.\n""  Z       up element.\n"
    "  S       down element.\n""  F       flatting elements.\n"
    "  Q       quit.\n"
    "\nPS :The hash function is made by Alexy (but didn't work well)\n"
    "\n"
    "GOOD LUCK!\n";

int help(int ac, char **av)
{
    if ((ac > 2) || (my_strcmp(av[1], "-h") != 0)) {
        return 84;
    }
    write(1, help_message, my_strlen(help_message) + 1);
    return 0;
}
