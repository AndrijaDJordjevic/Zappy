/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** broadcast
*/

#include "macros.h"
#include "client_cmd.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concat_strings(char **args)
{
    int final_length = 0;
    int i;
    int j;
    char *result = NULL;

    for (i = 0; args[i] != NULL; i++)
        final_length += strlen(args[i]);
    result = (char*)malloc((final_length + i) * sizeof(char));
    if (result == NULL)
        return NULL;
    for (i = 0, j = 0; args[i] != NULL; i++) {
        if (i > 0)
            result[j++] = ' ';
        strcpy(&result[j], args[i]);
        j += strlen(args[i]);
    }
    return result;
}

void send_broadcast_gui(int client_socket, int gui_fd, char *str)
{
    char msg_gui[BUFSIZ] = {0};

    snprintf(msg_gui, MAX_BUFF, "pbc %d %s\n", client_socket, str);
    send_message(gui_fd, msg_gui, "broadcast");
}

int select_client_write(int fd, struct timeval *timeout, serv_t *serv,
char *msg_ai)
{
    int ret = 0;

    timeout->tv_sec = 7;
    timeout->tv_usec = 0;

    ret = select(fd + 1, NULL, &serv->sets.working_write_fds,
    &serv->sets.working_except_fds, timeout);
    if (ret == -1) {
        return -1;
    } else if (ret == 0) {
        return 0;
    }
    if (FD_ISSET(fd, &serv->sets.working_except_fds)) {
        kill_this_client(get_client_by_fd
        (serv->clients, fd, serv->max_clients), &serv->sets, serv->max_clients);
        return -1;
    } else if (FD_ISSET(fd, &serv->sets.working_write_fds))
        dprintf(fd, "%s", msg_ai);
    return 0;
}

void broadcast(serv_t *serv, int client_socket, char *str)
{
    int tmp_fd = 0;
    int gui_fd = get_gui_fd(serv->clients, serv->max_clients);
    client_t *client_broadcasting = get_client_by_fd(serv->clients,
        client_socket, serv->max_clients);
    char msg_ai[MAX_BUFF] = {0};
    struct timeval timeout = {0};

    if (client_broadcasting == NULL || str == NULL)
        return;
    for (size_t i = 0; i < serv->max_clients; i++) {
        tmp_fd = serv->clients[i].fd;
        if (tmp_fd == -1 || tmp_fd == client_socket || tmp_fd == gui_fd)
            continue;
        snprintf(msg_ai, MAX_BUFF, "message %d, %s\n",
        get_direction(client_broadcasting, serv->clients[i],
        serv->param->width, serv->param->height), str);
        if (select_client_write(tmp_fd, &timeout, serv, msg_ai) == -1)
            return;
        msg_ai[0] = '\0';
    }
    send_broadcast_gui(client_socket, gui_fd, str);
}

void broadcast_command(int client_socket, serv_t *serv, char **args)
{
    int len = my_strlen_2d(args);

    if (len < 2) {
        send_message(client_socket, SERV_KO, "broadcast_cmd");
        return;
    } else {
        char *str = concat_strings(&args[1]);
        send_message(client_socket, SERV_OK, "broadcast_cmd");
        broadcast(serv, client_socket, str);
        free(str);
    }
}
