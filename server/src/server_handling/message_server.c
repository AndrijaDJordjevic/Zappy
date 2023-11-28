/*
** EPITECH PROJECT, 2023
** message_server
** File description:
** server
*/

#include "macros.h"
#include "my_server.h"
#include <unistd.h>

void smg(serv_t *serv, char *message)
{
    char command[100];
    int gui = get_gui_fd(serv->clients, serv->max_clients);

    snprintf(command, sizeof(command), "smg %s\n", message);
    send_message(gui, command, "smg");
}
