/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** find_best_direction
*/

#include "player.h"
#include "client_cmd.h"
#include <stdio.h>
#include <math.h>

static double compute_distance(position_t *emitter, position_t *receiver,
int x, int y)
{
    double final_ret = -1;
    double current_ret = -1;
    position_t current_emitter = {emitter->x, emitter->y};
    position_t tmp_receiver = {receiver->x + x, receiver->y + y};

    for (int i = 0; i < 9; i++) {
        current_ret = sqrt(pow((tmp_receiver.x - current_emitter.x), 2) +
        pow((tmp_receiver.y - current_emitter.y), 2));
        if (final_ret == -1 || current_ret < final_ret)
            final_ret = current_ret;
        current_emitter.x += x;
        if (i % 3 == 0) {
            current_emitter.y += y;
            current_emitter.x = emitter->x;
        }
    }
    return final_ret;
}

int get_short_direction(position_t *emitter, client_direction_t *recv,
int x, int y)
{
    double result = -1;
    double current_result = -1;
    int final_direction = -1;
    position_t *recv_pos[8] = {
        &recv->pos1, &recv->pos2, &recv->pos3, &recv->pos4,
        &recv->pos5, &recv->pos6, &recv->pos7, &recv->pos8
    };

    for (int i = 0; i < 8; i++) {
        current_result = compute_distance(emitter, recv_pos[i], x, y);
        if (result == -1 || current_result < result) {
            final_direction = i + 1;
            result = current_result;
        }
    }
    return final_direction;
}

int find_best_direction(position_t *emitter, client_direction_t *receiver,
int x, int y)
{
    int direction = get_short_direction(emitter, receiver, x, y);

    if (direction != -1)
        return direction;

    return direction;
}
