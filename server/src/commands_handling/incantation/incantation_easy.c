/*
** EPITECH PROJECT, 2023
** lvl3
** File description:
** lvl3
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_server.h"
#include "player.h"
#include "macros.h"
#include "client_cmd.h"
#include "gui_cmd.h"

inventory_t get_mandatory_lvl3(void)
{
    inventory_t mandatory = {
        .food = 0,
        .linemate = 1,
        .deraumere = 1,
        .sibur = 1,
        .mendiane = 0,
        .phiras = 0,
        .thystame = 0
    };
    return mandatory;
}

inventory_t get_mandatory_lvl4(void)
{
    static const inventory_t mandatory = {
        .food = 0,
        .linemate = 2,
        .deraumere = 0,
        .sibur = 1,
        .mendiane = 0,
        .phiras = 2,
        .thystame = 0
    };
    return mandatory;
}

void incan_lvl_3(serv_t *serv, int fd)
{
    incantations_mandatory(serv, fd, 2);
}

void incan_lvl_4(serv_t *serv, int fd)
{
    incantations_mandatory(serv, fd, 2);
}
