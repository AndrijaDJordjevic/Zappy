/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** macros
*/

#ifndef MACROS_H_
    #define MACROS_H_
    #include <string.h>
    #define IS_ARG_HELP(arg) (strcmp(arg, "-help") == 0 || \
strcmp(arg, "-h") == 0)
    #define RESSOURCE_TIME_UNIT 20
    #define ERROR 84
    #define FULL 1
    #define OVERWRITE 0
    #define SUCCESS 0
    #define STDERR 2
    #define FLAG_H 1
    #define MAX_BUFF 1024
    #define AUTH -2
    #define INVALID_NB_ARGS \
"./zappy_server: Error, Invalid number of arguments, try './zappy_server -h'\n"
    #define SERV_WELCOME "WELCOME\n"
    #define SERV_DEAD "DEAD\n"
    #define SERV_KO "ko\n"
    #define SERV_OK "ok\n"
    #define SERV_SUC "suc\n"
    #define PLAYER_DEAD -1
#endif /* !MACROS_H_ */
