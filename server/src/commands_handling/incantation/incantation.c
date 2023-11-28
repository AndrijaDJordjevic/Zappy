/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** incantation
*/

#include "client_cmd.h"
#include "macros.h"
#include "gui_cmd.h"

void incantation_command(int client_socket, serv_t *serv, char **args)
{
    client_t *client = get_client_by_fd(serv->clients, client_socket,
serv->max_clients);
    void (*incan_functions[])(serv_t *, int) = {
        NULL,
        incan_lvl_2,
        incan_lvl_3,
        incan_lvl_4,
    };

    if (client->level >= 1 && client->level <= 4) {
        incan_functions[client->level](serv, client_socket);
    }
    (void)args;
    return;
}

static void inc_second_check(incantation_t *inc, serv_t *serv)
{
    remove_ressource_incantation(serv->map, inc->client->pos, inc->mandatory);
    loop_lvl_up_players(serv->clients, inc->player_lst, serv->max_clients);
    message_elevation("Incantation", inc->fd, inc->client);
}

static void inc_first_check(incantation_t *inc, serv_t *serv)
{
    if (pic(serv, inc->player_lst, inc->client) == ERROR) {
        send_message(inc->fd, SERV_KO, "Incantation");
        pie(serv, inc->client->pos, false);
        return;
    }
    inc->current_tile = get_tile_ressources(inc->client->pos, serv->map);
    get_inc_nbr_player_lvl(inc->player_lst, serv, inc->nbr_max,
inc->client->level + 1);
}

static void incantation(incantation_t *inc, serv_t *serv, bool check)
{
    if (check_incantation(&(inc->mandatory), &(inc->current_tile)) &&
int_lst_len(inc->player_lst) == inc->nbr_max) {
        if (check)
            inc_first_check(inc, serv);
        else
            inc_second_check(inc, serv);
    } else {
        send_message(inc->fd, SERV_KO, "Incantation");
        pie(serv, inc->client->pos, false);
    }
}

void incantations_mandatory(serv_t *serv, int fd, int nbr_max)
{
    client_t *client;
    inventory_t current_tile;
    int player_lst[MAX_BUFF] = {fd};

    if (inc_check_var(fd, serv) == ERROR) {
        send_message(fd, SERV_KO, "Incantation");
        return;
    }
    client = get_client_by_fd(serv->clients, fd, serv->max_clients);
    current_tile = get_tile_ressources(client->pos, serv->map);
    incantation_t inc = {client, get_mandatory_lvl(client->level + 1)
    , current_tile, player_lst, fd, nbr_max};
    get_inc_nbr_player_lvl(player_lst, serv, nbr_max, client->level + 1);
    if (int_lst_len(player_lst) != nbr_max) {
        send_message(fd, SERV_KO, "Incantation");
        return;
    }
    incantation(&inc, serv, true);
    incantation(&inc, serv, false);
}
