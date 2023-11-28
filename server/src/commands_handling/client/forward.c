/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** forward
*/

#include "macros.h"
#include "client_cmd.h"
#include <stdio.h>

void move_player_forward(enum orientation orientation, position_t *pos,
int x, int y)
{
    switch (orientation) {
        case N:
            pos->y = pos->y > 0 ? pos->y - 1 : y - 1;
            break;
        case E:
            pos->x = pos->x < x - 1 ? pos->x + 1 : 0;
            break;
        case S:
            pos->y = pos->y < y - 1 ? pos->y + 1 : 0;
            break;
        case W:
            pos->x = pos->x > 0 ? pos->x - 1 : x - 1;
            break;
        default:
            break;
    };
}

void forward_command(int client_socket, serv_t *serv, char **args)
{
    client_t *client = get_client_by_fd(serv->clients,
    client_socket, serv->max_clients);

    if (client == NULL)
        return;
    move_player_forward(client->orientation,
    &client->pos, serv->param->width, serv->param->height);
    printf("Player %d forward: X: %d, Y: %d\n", client_socket,
    client->pos.x, client->pos.y);
    send_message(client_socket, SERV_OK, "forward_cmd");
    (void)args;
    return;
}
