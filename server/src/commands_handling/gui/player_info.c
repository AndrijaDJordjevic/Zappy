/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** player_info
*/
#include <stdlib.h>
#include <stdio.h>
#include "my_server.h"
#include "player.h"
#include "macros.h"
#include "client_cmd.h"

void player_inventory(int fd, serv_t *serv, char **args)
{
    char buffer[MAX_BUFF];
    int player_id = -1;
    int len = my_strlen_2d(args);
    client_t *client;

    if (len != 2 || (player_id = atoi(args[1])) <= 0) {
        dprintf(fd, "sbp\n");
        return;
    }
    client = get_client_by_fd(serv->clients, fd, serv->max_clients);
    if (client == NULL) {
        send(fd, SERV_KO, strlen(SERV_KO), 0);
        return;
    }
    sprintf(buffer, "pin %d %d %d %d %d %d %d %d %d %d\n", player_id,
    client->pos.x, client->pos.y, client->inventory.food,
    client->inventory.linemate, client->inventory.deraumere,
    client->inventory.sibur, client->inventory.mendiane,
    client->inventory.phiras, client->inventory.thystame);
    send_message(fd, buffer, "player_inventory");
}

void player_level(int fd, serv_t *serv, char **args)
{
    char buffer[MAX_BUFF];
    int player_id = -1;
    client_t *client;
    int len = my_strlen_2d(args);

    if (len != 2 || (player_id = atoi(args[1])) <= 0) {
        dprintf(fd, "sbp\n");
        return;
    }
    client = get_client_by_fd(serv->clients, fd, serv->max_clients);
    if (client == NULL) {
        send(fd, SERV_KO, strlen(SERV_KO), 0);
        return;
    }
    sprintf(buffer, "plv %d %d\n", player_id, client->level);
    send_message(fd, buffer, "player_level");
}

void player_position(int fd, serv_t *serv, char **args)
{
    char buffer[MAX_BUFF];
    int player_id = -1;
    client_t *client;
    int len = my_strlen_2d(args);

    if (len != 2 || (player_id = atoi(args[1])) <= 0) {
        dprintf(fd, "sbp\n");
        return;
    }
    client = get_client_by_fd(serv->clients, player_id, serv->max_clients);
    if (client == NULL) {
        send(fd, SERV_KO, strlen(SERV_KO), 0);
        return;
    }
    sprintf(buffer, "ppo %d %d %d %d\n", player_id, client->pos.x,
    client->pos.y, client->orientation);
    send_message(fd, buffer, "player_position");
}
