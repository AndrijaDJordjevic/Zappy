/*
** EPITECH PROJECT, 2023
** egg
** File description:
** auth
*/

#include "client_cmd.h"
#include "player.h"
#include "my_server.h"
#include "macros.h"
#include <stdlib.h>
#include <stdio.h>

static void ebo(int gui, int egg_id)
{
    char command[100];

    snprintf(command, sizeof(command), "ebo %d\n", egg_id);
    send_message(gui, command, "ebo");
}

void send_pnw_egg(serv_t *serv, int client_socket, char *team)
{
    if (strcmp(team, "GRAPHIC") == SUCCESS)
        return;
    else
        pnw_client(serv, client_socket);
}

void handle_auth_case_egg(serv_t *serv, int client_socket, char *team,
client_t *current_client)
{
    int team_index = get_team_index(serv->param, team);
    egg_t *egg = find_egg(serv->eggs, team_index);

    if (egg == NULL) {
        send_message(client_socket, SERV_KO, "eggs auth");
        return;
    }
    ebo(get_gui_fd(serv->clients, serv->max_clients), egg->id);
    current_client->team_index = team_index;
    add_client_team_egg(current_client, egg->position);
    send_pnw_egg(serv, client_socket, team);
    send_team_infos(client_socket, serv, team_index);
    remove_egg_position(serv->eggs, egg->position.x, egg->position.y);
}

void add_client_team_egg(client_t *current_client, position_t position)
{
    current_client->pos = position;
    return;
}
