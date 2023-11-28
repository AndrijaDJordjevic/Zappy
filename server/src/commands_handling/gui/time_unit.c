/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** handle_client_commands
*/
#include <stdlib.h>
#include <stdio.h>
#include "my_server.h"
#include "macros.h"

void time_unit_update(int fd, serv_t *serv, char **args)
{
    int new_time_unit = 0;
    char buffer[MAX_BUFF];

    if (args[1] == NULL || (new_time_unit = atoi(args[1])) <= 0) {
        send_message(fd, SERV_KO, "time_unit_update");
        return;
    }
    serv->param->freq = new_time_unit;
    sprintf(buffer, "sst %d\n", new_time_unit);
    send_message(fd, buffer, "time_unit_update");
}

void time_unit_request(int fd, serv_t *serv, char **args)
{
    char buffer[MAX_BUFF];

    (void)args;
    sprintf(buffer, "sgt %d\n", serv->param->freq);
    send_message(fd, buffer, "time_unit_request");
}
