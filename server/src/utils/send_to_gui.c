/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** incantation
*/

#include "my_server.h"
#include "player.h"
#include <string.h>

void send_to_gui(serv_t *serv, char *message)
{
    client_t *clients = serv->clients;

    for (size_t i = 0; i < serv->max_clients; ++i) {
        if (clients[i].fd != -1 && clients[i].client_type == GRAPHIC)
            send_message(clients[i].fd, message, "gui_incantation_cmd");
    }
}
