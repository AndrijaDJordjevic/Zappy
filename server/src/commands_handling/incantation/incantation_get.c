/*
** EPITECH PROJECT, 2023
** get
** File description:
** incantation
*/

#include "client_cmd.h"
#include "macros.h"

inventory_t get_tile_ressources(position_t tile, world map)
{
    inventory_t ressource = {
        .food = map[tile.y][tile.x].ressources_elements.food,
        .linemate = map[tile.y][tile.x].ressources_elements.linemate,
        .deraumere = map[tile.y][tile.x].ressources_elements.deraumere,
        .sibur = map[tile.y][tile.x].ressources_elements.sibur,
        .mendiane = map[tile.y][tile.x].ressources_elements.mendiane,
        .phiras = map[tile.y][tile.x].ressources_elements.phiras,
        .thystame = map[tile.y][tile.x].ressources_elements.thystame
    };
    return ressource;
}

static bool get_player_pos(position_t player1, position_t player2)
{
    if (player1.x == player2.x) {
        if (player1.y == player2.y)
            return true;
    }
    return false;
}

void get_inc_nbr_player_lvl(int *player_lst, serv_t *serv, int max, int lvl)
{
    for (size_t i = 0; i < serv->max_clients &&
    int_lst_len(player_lst) < max; i++) {
        if (serv->clients[i].fd == -1)
            continue;
        if (serv->clients[i].fd == player_lst[0]
        && serv->clients[i].level == lvl && serv->clients[i].fd != -1 &&
        get_player_pos(serv->clients[i].pos, serv->clients[player_lst[0]].pos)
        == true) {
            player_lst[1] = serv->clients[i].fd;
        }
    }
}

inventory_t get_mandatory_lvl(int lvl)
{
    inventory_t res = {-1, -1, -1, -1, -1, -1, -1};
    inventory_t (*get_mandatory_lvl[8])(void) = {
        NULL,
        get_mandatory_lvl2,
        get_mandatory_lvl3,
        get_mandatory_lvl4,
        get_mandatory_lvl5,
        get_mandatory_lvl6,
        get_mandatory_lvl7,
        get_mandatory_lvl8
    };

    if ((lvl >= 1 && lvl <= 7) && get_mandatory_lvl[lvl] != NULL) {
        return get_mandatory_lvl[lvl]();
    }
    return res;
}
