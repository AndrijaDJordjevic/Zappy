/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** gui_cmd
*/

#ifndef GUI_CMD_H_
    #define GUI_CMD_H_
    #include "my_server.h"

void map_size(int fd, serv_t *serv, char **args);
void tile_content(int fd, serv_t *serv, char **args);
void tile_content_cmd_string(char *output, size_t outputSize, serv_t *serv,
char **xy);
void map_content(int fd, serv_t *serv, char **args);
void player_position(int fd, serv_t *serv, char **args);
void teams_name(int fd, serv_t *serv, char **args);
void player_level(int fd, serv_t *serv, char **args);
void player_inventory(int fd, serv_t *serv, char **args);
void time_unit_request(int fd, serv_t *serv, char **args);
void time_unit_update(int fd, serv_t *serv, char **args);
void broadcast_msg(int fd, serv_t *serv, char **args);
void ressource_dropping(int fd, serv_t *serv, char **args);
void ressource_picking(int fd, serv_t *serv, char **args);
void player_death(int fd, serv_t *serv, char **args);
void pie(serv_t *serv, position_t pos, bool status);
int pic(serv_t *serv, int *players, const client_t *client);
void smg(serv_t *serv, char *message);

#endif /* !GUI_CMD_H_ */
