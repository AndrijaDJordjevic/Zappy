/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** get_directions
*/

#include "player.h"
#include "client_cmd.h"

static client_direction_t get_client_view_direction(int orientation,
position_t pos, int x, int y)
{
    client_direction_t direction = {0};

    direction.pos0 = (position_t) {pos.x, pos.y};
    switch (orientation) {
        case N:
            get_north_direction(&direction, x, y);
            break;
        case E:
            get_east_direction(&direction, x, y);
            break;
        case S:
            get_south_direction(&direction, x, y);
            break;
        case W:
            get_west_direction(&direction, x, y);
            break;
        default:
            break;
    }
    return direction;
}

int get_direction(client_t *emitter, client_t receiver, int map_x, int map_y)
{
    client_direction_t recv_direction = get_client_view_direction(
        receiver.orientation, receiver.pos, map_x, map_y);

    if (receiver.pos.x == emitter->pos.x && receiver.pos.y == emitter->pos.y)
        return 0;
    return find_best_direction(&emitter->pos, &recv_direction, map_x, map_y);
}
