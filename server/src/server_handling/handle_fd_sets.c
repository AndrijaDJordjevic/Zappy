/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** init_fd_sets
*/

#include "my_server.h"
#include <string.h>

void clear_fd_sets(sets_t *set, int fd)
{
    FD_CLR(fd, &set->master_read_fds);
    FD_CLR(fd, &set->master_write_fds);
    FD_CLR(fd, &set->master_except_fds);
    FD_CLR(fd, &set->working_read_fds);
    FD_CLR(fd, &set->working_write_fds);
    FD_CLR(fd, &set->working_except_fds);
}

void reset_fd_sets(sets_t *set, int freq, struct timeval *timeout)
{
    set->working_read_fds = set->master_read_fds;
    set->working_write_fds = set->master_write_fds;
    set->working_except_fds = set->master_except_fds;
    if (timeout->tv_usec == timeout->tv_sec) {
        timeout->tv_sec = 1 / freq;
        timeout->tv_usec = 0;
    } else {
        timeout->tv_sec = (1 / freq) - (timeout->tv_usec / 1000000);
        timeout->tv_usec = 0;
    }
}

void init_fd_sets(serv_t *serv)
{
    serv->sets.master_read_fds = (fd_set){0};
    serv->sets.master_write_fds = (fd_set){0};
    serv->sets.master_except_fds = (fd_set){0};

    FD_ZERO(&serv->sets.master_read_fds);
    FD_ZERO(&serv->sets.master_write_fds);
    FD_ZERO(&serv->sets.master_except_fds);
    FD_SET(serv->tcp_socket, &serv->sets.master_write_fds);
    FD_SET(serv->tcp_socket, &serv->sets.master_read_fds);
    FD_SET(serv->tcp_socket, &serv->sets.master_except_fds);

    serv->max_fd = serv->tcp_socket;
    serv->timeout.tv_sec = 1 / serv->param->freq;
    serv->timeout.tv_usec = 0;
}
