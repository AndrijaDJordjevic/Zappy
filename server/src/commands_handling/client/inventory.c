/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** inventory
*/

#include "client_cmd.h"
#include "client_cmd_macros.h"
#include "macros.h"

void inventory_command(int client_socket, serv_t *serv, char **args)
{
    client_t *client = get_client_by_fd(serv->clients, client_socket,
    serv->max_clients);
    inventory_t *inventory = &client->inventory;
    char buffer[MAX_BUFF] = {0};

    if (client == NULL) {
        send_message(client_socket, SERV_KO, "inventory_cmd");
        return;
    }

    snprintf(buffer, MAX_BUFF, DISPLAY_INVENTORY, inventory->food,
    inventory->linemate, inventory->deraumere, inventory->sibur,
    inventory->mendiane, inventory->phiras, inventory->thystame);
    printf("Client %d inventory: %s\n", client_socket, buffer);
    dprintf(client_socket, "%s", buffer);

    (void)args;
    return;
}
