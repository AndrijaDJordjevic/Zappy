/*
** EPITECH PROJECT, 2023
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "macros.h"
#include "my_server.h"


Test(is_params_valid, default_param) {
    params_t params = default_params();

    cr_assert_eq(is_params_valid(&params), ERROR);
}

Test(is_params_valid, good_param_one_team) {
    char* teams[] = {
        "martin",
        NULL
    };
    params_t params = default_params();
    params.names = teams;
    params.clients = 4;
    params.freq = 100;
    params.height = 5;
    params.width = 5;
    params.port = 4242;
    params.nbr_teams = 10;

    cr_assert_eq(is_params_valid(&params), SUCCESS);
}

Test(is_params_valid, good_param_two_team) {
    char* teams[] = {
        "martin",
        "andrija",
        NULL
    };
    params_t params = default_params();
    params.names = teams;
    params.clients = 4;
    params.freq = 100;
    params.height = 5;
    params.width = 5;
    params.port = 4242;
    params.nbr_teams = 10;

    cr_assert_eq(is_params_valid(&params), SUCCESS);
}

Test(is_params_valid, wrong_param) {
    char* teams[] = {
        "martin",
        "andrija",
        NULL
    };
    params_t params = default_params();
    params.names = teams;
    params.clients = 4;
    params.freq = -1;
    params.height = 5;
    params.width = 5;
    params.port = 4242;
    params.nbr_teams = 10;

    cr_assert_eq(is_params_valid(&params), ERROR);
}
