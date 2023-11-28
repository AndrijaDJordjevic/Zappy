/*
** EPITECH PROJECT, 2023
** lvl7
** File description:
** lvl7
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_server.h"
#include "player.h"
#include "macros.h"
#include "client_cmd.h"

inventory_t get_mandatory_lvl7(void)
{
    static const inventory_t mandatory = {
        .food = 0,
        .linemate = 1,
        .deraumere = 2,
        .sibur = 3,
        .mendiane = 0,
        .phiras = 1,
        .thystame = 0
    };
    return mandatory;
}

inventory_t get_mandatory_lvl8(void)
{
    static const inventory_t mandatory = {
        .food = 0,
        .linemate = 2,
        .deraumere = 2,
        .sibur = 2,
        .mendiane = 2,
        .phiras = 2,
        .thystame = 1
    };
    return mandatory;
}

void incan_lvl_8(serv_t *serv, int fd)
{
    incantations_mandatory(serv, fd, 6);
}

void incan_lvl_7(serv_t *serv, int fd)
{
    incantations_mandatory(serv, fd, 6);
}
