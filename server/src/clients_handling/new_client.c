/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** new_client
*/

#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "macros.h"
#include "my_server.h"

static void init_new_allocated_list(client_t *current_list, size_t max_clients,
    size_t start, serv_t *serv)
{
    for (size_t i = start; i < max_clients; ++i) {
        current_list[i] = init_new_client(-1, serv);
    }
}

static client_t *realloc_client_list(client_t *current_list, serv_t *serv)
{
    client_t *new_list = NULL;

    serv->max_clients *= 2;
    new_list = realloc(current_list, sizeof(client_t) * (serv->max_clients));

    if (new_list == NULL) {
        perror("malloc");
        return NULL;
    }

    current_list = new_list;

    return new_list;
}

client_t *append_client(client_t *current_list, serv_t *serv, int fd)
{
    for (size_t i = 0; i < serv->max_clients; ++i) {
        if (current_list[i].fd == -1) {
            overwrite_client(&current_list[i], serv, fd);
            return current_list;
        }
    }
    current_list = realloc_client_list(current_list, serv);
    if (current_list == NULL)
        return NULL;
    init_new_allocated_list(current_list, serv->max_clients,
        serv->max_clients / 2, serv);
    current_list[serv->max_clients / 2] = init_new_client(fd, serv);
    return current_list;
}

client_t *new_client(client_t *current_list, serv_t *serv, int fd)
{
    if (serv->max_clients == 0) {
        serv->max_clients = CLIENT_LIST_SIZE_INCREMENT;
        current_list = malloc(sizeof(client_t) * serv->max_clients);
        if (current_list == NULL) {
            perror("malloc");
            return NULL;
        }
        init_new_allocated_list(current_list, serv->max_clients, 0, serv);
        current_list[0] = init_new_client(fd, serv);
    } else {
        return append_client(current_list, serv, fd);
    }
    return current_list;
}
