/*
** EPITECH PROJECT, 2023
** run
** File description:
** run
*/

#include "macros.h"
#include "my_server.h"
#include "player.h"
#include "map.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

static void client_connection(serv_t *server, int i)
{
    if (i == server->tcp_socket) {
        if (handle_new_connection(server) == ERROR)
            exit(ERROR);
        } else
            handle_client_data(server, i);
}

void check_fd_sets(serv_t *serv, int fd, sets_t *set)
{
    if (FD_ISSET(fd, &set->working_read_fds))
        client_connection(serv, fd);
    if (FD_ISSET(fd, &set->working_write_fds)) {
        check_cmd_queue(serv);
        return;
    }
    if (FD_ISSET(fd, &set->working_except_fds))
        return;
}

static int handle_client_requests(serv_t *server, sets_t *set)
{
    handle_players_life(server);
    for (int i = 0; i <= server->max_fd; i++) {
        check_fd_sets(server, i, set);
    }
    return SUCCESS;
}

static int start_server(serv_t *server)
{
    int ret_val;

    signal(SIGINT, handle_signint);
    reset_fd_sets(&server->sets, server->param->freq, &server->timeout);
    ret_val = select(server->max_fd + 1, &server->sets.working_read_fds,
    &server->sets.working_write_fds, &server->sets.working_except_fds,
    &server->timeout);
    if (ret_val == -1) {
        if (!get_singleton(false))
            return SUCCESS;
        perror("select");
        close(server->tcp_socket);
        exit(ERROR);
    } else if (ret_val) {
        handle_client_requests(server, &server->sets);
    }
    handle_players_life(server);
    handle_ressources_generation(server);
    return -1;
}

int run_server(serv_t *server)
{
    init_fd_sets(server);
    if (initiate_map(server) != SUCCESS)
        return ERROR;
    while (get_singleton(false)) {
        if (start_server(server) == SUCCESS)
            break;
    }
    free_map(server->map, server->param->height);
    if (server->clients != NULL)
        kill_clients(server->clients, server->max_clients, &server->sets);
    free_all_eggs(server->eggs);
    return SUCCESS;
}
