/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** broadcast gui
*/
#include <stdlib.h>
#include <stdio.h>
#include "my_server.h"
#include "player.h"
#include "macros.h"
#include "client_cmd.h"

char* players_nbr_to_str(int* players_nbr, int nbr)
{
    int total_size = 0;
    char* str = (char*)malloc((total_size + 1) * sizeof(char));
    int offset = 0;

    for (int i = 0; i < nbr; i++)
        total_size += snprintf(NULL, 0, "%d ", players_nbr[i]);
    if (str == NULL) {
        fprintf(stderr, "Erreur allocation of memory\n");
        return NULL;
    }
    for (int i = 0; i < nbr; i++) {
        offset += snprintf(str + offset, total_size - offset + 1,
"%d ", players_nbr[i]);
    }
    str[total_size - 1] = '\0';
    return str;
}

int pic(serv_t *serv, int *players, const client_t *client)
{
    char buffer[MAX_BUFF];
    int len_players = int_lst_len(players);
    char* players_nbr;

    if (len_players == 0)
        return ERROR;
    players_nbr = players_nbr_to_str(players, len_players);
    if (players_nbr == NULL)
        return ERROR;
    sprintf(buffer, "pic %d %d %d %s", client->pos.x, client->pos.y,
    client->level, players_nbr);
    send_to_gui(serv, buffer);
    free(players_nbr);
    return SUCCESS;
}
