/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** eject
*/

#include "macros.h"
#include "client_cmd.h"
#include "client_cmd_macros.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char get_orientation_by_enum(enum orientation orientation)
{
    switch (orientation) {
    case N:
        return ('N');
    case E:
        return ('E');
    case S:
        return ('S');
    case W:
        return ('W');
    }
    return ('R');
}

static void handle_player_pos(position_t *ejected, params_t *param,
client_t *client, char *msg)
{
    char *tmp = NULL;

    if (!CHECK_POS(ejected->x, ejected->y, client->pos.x, client->pos.y))
        return;
    tmp = strdup(msg);
    move_player_forward(client->orientation, ejected, param->width,
    param->height);
    free(tmp);
}

void eject_players(client_t *client, int fd, serv_t *serv)
{
    char const orientation = get_orientation_by_enum(client->orientation);
    char msg[MAX_BUFF] = "";
    int gui_fd = get_gui_fd(serv->clients, serv->max_clients);
    if (orientation == 'R' || client == NULL)
        return;
    snprintf(msg, MAX_BUFF, "eject: %c\n", orientation);

    for (size_t i = 0; i < serv->max_clients; i++) {
        if (serv->clients[i].fd == -1 || serv->clients[i].fd == fd ||
        serv->clients[i].fd == gui_fd)
            continue;
        else {
            handle_player_pos(&serv->clients[i].pos, serv->param, client, msg);
        }
    }
}

static void edi(int gui, int egg_id)
{
    char command[100];

    snprintf(command, sizeof(command), "edi %d\n", egg_id);
    send_message(gui, command, "edi");
    printf("%s", command);
}

void eject_command(int client_socket, serv_t *serv, char **args)
{
    client_t *client = get_client_by_fd(serv->clients, client_socket,
    serv->max_clients);
    char gui_command[MAX_BUFF];
    int gui_fd = get_gui_fd(serv->clients, serv->max_clients);
    int res = 0;

    if (client == NULL)
        return;
    sprintf(gui_command, "pex %d\n", client_socket);
    eject_players(client, client_socket, serv);
    send_message(client_socket, SERV_OK, "eject");
    send_message(gui_fd, gui_command, "pex");
    while (res != -1) {
        res = remove_egg_position(serv->eggs, client->pos.x,
        client->pos.y);
        if (res != -1)
            edi(get_gui_fd(serv->clients, serv->max_clients), res);
    }
    (void)args;
}
