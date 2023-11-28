/*
** EPITECH PROJECT, 2023
** incantation
** File description:
** utils
*/

#include "client_cmd.h"
#include "macros.h"

void message_elevation(char *error, int fd, client_t *client)
{
    char message[MAX_BUFF];

    sprintf(message, "Elevation underway. Current level: %i\n", client->level);
    send_message(fd, message, error);
}

int int_lst_len(int *lst)
{
    int len = 0;

    for (; lst[len] != 0; len++);
    return len;
}

static void lvl_up_players(client_t *lst, int fd, size_t max_clients)
{
    for (size_t i = 0; i < max_clients; i++) {
        if (lst[i].fd == -1)
            continue;
        if (lst[i].fd == fd) {
            lst->level++;
            break;
        }
    }
}

void loop_lvl_up_players(client_t *lst, int *player_lst, size_t max_clients)
{
    for (size_t i = 0; player_lst[i] != 0; i++)  {
        lvl_up_players(lst, player_lst[i], max_clients);
    }
}

void remove_ressource_incantation(world map, position_t pos,
inventory_t mandatory)
{
    map[pos.y][pos.x].ressources_elements.linemate -= mandatory.linemate;
    map[pos.y][pos.x].ressources_elements.deraumere -= mandatory.deraumere;
    map[pos.y][pos.x].ressources_elements.sibur -= mandatory.sibur;
    map[pos.y][pos.x].ressources_elements.mendiane -= mandatory.mendiane;
    map[pos.y][pos.x].ressources_elements.phiras -= mandatory.phiras;
    map[pos.y][pos.x].ressources_elements.thystame -= mandatory.thystame;
}
