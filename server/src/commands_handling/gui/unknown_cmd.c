/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** unknown_cmd
*/

#include "macros.h"
#include "client_cmd.h"
#include "my_server.h"

void unknown_cmd(int fd, serv_t *serv, char **args)
{
    (void) fd;
    (void) serv;
    (void) args;
    send_message(fd, "suc\n", "unknown");
}
