/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-martin.petit
** File description:
** look_utils
*/

#include <stdlib.h>
#include "my_server.h"
#include "map.h"
#include "macros.h"
#include "player.h"
#include <stdlib.h>
#include <string.h>
#include "client_cmd_macros.h"


void get_next_tile_line(enum orientation orientation, int width, int height,
position_t *next_tile)
{
    switch (orientation) {
        case N:
            next_tile->y = next_tile->y > 0 ? next_tile->y - 1 : height - 1;
            next_tile->x = next_tile->x > 0 ? next_tile->x - 1 : width - 1;
            break;
        case E:
            next_tile->x = next_tile->x < width - 1 ? next_tile->x + 1 : 0;
            next_tile->y = next_tile->y > 0 ? next_tile->y - 1 : height - 1;
            break;
        case S:
            next_tile->y = next_tile->y < height - 1 ? next_tile->y + 1 : 0;
            next_tile->x = next_tile->x < width - 1 ? next_tile->x + 1 : 0;
            break;
        case W:
            next_tile->x = next_tile->x > 0 ? next_tile->x - 1 : width - 1;
            next_tile->y = next_tile->y < height - 1 ? next_tile->y + 1 : 0;
            break;
    }
}

void get_next_tile_width(enum orientation orientation, position_t *next_tile,
int width, int height)
{
    switch (orientation) {
        case N:
            next_tile->x = next_tile->x < width - 1 ? next_tile->x + 1 : 0;
            break;
        case E:
            next_tile->y = next_tile->y < height - 1 ? next_tile->y + 1 : 0;
            break;
        case S:
            next_tile->x = next_tile->x > 0 ? next_tile->x - 1 : width - 1;
            break;
        case W:
            next_tile->y = next_tile->y > 0 ? next_tile->y - 1 : height - 1;
            break;
    }
}

static char const *ressource_to_str(enum ressource item)
{
    char const *str[RESSOURCES_NBR] = {
        "food",
        "linemate",
        "deraumere",
        "sibur",
        "mendiane",
        "phiras",
        "thystame"
    };

    return (str[item]);
}

static bool is_player_on_tile(serv_t *serv, int fd)
{
    client_t *list = serv->clients;
    client_t *clt = get_client_by_fd(serv->clients, fd, serv->max_clients);

    if (list == NULL || clt == NULL)
        return false;
    for (size_t i = 0; i < serv->max_clients; i++) {
        if (list[i].fd == fd || list[i].fd == -1 ||
        list[i].client_type != PLAYER)
            continue;
        if CHECK_POS(clt->pos.x, list[i].pos.x, clt->pos.y, list[i].pos.y)
            return true;
        }
    return false;
}

char *get_tile_content(inventory_t item, serv_t *serv, int fd)
{
    int *ressources[RESSOURCES_NBR] = { &item.food,
        &item.linemate, &item.deraumere, &item.sibur, &item.mendiane,
        &item.phiras, &item.thystame
    };
    char str[MAX_BUFF] = {0};

    if (is_player_on_tile(serv, fd) == true)
        strcat(str, "player ");
    for (int i = 0; i < RESSOURCES_NBR; i++) {
        if (*ressources[i] > 0 ) {
            strcat(str, i != 0 && strlen(str) > 0
            && *ressources[i - 1] == 0 ? " " : "");
            strcat(str, ressource_to_str(i));
            strcat(str, i != RESSOURCES_NBR - 1 &&
            *ressources[i + 1] > 0 ? " " : "");
        }
    }
    if (strlen(str) == 0)
        strcat(str, " ");
    return strcmp(str, "player ") == 0 ? strdup("player") : strdup(str);
}
