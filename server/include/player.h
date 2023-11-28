/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** player
*/

#ifndef _PLAYER_H
    #define _PLAYER_H
    #include <stdbool.h>
    #define DEFAULT_LIFE 10
    #define DEFAULT_MAX_CLIENT_CMD 10
    #define CLIENT_LIST_SIZE_INCREMENT 8
    #define NB_POS_AROUND_PLAYER 8
    #include <time.h>
    #include "time_management.h"
    #include <sys/select.h>

enum ressource {
    NONE = -1,
    FOOD = 0,
    LINEMATE = 1,
    DERAUMERE = 2,
    SIBUR = 3,
    MENDIANE = 4,
    PHIRAS = 5,
    THYSTAME = 6
};

enum orientation {
    N = 1,
    E = 2,
    S = 3,
    W = 4
};

enum client_type {
    PLAYER,
    GRAPHIC,
    UNKNOWN
};

typedef struct inventory_s {
    int food;
    int linemate;
    int deraumere;
    int sibur;
    int mendiane;
    int phiras;
    int thystame;
} inventory_t;

typedef struct position_s {
    int x;
    int y;
} position_t;

typedef struct serv_s serv_t;
typedef struct sets_s sets_t;

typedef struct args_link_s {
    char **args;
    struct args_link_s *next;
} args_link_t;

typedef struct client_direction_s {
    position_t pos0;
    position_t pos1;
    position_t pos2;
    position_t pos3;
    position_t pos4;
    position_t pos5;
    position_t pos6;
    position_t pos7;
    position_t pos8;
} client_direction_t;

typedef struct client_cmd_queue_s {
    int cmd_nbr;
    void (*cmd[DEFAULT_MAX_CLIENT_CMD])(int, struct serv_s *, char **);
    args_link_t *args_link;;
    enum time_unit time_unit[DEFAULT_MAX_CLIENT_CMD];
} client_cmd_queue_t;

typedef struct client_s {
    enum client_type client_type;
    position_t pos;
    inventory_t inventory;
    enum orientation orientation;
    int fd;
    int level;
    int egg_nbr;
    int life;
    int team_index;
    int time_unit;
    client_cmd_queue_t client_cmd_queue;
    time_t action_time;
    time_t survival_time;
} client_t;

typedef struct player_infos_s {
    int index;
    int time;
    int fd;
    int x;
    int y;
} player_infos_t;

typedef struct egg_s {
    int team_index;
    int id;
    position_t position;
} egg_t;

client_t *new_client(client_t *current_list, serv_t *serv, int fd);
client_t init_new_client(int fd, serv_t *serv);
void overwrite_client(client_t *client, serv_t *serv, int fd);
client_t *get_client_by_fd(client_t *clients, int fd, size_t max_clients);
client_t *get_client_by_team(client_t *clients, int team_id, serv_t *serv);
void kill_clients(client_t *clients, size_t max_clients, sets_t *set);
void kill_this_client(client_t *client, sets_t *set, int gui_fd);
position_t get_random_position(int width, int height);
int handle_new_connection(serv_t *server);


void free_cmd_queue(client_cmd_queue_t *cmd_queue);

int add_egg_to_team(egg_t*** eggs, const int team_index, int x, int y);
egg_t* find_egg(egg_t** eggs, int team_index);
int remove_egg_position(egg_t** eggs, int x, int y);
void free_all_eggs(egg_t** eggs);
void printEggs(const egg_t** eggs);
egg_t init_new_egg(int team_index, int x, int y, int id);
int count_eggs_in_team(const egg_t** eggs, int team_index);
egg_t** initialize_eggs(void);

#endif
