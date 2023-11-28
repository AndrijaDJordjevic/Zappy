/*
** EPITECH PROJECT, 2023
** lvl
** File description:
** lvl
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_server.h"
#include "player.h"
#include "macros.h"
#include "client_cmd.h"
#include "gui_cmd.h"

inventory_t get_mandatory_lvl2(void)
{
    const inventory_t mandatory = {
        .food = 0,
        .linemate = 1,
        .deraumere = 0,
        .sibur = 0,
        .mendiane = 0,
        .phiras = 0,
        .thystame = 0
    };
    return mandatory;
}

static void message_pic(char *error, int fd, client_t *client, serv_t* serv)
{
    char message[MAX_BUFF];

    sprintf(message, "pic %i %i %i\n", client->pos.x, client->pos.y,
    fd);
    send_message(get_gui_fd(serv->clients, serv->max_clients), message, error);
}

static void send_ko_inc(serv_t *serv, int fd, char *error, client_t *client)
{
    send_message(fd, SERV_KO, error);
    pie(serv, client->pos, false);
}

void incan_lvl_2(serv_t* serv, int fd)
{
    client_t *client = get_client_by_fd(serv->clients, fd, serv->max_clients);
    inventory_t mandatory = get_mandatory_lvl2();
    inventory_t current_tile = get_tile_ressources(client->pos, serv->map);
    char *error = "Incantation lvl2";

    message_pic(error, fd, client, serv);
    if (check_incantation(&mandatory, &current_tile)) {
        current_tile = get_tile_ressources(client->pos, serv->map);
        if (check_incantation(&mandatory, &current_tile)) {
            remove_ressource_incantation(serv->map, client->pos, mandatory);
            pie(serv, client->pos, true);
            client->level++;
            message_elevation(error, fd, client);
        } else
            send_ko_inc(serv, fd, error, client);
    } else
        send_ko_inc(serv, fd, error, client);
}
