/*
** EPITECH PROJECT, 2023
** pwd
** File description:
** pnw
*/

#include "client_cmd.h"
#include "player.h"
#include "my_server.h"
#include "macros.h"
#include <stdio.h>
#include <stdlib.h>

int get_gui_fd(client_t *clients, size_t max_clients)
{
    for (size_t i = 0; i < max_clients; i++) {
        if (clients[i].fd != -1 && clients[i].client_type == GRAPHIC)
            return clients[i].fd;
    }
    return -1;
}

void pnw_client(serv_t *serv, int client_socket)
{
    int graphic_fd = get_gui_fd(serv->clients, serv->max_clients);

    for (size_t i = 0; i < serv->max_clients; i++) {
        if (serv->clients[i].fd == client_socket)
            pnw(serv->clients[i], graphic_fd, client_socket, serv->param);
    }
}

static void pnw_gui(serv_t *serv, int gui_fd)
{
    for (size_t i = 0; i < serv->max_clients; i++) {
        if (serv->clients[i].fd != -1 &&
        serv->clients[i].client_type != GRAPHIC)
            pnw(serv->clients[i], gui_fd, serv->clients[i].fd, serv->param);
    }
}

void pnw(client_t clt, int gui, int socket, params_t *param)
{
    char command[100];
    char *team_name = get_team_name(clt.team_index, param);

    if (team_name == NULL) {
        team_name = malloc(sizeof(char) * 6);
        strcpy(team_name, "error");
    }
    snprintf(command, sizeof(command), "pnw %d %d %d %d %d %s\n",
        socket, clt.pos.x, clt.pos.y, clt.orientation, clt.level, team_name);

    send_message(gui, command, "pnw");
    if (strcmp(team_name, "error") == 0)
        free(team_name);
}

void send_pnw(serv_t *serv, int client_socket, char *team)
{
    if (strcmp(team, "GRAPHIC") == SUCCESS)
        pnw_gui(serv, client_socket);
    else
        pnw_client(serv, client_socket);
}
