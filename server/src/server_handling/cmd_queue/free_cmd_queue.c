/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** free_cmd_queue
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_server.h"

void free_cmd_queue(client_cmd_queue_t *cmd_queue)
{
    args_link_t *tmp = NULL;

    if (cmd_queue == NULL)
        return;

    while (cmd_queue->args_link != NULL) {
        tmp = cmd_queue->args_link;
        cmd_queue->args_link = cmd_queue->args_link->next;
        free_array(tmp->args);
        free(tmp);
    }
}
