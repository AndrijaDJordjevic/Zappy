/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** take
*/

#include "macros.h"
#include "client_cmd.h"
#include "player.h"

static bool pick_obj_from_tile(enum ressource obj, serv_t *serv,
    client_t *client)
{
    int x = client->pos.x;
    int y = client->pos.y;
    int *ressources_list[RESSOURCES_NBR] = {
        (&serv->map[y][x].ressources_elements.food),
        (&serv->map[y][x].ressources_elements.linemate),
        (&serv->map[y][x].ressources_elements.deraumere),
        (&serv->map[y][x].ressources_elements.sibur),
        (&serv->map[y][x].ressources_elements.mendiane),
        (&serv->map[y][x].ressources_elements.phiras),
        (&serv->map[y][x].ressources_elements.thystame)
    };

    if (*ressources_list[obj] <= 0)
        return false;
    (*ressources_list[obj])--;
    return true;
}

static void add_obj_to_inventory(inventory_t *inventory, enum ressource obj)
{
    int *resources[RESSOURCES_NBR] = {
        &inventory->food,
        &inventory->linemate,
        &inventory->deraumere,
        &inventory->sibur,
        &inventory->mendiane,
        &inventory->phiras,
        &inventory->thystame
    };

    if (*resources[obj] < 0)
        return;
    (*resources[obj])++;
}

static bool take_obj_cmd(serv_t *serv, client_t *client, char *arg)
{
    enum ressource obj = get_ressource_index(arg);

    if (obj == NONE) {
        printf("take: invalid object\n");
        return false;
    }
    if (!pick_obj_from_tile(obj, serv, client)) {
        printf("take: pick obj from tile\n");
        return false;
    }
    add_obj_to_inventory(&client->inventory, obj);
    return true;
}

void take_command(int client_socket, serv_t *serv, char **args)
{
    int args_len = my_strlen_2d(args);
    client_t *client = get_client_by_fd(serv->clients, client_socket,
        serv->max_clients);
    int gui_fd = get_gui_fd(serv->clients, serv->max_clients);
    char msg_gui[MAX_BUFF];

    if (args_len != 2 || client == NULL || !check_take_set_args(args[1])) {
        send_message(client_socket, SERV_KO, "take_cmd_serv_ko");
        return;
    } else if (take_obj_cmd(serv, client, args[1]) == false) {
        send_message(client_socket, SERV_KO, "take_cmd_serv_ko2");
        return;
    }
    snprintf(msg_gui, MAX_BUFF, "pgt %d %d\n", client_socket,
        get_ressource_index(args[1]));
    send_message(gui_fd, msg_gui, "take_cmd_to_gui");
    send_message(client_socket, SERV_OK, "take_cmd_serv_ok");
    return;
}
