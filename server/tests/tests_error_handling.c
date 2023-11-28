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


Test(error_handling, success_flagh_g) {
    char* av[] = {
        "./zappy_server",
        "-help"
    };
    int ac = 2;

    cr_assert_eq(error_handling(av, ac), FLAG_H);
}

Test(error_handling, standard_command) {
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

    cr_assert_eq(error_handling(av, ac), SUCCESS);
}

Test(error_handling, other_standard_command) {
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
        "-x",
        "5"
    };
    int ac = 13;

    cr_assert_eq(error_handling(av, ac), SUCCESS);
}

Test(error_handling, no_flag) {
    char* av[] = {
        "./zappy_server"
    };
    int ac = 1;

    cr_assert_eq(error_handling(av, ac), ERROR);
}

Test(error_handling, two_teams) {
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

    cr_assert_eq(error_handling(av, ac), SUCCESS);
}

Test(error_handling, six_teams) {
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
        "andrija",
        "louis",
        "jeremy"
        "-x",
        "5"
    };
    int ac = 18;

    cr_assert_eq(error_handling(av, ac), SUCCESS);
}

Test(error_handling, one_flag) {
        char* av[] = {
        "./zappy_server",
        "-y",
        "5"
    };
    int ac = 3;

    cr_assert_eq(error_handling(av, ac), ERROR);
}

Test(error_handling, no_flag_xy) {
        char* av[] = {
        "./zappy_server",
        "-f",
        "100",
        "-p",
        "4243",
        "-c",
        "10",
        "-n",
        "martin",
        "hugo"
    };
    int ac = 10;

    cr_assert_eq(error_handling(av, ac), ERROR);
}
