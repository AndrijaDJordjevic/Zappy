/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** broadcast gui
*/

#include "macros.h"
#include "client_cmd.h"
#include "player.h"

void broadcast_msg(int fd, serv_t *serv, char **args)
{
    char msg[BUFSIZ];
    unsigned int args_len = my_strlen_2d(args);
    client_t *client;
    int serv_gui_fd = get_gui_fd(serv->clients, serv->max_clients);

    if (args_len != 2 || serv_gui_fd == -1) {
        send_message(fd, "sbp\n", "broadcast_msg");
        return;
    }
    client = get_client_by_fd(serv->clients, fd, serv->max_clients);
    if (client == NULL) {
        send_message(fd, "Error: player not found\n", "broadcast_msg");
        return;
    }
    snprintf(msg, BUFSIZ, "pbc %d %s\n", fd, args[2]);

    send_message(serv_gui_fd, msg, "broadcast_msg");
}
