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

Test(arguments_handling, success_flagh_g) {
    char* av[] = {
        "./zappy_server",
        "-f",
        "100",
        "-c",
        "10",
        "-n",
        "martin",
        "-y",
        "5",
        "-x",
        "5",
        "-p",
        "4243"
    };
    int ac = 13;
    params_t params = default_params();

    cr_assert_eq(arguments_handling(ac, av, &params), SUCCESS);
}

Test(arguments_handling, unknown_flag) {
        char* av[] = {
        "./zappy_server",
        "-y",
        "5",
        "-f",
        "100",
        "-p",
        "4243",
        "-z",
        "10",
        "-n",
        "martin",
        "hugo",
        "andrija",
        "louis",
        "jeremy"
        "-x",
        "5"
    };
    int ac = 17;
    params_t params = default_params();

    cr_assert_eq(arguments_handling(ac, av, &params), ERROR);
}

Test(arguments_handling, two_teams) {
        char* av[] = {
        "./zappy_server",
        "-y",
        "5",
        "-f",
        "100",
        "-p",
        "4243",
        "-c",
        "10",
        "-n",
        "martin",
        "hugo",
        "-x",
        "5"
    };
    int ac = 14;
    params_t params = default_params();

    cr_assert_eq(arguments_handling(ac, av, &params), SUCCESS);
}

Test(arguments_handling, six_teams) {
        char* av[] = {
        "./zappy_server",
        "-y",
        "5",
        "-f",
        "100",
        "-p",
        "4243",
        "-z",
        "10",
        "-n",
        "martin",
        "hugo",
        "andrija",
        "louis",
        "jeremy",
        "-x",
        "5"
    };
    int ac = 17;
    params_t params = default_params();

    cr_assert_eq(arguments_handling(ac, av, &params), ERROR);
}

Test(arguments_handling, one_arg_miss) {
        char* av[] = {
        "./zappy_server",
        "-y",
        "5",
        "-f",
        "100",
        "-p",
        "4243",
        "-n",
        "martin",
        "hugo",
        "andrija",
        "louis",
        "jeremy",
        "-x",
        "5"
    };
    int ac = 15;
    params_t params = default_params();

    cr_assert_eq(arguments_handling(ac, av, &params), SUCCESS);
}
