/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** handle_client_commands
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_server.h"
#include "client_cmd_macros.h"
#include "client_cmd.h"
#include "gui_cmd.h"
#include "macros.h"
#include "time_management.h"

void check_cmd_validity(client_t *client, char **command)
{
    int client_cmd_len = 0;
    const t_symstruct *clt_cmd = available_client_cmd(&client_cmd_len);

    if (client == NULL)
        return;
    for (int i = 0; i < client_cmd_len; ++i) {
        if (strcmp(clt_cmd[i].key, command[0]) == 0) {
            handle_cmd_queue(client, clt_cmd[i], command);
            return;
        }
    }
    dprintf(client->fd, SERV_KO);
}

static int set_client_cmd_queue(int client_socket, char **command,
serv_t *serv)
{
    client_t *client = get_client_by_fd(serv->clients, client_socket,
    serv->max_clients);

    if (client == NULL) {
        printf("client is null\n");
        return (ERROR);
    }
    if (client->client_cmd_queue.cmd_nbr >= DEFAULT_MAX_CLIENT_CMD) {
        printf("client cmd queue is full\n");
        return (SUCCESS);
    } else if (get_gui_fd(serv->clients, serv->max_clients) == client_socket) {
        return (ERROR);
    }
    check_cmd_validity(client, command);
    return ERROR;
}

static int call_gui_cmd(int fd, serv_t *serv, char **command)
{
    int gui_cmd_len = 0;
    const t_symstruct *gui_commands = available_gui_commands(&gui_cmd_len);

    if (fd != get_gui_fd(serv->clients, serv->max_clients))
        return (ERROR);

    for (int i = 0; i < gui_cmd_len; ++i)
        if (strcmp(gui_commands[i].key, command[0]) == 0) {
            gui_commands[i].cmd(fd, serv, command);
            return (SUCCESS);
        }
    dprintf(fd, "suc\n");
    return ERROR;
}

void handle_client_commands(int client_socket, char *command, serv_t *serv)
{
    char **command_cut = str_to_word_array(command);
    int ret = 0;

    if (command_cut == NULL || command_cut[0] == NULL) {
        send_message(client_socket, SERV_KO, "handle_client_commands");
        free_array(command_cut);
        return;
    } else if ((ret = check_client_auth(serv, client_socket, command_cut[0]))
    != SUCCESS) {
        send_message(client_socket, ret != AUTH ? SERV_KO : ""
        , "handle_client_commands");
        free_array(command_cut);
        return;
    }
    set_client_cmd_queue(client_socket, command_cut, serv);
    call_gui_cmd(client_socket, serv, command_cut);
    if (command_cut != NULL)
        free_array(command_cut);
}
