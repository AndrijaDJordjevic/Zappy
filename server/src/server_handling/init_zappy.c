/*
** EPITECH PROJECT, 2023
** set connexions
** File description:
** connection
*/

#include "macros.h"
#include "my_server.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

static struct sockaddr_in fill_in_adress(int port)
{
    struct sockaddr_in address = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY,
    };
    return address;
}

static int connection_error(const serv_t *f)
{
    if (f->tcp_socket == -1) {
        perror("socket");
        return ERROR;
    }
    if (bind(f->tcp_socket, (struct sockaddr *)&f->address,
    sizeof(f->address)) != SUCCESS) {
        perror("bind");
        close(f->tcp_socket);
        return ERROR;
    }
    if (listen(f->tcp_socket, SOMAXCONN) != SUCCESS) {
        perror("listen");
        close(f->tcp_socket);
        return ERROR;
    }
    return SUCCESS;
}

int init_zappy(serv_t *server, int port)
{
    server->address = fill_in_adress(port);
    server->tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    server->eggs = initialize_eggs();

    if (connection_error(server) == ERROR) {
        free(server->eggs);
        return ERROR;
    }
    return SUCCESS;
}
