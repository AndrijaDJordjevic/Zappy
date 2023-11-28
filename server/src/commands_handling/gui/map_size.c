/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** map_size
*/
#include <stdio.h>
#include "my_server.h"
#include "client_cmd.h"

void map_size(int fd, serv_t *serv, char **args)
{
    int len = my_strlen_2d(args);
    (void)args;

    if (len != 1) {
        dprintf(fd, "sbp\n");
        return;
    }
    dprintf(fd, "msz %d %d\n", serv->param->width, serv->param->height);
}
