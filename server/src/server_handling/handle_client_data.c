/*
** EPITECH PROJECT, 2023
** client
** File description:
** client
*/

#include "macros.h"
#include "my_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char *decode_bytes(const unsigned char *bytes, size_t length)
{
    char *decoded_string = (char *)malloc((length + 1) * sizeof(char));

    if (decoded_string == NULL)
        return NULL;
    memcpy(decoded_string, bytes, length);
    decoded_string[length] = '\0';
    return decoded_string;
}

static bool is_client_dead(serv_t *serv, int client_socket)
{
    client_t *client = get_client_by_fd(serv->clients, client_socket,
        serv->max_clients);

    if (client == NULL)
        return true;
    if (client->fd == -1) {
        return true;
    }
    return false;
}

void handle_client_data(serv_t *serv, int client_socket)
{
    char buffer[MAX_BUFF];
    int count = read(client_socket, buffer, sizeof(buffer) - 1);
    char *decoded_string = NULL;
    int gui_fd = get_gui_fd(serv->clients, serv->max_clients);
    client_t *client = get_client_by_fd(serv->clients,
    client_socket, serv->max_clients);

    if (is_client_dead(serv, client_socket) || count <= 0) {
        return;
    }
    buffer[count] = '\0';
    decoded_string = decode_bytes((const unsigned char*)buffer, count);
    if (decoded_string == NULL) {
        kill_this_client(client, &serv->sets, gui_fd);
        return;
    }
    handle_client_commands(client_socket, decoded_string, serv);
    free(decoded_string);
}
