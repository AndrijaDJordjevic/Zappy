/*
** EPITECH PROJECT, 2023
** lvl5
** File description:
** lvl5
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_server.h"
#include "player.h"
#include "macros.h"
#include "client_cmd.h"
#include "gui_cmd.h"

inventory_t get_mandatory_lvl5(void)
{
    static const inventory_t mandatory = {
        .food = 0,
        .linemate = 1,
        .deraumere = 1,
        .sibur = 2,
        .mendiane = 0,
        .phiras = 1,
        .thystame = 0
    };
    return mandatory;
}

inventory_t get_mandatory_lvl6(void)
{
    static const inventory_t mandatory = {
        .food = 0,
        .linemate = 1,
        .deraumere = 2,
        .sibur = 1,
        .mendiane = 3,
        .phiras = 0,
        .thystame = 0
    };
    return mandatory;
}

void incan_lvl_6(serv_t *serv, int fd)
{
    incantations_mandatory(serv, fd, 4);
}

void incan_lvl_5(serv_t *serv, int fd)
{
    incantations_mandatory(serv, fd, 4);
}
