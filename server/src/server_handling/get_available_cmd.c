/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** get_client_gui_cmd
*/

#include "client_cmd_macros.h"
#include "client_cmd.h"
#include "gui_cmd.h"
#include "time_management.h"

const t_symstruct *available_client_cmd(int *size)
{
    static const t_symstruct commands[] = {
        {"Forward", forward_command, FORWARD},
        {"Right", right_command, RIGHT},
        {"Left", left_command, LEFT},
        {"Look", look_command, LOOK},
        {"Inventory", inventory_command, INVENTORY},
        {"Broadcast", broadcast_command, BROADCAST},
        {"Connect_nbr", connect_nbr_command, CONNECT_NBR},
        {"Fork", fork_command, FORK},
        {"Eject", eject_command, EJECT},
        {"Take", take_command, TAKE},
        {"Set", set_command, SET},
        {"Incantation", incantation_command, INCANTATION},
    };
    *size = sizeof(commands) / sizeof(t_symstruct);
    return commands;
}

const t_symstruct *available_gui_commands(int *size)
{
    static const t_symstruct commands[] = {
        {"msz", map_size, NO},
        {"bct", tile_content, NO},
        {"ppo", player_position, NO},
        {"tna", teams_name, NO},
        {"mct", map_content, NO},
        {"plv", player_level, NO},
        {"pin", player_inventory, NO},
        {"sgt", time_unit_request, NO},
        {"sst", time_unit_update, NO},
        {"pbc", broadcast_msg, NO},
        {"pdr", ressource_dropping, NO},
        {"pgt", ressource_picking, NO}
    };
    *size = sizeof(commands) / sizeof(t_symstruct);
    return commands;
}
