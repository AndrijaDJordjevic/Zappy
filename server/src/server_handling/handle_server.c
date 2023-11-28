/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** handle_server
*/

#include "macros.h"
#include "my_server.h"
#include <unistd.h>

static void init_empty_clients(serv_t *serv)
{
    serv->max_clients = 0;
    serv->clients = NULL;
}

int handle_server(params_t *param)
{
    serv_t server = {0};

    if (init_zappy(&server, param->port) == ERROR) {
        return ERROR;
    }
    init_empty_clients(&server);
    server.param = param;
    server.ressources_time_unit = RESSOURCE_TIME_UNIT / param->freq;

    run_server(&server);
    clear_fd_sets(&server.sets, server.tcp_socket);
    close(server.tcp_socket);

    return SUCCESS;
}
