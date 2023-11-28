/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** look
*/
#include <stdlib.h>
#include "my_server.h"
#include "map.h"
#include "macros.h"
#include "player.h"
#include <stdlib.h>
#include <string.h>
#include "client_cmd_macros.h"
#include "client_cmd.h"

static char *get_tile_row_content(int fd, tile_content_t tile_content)
{
    char *tmp = NULL;
    position_t tile = tile_content.pos;
    (void)  fd;

    for (int i = 0; i < tile_content.vision_side ; i++) {
        tmp = get_tile_content(tile_content.serv->map[tile.y][tile.x]
            .ressources_elements, tile_content.serv, fd);
        strcat(tile_content.str, tmp);
        strcat(tile_content.str, ",");
        get_next_tile_width(tile_content.orientation, &tile,
        tile_content.serv->param->width, tile_content.serv->param->height);
        free(tmp);
        tmp = NULL;
    }
    return (tile_content.str);
}

static void cut_last_comma(char *str)
{
    int len;
    strcat(str, "]");

    len = strlen(str);

    if (str[len - 2] == ',' && str[len - 1] == ']') {
        str[len - 2] = ']';
        str[len - 1] = '\n';
        str[len] = '\0';
    }

}

static void handle_first_tile(client_t *client, serv_t *serv, int fd,
char *vision)
{
    char *tmp = NULL;

    tmp = get_tile_content(serv->map[client->pos.y][client->pos.x]
        .ressources_elements, serv, fd);
    if (tmp == NULL) {
        return;
    }
    strcat(vision, tmp);
    strcat(vision, ",");
    free(tmp);
    tmp = NULL;
}

static void look_around(client_t *client, serv_t *serv, int fd)
{
    position_t tile = client->pos;
    int current_vision_side = 1;
    int max_vision_front = client->level;
    char vision[BUFSIZ] = "[";
    char str[MAX_BUFF] = "";

    for (int i = 0; i <= max_vision_front; i++, current_vision_side += 2) {
        str[0] = '\0';
        if (current_vision_side == 1) {
            handle_first_tile(client, serv, fd, vision);
        } else
            strcat(vision, get_tile_row_content(fd, (tile_content_t)
            {serv, str, current_vision_side, client->orientation, tile}));
        get_next_tile_line(client->orientation, serv->param->width,
            serv->param->height, &tile);
    }
    cut_last_comma(vision);
    send_message(fd, vision, "Look around");
}

void look_command(int client_socket, serv_t *serv, char **args)
{
    client_t *client = get_client_by_fd(serv->clients, client_socket,
    serv->max_clients);

    if (client == NULL || !serv) {
        send_message(client_socket, SERV_KO, "look_cmd: player not found");
        return;
    }
    printf("Player %d is looking around, lvl: %d\n", client->fd, client->level);
    look_around(client, serv, client_socket);
    (void)args;
}
