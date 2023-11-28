/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** incantation
*/
#include <stdio.h>
#include "my_server.h"
#include "player.h"
#include "macros.h"

void pie(serv_t *serv, position_t pos, bool status)
{
    char buffer[MAX_BUFF];

    if (status)
        sprintf(buffer, "pie %d %d ok\n", pos.x, pos.y);
    else
        sprintf(buffer, "pie %d %d ko\n", pos.x, pos.y);
    send_to_gui(serv, buffer);
}
