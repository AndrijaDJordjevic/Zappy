/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** map_content
*/

#include "my_server.h"
#include "gui_cmd.h"
#include "map.h"
#include "macros.h"
#include "client_cmd_macros.h"
#include "client_cmd.h"

void format_position_string(char *tile_pos_x, char *tile_pos_y, int x, int y)
{
    snprintf(tile_pos_x, MAX_TILE_OUTPUT_LENGTH, "%d", x);
    snprintf(tile_pos_y, MAX_TILE_OUTPUT_LENGTH, "%d", y);
}

void map_content(int fd, serv_t *serv, char **args)
{
    char tileOutput[MAX_TILE_OUTPUT_LENGTH] = "";
    char final_output[MAX_OUTPUT_LENGTH] = "";
    char tile_pos_x[MAX_TILE_OUTPUT_LENGTH] = "";
    char tile_pos_y[MAX_TILE_OUTPUT_LENGTH] = "";
    int len = my_strlen_2d(args);

    if (len != 1) {
        dprintf(fd, "sbp\n");
        return;
    }
    for (int y = 0; y < serv->param->height; y++) {
        for (int x = 0; x < serv->param->width; x++) {
            tileOutput[0] = '\0';
            format_position_string(tile_pos_x, tile_pos_y, x, y);
            tile_content_cmd_string(tileOutput, sizeof(tileOutput),
            serv, (char *[]) {tile_pos_x, tile_pos_y});
            strcat(final_output, tileOutput);
        }
    }
    dprintf(fd, "%s", final_output);
}
