/*
** EPITECH PROJECT, 2023
** test
** File description:
** tes
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "macros.h"
#include "my_server.h"

Test(get_singleton, false_singleton) {
    bool status = false;

    cr_assert_eq(get_singleton(status), true);
}

Test(get_singleton, true_singleton) {
    bool status = true;

    cr_assert_eq(get_singleton(status), false);
}
