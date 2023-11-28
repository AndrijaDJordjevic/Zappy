/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** teams_name
*/
#include <stdlib.h>
#include <stdio.h>
#include "my_server.h"
#include "player.h"
#include "macros.h"
#include "client_cmd.h"

char *get_team_name(int team_index, params_t *param)
{
    for (int i = 0; param->names[i] != NULL; i++) {
        if (i == team_index)
            return param->names[i];
    }
    return NULL;
}

void teams_name(int fd, serv_t *serv, char **args)
{
    int i = 0;
    char buffer[4096] = {0};
    char tmp[4096] = {0};
    int len = my_strlen_2d(args);

    if (len != 1) {
        dprintf(fd, "suc\n");
        return;
    }
    while (serv->param->names[i] != NULL) {
        if (strcmp(serv->param->names[i], "GRAPHIC") != 0) {
            snprintf(tmp, sizeof(tmp), "tna %s\n", serv->param->names[i]);
            strcat(buffer, tmp);
            tmp[0] = '\0';
        }
        i++;
    }
    send(fd, buffer, strlen(buffer), 0);
}
