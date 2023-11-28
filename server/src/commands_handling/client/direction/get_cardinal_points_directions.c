/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** get_directions
*/

#include "player.h"

static void check_positions(client_direction_t *direction, int x, int y)
{
    position_t *around_player[NB_POS_AROUND_PLAYER] = {
        &direction->pos1,
        &direction->pos2,
        &direction->pos3,
        &direction->pos4,
        &direction->pos5,
        &direction->pos6,
        &direction->pos7,
        &direction->pos8
    };

    for (int i = 0; i < NB_POS_AROUND_PLAYER; i++) {
        around_player[i]->x = around_player[i]->x % x;
        around_player[i]->y = around_player[i]->y % y;
    }
}

void get_north_direction(client_direction_t *direction, int x, int y)
{
    int pos_x = direction->pos0.x;
    int pos_y = direction->pos0.y;

    direction->pos1 = (position_t) {pos_x, pos_y - 1};
    direction->pos2 = (position_t) {pos_x - 1, pos_y - 1};
    direction->pos3 = (position_t) {pos_x - 1, pos_y};
    direction->pos4 = (position_t) {pos_x - 1, pos_y + 1};
    direction->pos5 = (position_t) {pos_x, pos_y + 1};
    direction->pos6 = (position_t) {pos_x + 1, pos_y + 1};
    direction->pos7 = (position_t) {pos_x + 1, pos_y};
    direction->pos8 = (position_t) {pos_x + 1, pos_y - 1};
    check_positions(direction, x, y);
}

void get_east_direction(client_direction_t *direction, int x, int y)
{
    int pos_x = direction->pos0.x;
    int pos_y = direction->pos0.y;

    direction->pos1 = (position_t) {pos_x + 1, pos_y};
    direction->pos2 = (position_t) {pos_x + 1, pos_y - 1};
    direction->pos3 = (position_t) {pos_x, pos_y - 1};
    direction->pos4 = (position_t) {pos_x - 1, pos_y - 1};
    direction->pos5 = (position_t) {pos_x - 1, pos_y};
    direction->pos6 = (position_t) {pos_x - 1, pos_y + 1};
    direction->pos7 = (position_t) {pos_x, pos_y + 1};
    direction->pos8 = (position_t) {pos_x + 1, pos_y + 1};
    check_positions(direction, x, y);
}

void get_south_direction(client_direction_t *direction, int x, int y)
{
    int pos_x = direction->pos0.x;
    int pos_y = direction->pos0.y;

    direction->pos1 = (position_t) {pos_x, pos_y + 1};
    direction->pos2 = (position_t) {pos_x + 1, pos_y + 1};
    direction->pos3 = (position_t) {pos_x + 1, pos_y};
    direction->pos4 = (position_t) {pos_x + 1, pos_y - 1};
    direction->pos5 = (position_t) {pos_x, pos_y - 1};
    direction->pos6 = (position_t) {pos_x - 1, pos_y - 1};
    direction->pos7 = (position_t) {pos_x - 1, pos_y};
    direction->pos8 = (position_t) {pos_x - 1, pos_y + 1};
    check_positions(direction, x, y);
}

void get_west_direction(client_direction_t *direction, int x, int y)
{
    int pos_x = direction->pos0.x;
    int pos_y = direction->pos0.y;

    direction->pos1 = (position_t) {pos_x - 1, pos_y};
    direction->pos2 = (position_t) {pos_x - 1, pos_y + 1};
    direction->pos3 = (position_t) {pos_x, pos_y + 1};
    direction->pos4 = (position_t) {pos_x + 1, pos_y + 1};
    direction->pos5 = (position_t) {pos_x + 1, pos_y};
    direction->pos6 = (position_t) {pos_x + 1, pos_y - 1};
    direction->pos7 = (position_t) {pos_x, pos_y - 1};
    direction->pos8 = (position_t) {pos_x - 1, pos_y - 1};
    check_positions(direction, x, y);
}
