/*
** EPITECH PROJECT, 2023
** check
** File description:
** check
*/

#include "client_cmd.h"
#include "macros.h"
#include "gui_cmd.h"

bool check_incantation(const inventory_t *mandatory,
const inventory_t *ressource)
{
    return ressource->linemate >= mandatory->linemate &&
ressource->deraumere >= mandatory->deraumere &&
ressource->sibur >= mandatory->sibur &&
ressource->mendiane >= mandatory->mendiane &&
ressource->phiras >= mandatory->phiras &&
ressource->thystame >= mandatory->thystame;
}

int inc_check_var(int fd, serv_t *serv)
{
    client_t *client = get_client_by_fd(serv->clients, fd, serv->max_clients);
    inventory_t mandatory;
    inventory_t current_tile;

    if (client == NULL)
        return ERROR;
    mandatory = get_mandatory_lvl(client->level + 1);
    if (mandatory.food == -1)
        return ERROR;
    if (client->pos.x > serv->param->width || client->pos.x < 0)
        return ERROR;
    else if (client->pos.y > serv->param->width || client->pos.y < 0)
        return ERROR;
    current_tile = get_tile_ressources(client->pos, serv->map);
    if (current_tile.food == -1)
        return ERROR;
    return SUCCESS;
}
