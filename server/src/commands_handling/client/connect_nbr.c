/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** connect_nbr
*/
#include "client_cmd.h"
#include "macros.h"
#include "my_server.h"

void connect_nbr_command(int client_socket, serv_t *serv, char **args)
{
    client_t *current_client = get_client_by_fd(serv->clients,
        client_socket, serv->max_clients);
    int team_index = current_client->team_index;
    int team_slot = 0;
    char msg[128] = "";

    if (current_client == NULL)
        return;
    (void) args;
    team_slot = (serv->param->clients +
    count_eggs_in_team((const egg_t**)serv->eggs, team_index)) -
    get_nbr_team(serv->clients, team_index, serv->max_clients);
    snprintf(msg, 128, "%d\n", team_slot);
    send_message(client_socket, msg, "connect_nbr");
}
