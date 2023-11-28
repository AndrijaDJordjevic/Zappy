/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** my_server
*/

#ifndef MY_SERVER_H_
    #define MY_SERVER_H_
    #include <sys/socket.h>
    #include <sys/select.h>
    #include <netinet/in.h>
    #include <stdbool.h>
    #include "map.h"

    typedef struct params_s {
        int port;
        int width;
        int height;
        char **names;
        int nbr_teams;
        int clients;
        int freq;
    } params_t;

    typedef struct sets_s {
        fd_set working_read_fds;
        fd_set working_write_fds;
        fd_set working_except_fds;
        fd_set master_read_fds;
        fd_set master_write_fds;
        fd_set master_except_fds;
    } sets_t;

    typedef struct serv_s {
        struct sockaddr_in address;
        int tcp_socket;
        sets_t sets;
        struct timeval timeout;
        int max_fd;
        size_t max_clients;
        client_t *clients;
        params_t *param;
        world map;
        egg_t **eggs;
        time_t ressources_time;
        int ressources_time_unit;
    } serv_t;

void display_help(void);
int error_handling(char** av, const int ac);
int handle_server(params_t *param);
int init_zappy(serv_t *server, int port);
void init_fd_sets(serv_t *serv);
void clear_fd_sets(sets_t *set, int fd);
void reset_fd_sets(sets_t *set, int freq, struct timeval *timeout);
int run_server(serv_t *server);
void handle_client_data(serv_t *server, int client_socket);
void handle_client_commands(int client_socket, char *command, serv_t *serv);
int send_message(int fd, const char *message, const char *what);
int initiate_map(serv_t *serv);
void handle_ressources_generation(serv_t *serv);
int arguments_handling(int argc, char **argv, params_t *params);
params_t default_params(void);
int is_params_valid(params_t *params);
bool get_singleton(bool mode);
char **str_to_word_array(const char *str);
int check_client_auth(serv_t *serv, int client_socket, char *team);
int arraylen(char** array);
void free_array(char** arr);
void handle_signint(int sig);
char* inttochar(int number);
int get_team_index(params_t *param, char* team);
int get_nbr_team( client_t *clients, int team, size_t max_client);
void pnw(client_t clt, int gui, int socket, params_t *param);
void pnw_client(serv_t *serv, int client_socket);
void send_pnw(serv_t *serv, int client_socket, char *team);
int get_gui_fd(client_t *clients, size_t max_clients);
void send_dead_client(serv_t *serv);
char* get_team_name(int team_index, params_t *param);
void add_client_team_egg(client_t *current_client, position_t position);
void handle_auth_case_egg(serv_t *serv, int client_socket, char *team,
client_t *clients);
void send_team_infos(int client_socket, serv_t *serv, int team_index);
void send_to_gui(serv_t *serv, char *message);
void countdown(int frequency, int time);
void check_cmd_queue(serv_t *serv);
void handle_players_life(serv_t *serv);
void shutdown_server(serv_t *serv);

#endif /* !MY_SERVER_H_ */
