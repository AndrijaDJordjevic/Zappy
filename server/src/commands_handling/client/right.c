/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** right
*/

#include "macros.h"
#include "client_cmd.h"

void right_command(int client_socket, serv_t *serv, char **args)
{
    client_t *client = get_client_by_fd(serv->clients, client_socket,
    serv->max_clients);

    if (client == NULL)
        return;

    if (client->orientation == W)
        client->orientation = N;
    else
        client->orientation += 1;

    send_message(client_socket, SERV_OK, "right_cmd");
    (void)args;
}
