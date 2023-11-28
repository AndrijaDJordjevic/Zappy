/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** handle_new_connection
*/

#include "my_server.h"
#include "player.h"
#include "macros.h"
#include <unistd.h>

int handle_new_connection(serv_t *server)
{
    int client_socket = accept(server->tcp_socket, NULL, 0);

    if (client_socket == -1) {
        perror("accept");
        close(server->tcp_socket);
        return ERROR;
    }
    FD_SET(client_socket, &server->sets.master_read_fds);
    FD_SET(client_socket, &server->sets.master_write_fds);
    FD_SET(client_socket, &server->sets.master_except_fds);
    if (client_socket > server->max_fd)
        server->max_fd = client_socket;

    printf("New client connected, socket fd is %d\n", client_socket);

    send_message(client_socket, SERV_WELCOME, "handle_new_connection");

    server->clients = new_client(server->clients, server, client_socket);

    return 0;
}
