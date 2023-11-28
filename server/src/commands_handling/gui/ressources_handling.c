/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** ressources_handling
*/


#include "macros.h"
#include "client_cmd.h"
#include "player.h"

void send_ressource_to_gui(int fd, serv_t *serv, int ressource_nb,
    char const *cmd_name)
{
    char msg[BUFSIZ] = {0};
    int serv_gui_fd = get_gui_fd(serv->clients, serv->max_clients);

    if (serv_gui_fd == -1) {
        send_message(fd, "ko\n", cmd_name);
        return;
    }
    snprintf(msg, BUFSIZ, "%s %d %d\n", cmd_name, fd, ressource_nb);
    send_message(serv_gui_fd, msg, cmd_name);
}

int get_given_ressource(char *ressource)
{
    char *ressources[RESSOURCES_NBR] = {
        "food",
        "linemate",
        "deraumere",
        "sibur",
        "mendiane",
        "phiras",
        "thystame"
    };

    for (int i = 0; i < RESSOURCES_NBR; i++) {
        if (strcmp(ressource, ressources[i]) == 0)
            return i;
    }
    return NONE;
}

void ressource_dropping(int fd, serv_t *serv, char **args)
{
    int ressource_nb = NONE;
    int len = my_strlen_2d(args);

    if (len != 2) {
        send_message(fd, "suc\n", "ressource_picking");
        return;
    }

    ressource_nb = get_given_ressource(args[1]);
    send_ressource_to_gui(fd, serv, ressource_nb, "pdr");
}

void ressource_picking(int fd, serv_t *serv, char **args)
{
    int ressource_nb = NONE;
    int len = my_strlen_2d(args);

    if (len != 2) {
        send_message(fd, "suc\n", "ressource_picking");
        return;
    }
    ressource_nb = get_given_ressource(args[1]);
    send_ressource_to_gui(fd, serv, ressource_nb, "pgt");
}
