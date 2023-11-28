/*
** EPITECH PROJECT, 2023
** server
** File description:
** test
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "macros.h"
#include "my_server.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

Test(handle_server, wrong_port) {
    params_t param;
    char *names[] = {
        "team1",
        "team2",
        NULL
    };
    param.port = 80;
    param.width = 5;
    param.height = 5;
    param.names = names;
    param.nbr_teams = 2;
    param.clients = 0;
    param.freq = 100;
    cr_assert_eq(handle_server(&param), ERROR);
}
