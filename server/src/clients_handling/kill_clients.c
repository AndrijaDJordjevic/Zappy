/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** kill_clients
*/

#include "my_server.h"
#include "player.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void clear_sets(sets_t *set, int fd)
{
    FD_CLR(fd, &set->master_read_fds);
    FD_CLR(fd, &set->master_write_fds);
    FD_CLR(fd, &set->master_except_fds);
    FD_CLR(fd, &set->working_read_fds);
    FD_CLR(fd, &set->working_write_fds);
    FD_CLR(fd, &set->working_except_fds);
}

void close_client(client_t *client, sets_t *set)
{
        close(client->fd);
        clear_sets(set, client->fd);
        client->fd = -1;
}

void kill_this_client(client_t *client, sets_t *set, int gui_fd)
{
    char msg[32] = {0};
    int fd = client->fd;

    if (client == NULL || client->fd == -1)
        return;
    if (client->client_type == GRAPHIC) {
        printf("Graphic client %d disconnected\n", client->fd);
        close_client(client, set);
        return;
    } else if (fcntl(client->fd, F_GETFD) != -1) {
        send_message(client->fd, "DEAD", "kill_this_client");
    }
    free_cmd_queue(&client->client_cmd_queue);
    if (gui_fd != -1) {
        snprintf(msg, 32, "pdi %d", client->fd);
        send_message(gui_fd, msg, "kill_this_client to gui");
    }
    printf("Client %d disconnected\n", fd);
}

void kill_clients(client_t *clients, size_t max_clients, sets_t *set)
{
    int gui_fd = -1;
    for (size_t i = 0; i < max_clients; i++)
        if (clients[i].client_type == GRAPHIC)
            gui_fd = clients[i].fd;
    for (size_t i = 0; i < max_clients; i++) {
        if (clients[i].fd != -1)
            kill_this_client(&clients[i], set, gui_fd);
    }
    free(clients);
}
