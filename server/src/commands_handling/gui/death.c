/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** death
*/

#include "macros.h"
#include "client_cmd.h"
#include "player.h"
#include "my_server.h"
#include <stdlib.h>

void player_death(int fd, serv_t *serv, char **args)
{
    client_t *client = get_client_by_fd(serv->clients, fd, serv->max_clients);
    char msg[BUFSIZ] = {0};

    if (client == NULL) {
        send_message(fd, "ko\n", "death");
        return;
    }
    kill_this_client(client, &serv->sets, get_gui_fd(serv->clients,
        serv->max_clients));
    snprintf(msg, BUFSIZ, "pdi %d\n", fd);
    send_message(fd, msg, "pdi");
    (void) args;
}

int get_winning_team(client_t *clients, int team_id, serv_t *serv)
{
    client_t *team = get_client_by_team(clients, team_id, serv);

    for (int i = 0; team[i].fd != -2; i++) {
        if (team[i].fd == -1)
            continue;
        if (team[i].level != 8)
            return -1;
    }
    free(team);
    return team_id;
}

bool has_team_win(client_t *clients, char *team_name, serv_t *serv,
    int *team_id)
{
    int winning_team = -1;

    for (int i = 0; serv->param->names[i]; i++) {
        winning_team = get_winning_team(clients, i, serv);
        if (winning_team != -1) {
            *team_id = winning_team;
            strcpy(team_name, serv->param->names[i]);
            return true;
        }
    }
    return false;
}

void team_end_of_game(int fd, serv_t *serv, char **args)
{
    char msg[BUFSIZ] = {0};
    char team_name[MAX_BUFF] = {0};
    int team_id = -1;

    if (has_team_win(serv->clients, team_name, serv, &team_id)) {
        snprintf(msg, BUFSIZ, "seg %s\n", serv->param->names[team_id]);
        send_message(fd, msg, "seg");
    } else {
        send_message(fd, "suc\n", "seg");
    }
    (void) args;
    (void) serv;
}
