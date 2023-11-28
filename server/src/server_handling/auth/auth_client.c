/*
** EPITECH PROJECT, 2023
** gui
** File description:
** gui
*/

#include "client_cmd.h"
#include "player.h"
#include "my_server.h"
#include "macros.h"
#include <stdlib.h>
#include <stdio.h>

void send_team_infos(int client_socket, serv_t *serv, int team_index)
{
    char buffer[MAX_BUFF] = {0};
    int width = serv->param->width;
    int height = serv->param->height;
    int remain_team = (serv->param->clients +
    count_eggs_in_team((const egg_t**)serv->eggs, team_index)) -
    get_nbr_team(serv->clients, team_index, serv->max_clients);

    if (get_client_by_fd(serv->clients, client_socket,
    serv->max_clients)->client_type == GRAPHIC)
        remain_team = 0;

    sprintf(buffer, "%d\n%d %d\n", remain_team, width, height);
    send_message(client_socket, buffer, "send_team_infos");
}

static void handle_auth_case(serv_t *serv, int client_socket, int team_index,
client_t *current_client)
{
    current_client->team_index = team_index;
    send_team_infos(client_socket, serv, team_index);
}

static void add_client_team_type(char *team_name, client_t *current_client)
{
    if (strcmp(team_name, "GRAPHIC") == 0)
        current_client->client_type = GRAPHIC;
    else
        current_client->client_type = PLAYER;
}

static void connect_team_or_egg(serv_t* serv, int client_socket, char *team,
client_t *current_client)
{
    int team_index = get_team_index(serv->param, team);
    int cal = serv->param->clients - get_nbr_team(serv->clients, team_index,
    serv->max_clients);

    if (cal == 0) {
        handle_auth_case_egg(serv, client_socket, team, current_client);
    } else {
        add_client_team_type(serv->param->names[team_index], current_client);
        handle_auth_case(serv, client_socket, team_index, current_client);
        send_pnw(serv, client_socket, team);
        printf("player connected to team %s\n", team);
    }
}

int check_client_auth(serv_t *serv, int client_socket, char *team)
{
    client_t *current_client = get_client_by_fd(serv->clients, client_socket,
    serv->max_clients);
    int team_index = 0;
    int remaining_slots = serv->param->clients;


    if (current_client->team_index == -1 && current_client != NULL) {
        team_index = get_team_index(serv->param, team);
        if (team_index == -1)
            return ERROR;
        remaining_slots += count_eggs_in_team((const egg_t**) serv->eggs,
        team_index) - get_nbr_team(serv->clients, team_index,
        serv->max_clients);
        if (remaining_slots >= 1) {
            connect_team_or_egg(serv, client_socket, team, current_client);
            return AUTH;
        }
        return ERROR;
    }
    return SUCCESS;
}
