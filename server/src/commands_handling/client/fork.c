/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** fork
*/

#include "macros.h"
#include "client_cmd.h"
#include "my_server.h"
#include <stdio.h>

static void enw(int gui, int client_socket, int egg_id, position_t pos)
{
    char command[100];

    if (egg_id == -1 || gui == -1 || client_socket == -1)
        return;
    snprintf(command, sizeof(command), "enw %d %d %d %d\n",
egg_id, client_socket, pos.x, pos.y);
    send_message(gui, command, "enw");
}

static void pfk(int gui, int fd)
{
    char command[100];

    if (fd == -1 || gui == -1)
        return;

    snprintf(command, sizeof(command), "pfk %d\n", fd);
    send_message(gui, command, "pfk");
}

void fork_command(int client_socket, serv_t *serv, char **args)
{
    client_t *client = get_client_by_fd(serv->clients, client_socket,
    serv->max_clients);
    position_t pos = client->pos;
    int res = 0;
    int gui = get_gui_fd(serv->clients, serv->max_clients);

    if (client == NULL) {
        send_message(client_socket, SERV_KO, "fork_cmd");
        return;
    }
    pfk(gui, client_socket);

    res = add_egg_to_team(&serv->eggs, client->team_index, pos.x, pos.y);
    enw(gui, client_socket, res, client->pos);

    send_message(client_socket, res != -1 ? SERV_OK : SERV_KO, "fork_cmd");
    (void)args;
    return;
}
