/*
** EPITECH PROJECT, 2023
** Singleton
** File description:
** Singleton
*/

#include "macros.h"
#include "my_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "player.h"
#include "gui_cmd.h"

int is_fd_open(int fd)
{
    return fcntl(fd, F_GETFD) != -1 || errno != EBADF;
}

void send_dead_client(serv_t *serv)
{
    client_t *clients = serv->clients;
    int gui_fd = get_gui_fd(clients, serv->max_clients);

    if (clients == NULL)
        return;
    for (size_t i = 0; i < serv->max_clients; i++) {
        if (clients[i].fd == -1)
            continue;
        if (clients[i].client_type == GRAPHIC)
            smg(serv, "Server down");
        else
            send_message(clients[i].fd, SERV_DEAD, "dead_client");
        kill_this_client(&clients[i], &serv->sets, gui_fd);

    }
}

bool get_singleton(bool mode)
{
    static bool status = true;

    if (mode)
        status = !status;
    return status;
}

void handle_signint(int sig)
{
    (void)sig;
    get_singleton(true);
    printf("server shutdown\n");
}
