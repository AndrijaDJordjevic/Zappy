/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** client_cmd
*/

#ifndef CLIENT_CMD_H_
    #define CLIENT_CMD_H_
    #include "my_server.h"
    #include "client_cmd_macros.h"

typedef struct incantation_s {
    client_t *client;
    inventory_t mandatory;
    inventory_t current_tile;
    int *player_lst;
    int fd;
    int nbr_max;
} incantation_t;

void forward_command(int client_socket, serv_t *serv, char **args);
void right_command(int client_socket, serv_t *serv, char **args);
void left_command(int client_socket, serv_t *serv, char **args);
void look_command(int client_socket, serv_t *serv, char **args);
void inventory_command(int client_socket, serv_t *serv, char **args);
void broadcast_command(int client_socket, serv_t *serv, char **args);
void connect_nbr_command(int client_socket, serv_t *serv, char **args);
void fork_command(int client_socket, serv_t *serv, char **args);
void eject_command(int client_socket, serv_t *serv, char **args);
void take_command(int client_socket, serv_t *serv, char **args);
void set_command(int client_socket, serv_t *serv, char **args);
void incantation_command(int client_socket, serv_t *serv, char **args);

const t_symstruct *available_gui_commands(int *size);
const t_symstruct *available_client_cmd(int *size);

void get_next_tile_width(enum orientation orientation, position_t *next_tile,
int width, int height);
void get_next_tile_line(enum orientation orientation, int width, int height,
position_t *next_tile);
char *get_tile_content(inventory_t item, serv_t *serv, int fd);
void move_player_forward(enum orientation orientation, position_t *pos,
int x, int y);
enum ressource get_ressource_index(char *arg);
bool check_take_set_args(char *arg);
int my_strlen_2d(char **args);

void incan_lvl_2(serv_t* serv, int fd);
void incan_lvl_3(serv_t *serv, int fd);
void incan_lvl_4(serv_t *serv, int fd);
void incan_lvl_5(serv_t *serv, int fd);
void incan_lvl_6(serv_t *serv, int fd);
void incan_lvl_7(serv_t *serv, int fd);
void incan_lvl_8(serv_t *serv, int fd);
inventory_t get_tile_ressources(position_t tile, world map);
bool check_incantation(const inventory_t *mandatory,
const inventory_t *ressource);
void get_inc_nbr_player_lvl(int *player_lst, serv_t *serv, int max, int lvl);
int int_lst_len(int *lst);
void loop_lvl_up_players(client_t *lst, int *player_lst, size_t max_clients);
void remove_ressource_incantation(world map, position_t pos,
inventory_t mandatory);
void handle_cmd_queue(client_t *client, const t_symstruct new_cmd,
char **command);
void message_elevation(char *error, int fd, client_t *client);
inventory_t get_mandatory_lvl2(void);
inventory_t get_mandatory_lvl3(void);
inventory_t get_mandatory_lvl4(void);
inventory_t get_mandatory_lvl5(void);
inventory_t get_mandatory_lvl6(void);
inventory_t get_mandatory_lvl7(void);
inventory_t get_mandatory_lvl8(void);
inventory_t get_mandatory_lvl(int lvl);

void get_north_direction(client_direction_t *direction, int x, int y);
void get_east_direction(client_direction_t *direction, int x, int y);
void get_west_direction(client_direction_t *direction, int x, int y);
void get_south_direction(client_direction_t *direction, int x, int y);
int get_direction(client_t *emitter, client_t receiver, int map_x, int map_y);
int find_best_direction(position_t *, client_direction_t *, int, int);
int get_shorter_way(int emitter, int receiver, int map_size);
int get_best_horizontal_axis_way(position_t *emitter, client_direction_t *recv,
int *map_size);
int get_best_vertical_axis_way(position_t *emitter, client_direction_t *recv,
int *map_size);
int get_best_diagonal_way(position_t *emitter, client_direction_t *recv,
int x, int y);
int inc_check_var(int fd, serv_t *serv);
void incantations_mandatory(serv_t *serv, int fd, int nbr_max);
#endif /* !CLIENT_CMD_H_ */
