/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** handle_cmd_queue
*/

#include "player.h"
#include "my_server.h"
#include "client_cmd_macros.h"
#include "client_cmd.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>

char **copy_2d_array(char **array)
{
    char **new_array = malloc(sizeof(char *) * (my_strlen_2d(array) + 1));
    int i = 0;

    if (array == NULL) {
        if (new_array != NULL)
            free(new_array);
        return NULL;
    }
    if (new_array == NULL)
        return NULL;
    for (; array[i] != NULL; i++) {
        new_array[i] = strdup(array[i]);
        if (new_array[i] == NULL)
            return NULL;
    }
    new_array[i] = NULL;
    return new_array;
}

args_link_t *add_args(char **command, args_link_t *list)
{
    args_link_t *new = malloc(sizeof(*new));
    args_link_t *current = list;

    if (new == NULL)
        return NULL;

    new->args = NULL;
    new->args = copy_2d_array(command);
    if (new->args == NULL)
        return NULL;
    new->next = NULL;
    if (list == NULL)
        return new;

    while (current->next != NULL)
        current = current->next;
    current->next = new;
    return list;
}

void handle_cmd_queue(client_t *client, const t_symstruct new_cmd,
char **command)
{
    client_cmd_queue_t *cmd_queue = &client->client_cmd_queue;

    if (cmd_queue->cmd_nbr == DEFAULT_MAX_CLIENT_CMD - 1)
        return;

    cmd_queue->cmd[cmd_queue->cmd_nbr] = new_cmd.cmd;
    cmd_queue->time_unit[cmd_queue->cmd_nbr] = new_cmd.time_unit;
    cmd_queue->args_link = add_args(command, cmd_queue->args_link);
    cmd_queue->cmd_nbr += 1;
    if (cmd_queue->cmd_nbr == 1)
        client->action_time = time(NULL);
}
