/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** client_cmd_macros
*/

#ifndef CLIENT_CMD_MACROS_H_
    #define CLIENT_CMD_MACROS_H_
    #define OK "ok"
    #define KO "ko"
    #define IS_DIGIT(c) (c >= '0' && c <= '9')
    #define MAX_TILE_OUTPUT_LENGTH 100
    #define MAX_OUTPUT_LENGTH 10000
    #define DISPLAY_INVENTORY \
    "[food %d , linemate %d , deraumere %d , sibur %d , mendiane %d \
, phiras %d , thystame %d]\n"
    #define CHECK_POS(x1, x2, y1, y2) (x1 == x2 && y1 == y2)
    #include "player.h"
    #include "my_server.h"

typedef struct tile_content_s {
    serv_t *serv;
    char *str;
    int vision_side;
    enum orientation orientation;
    position_t pos;
} tile_content_t;

typedef struct {
    char *key;
    void (*cmd)(int, serv_t *, char **);
    enum time_unit time_unit;
} t_symstruct;

#endif /* !CLIENT_CMD_MACROS_H_ */
