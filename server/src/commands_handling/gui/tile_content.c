/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** tile_content
*/
#include "my_server.h"
#include "client_cmd.h"
#include "client_cmd_macros.h"
#include "map.h"
#include <stdlib.h>

bool is_number(char *str)
{
    for (int i = 0; str[i]; i++)
        if (!IS_DIGIT(str[i]))
            return false;
    return true;
}

bool is_tile_content_valid(char **args)
{
    if (!is_number(args[0]) || !is_number(args[1]))
        return false;
    return true;
}

void tile_content_cmd_string(char *output, size_t outputSize, serv_t *serv,
char **xy)
{
    int x = atoi(xy[0]);
    int y = atoi(xy[1]);
    inventory_t *tile_content = &serv->map[y][x].ressources_elements;

    if (x < 0 || x >= serv->param->width || y < 0 || y >= serv->param->height) {
        snprintf(output, outputSize, "sbp\n");
        return;
    }

    snprintf(output, outputSize, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
    tile_content->food, tile_content->linemate, tile_content->deraumere,
    tile_content->sibur, tile_content->mendiane, tile_content->phiras,
    tile_content->thystame);
}

void tile_content(int fd, serv_t *serv, char **args)
{
    unsigned int len = my_strlen_2d(args);
    char output[MAX_TILE_OUTPUT_LENGTH] = "";

    if (len != 3 || !is_tile_content_valid(&args[1]))
        dprintf(fd, "sbp\n");
    else
        tile_content_cmd_string(output, sizeof(output), serv, &args[1]);

    dprintf(fd, "%s", output);
}
