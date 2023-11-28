/*
** EPITECH PROJECT, 2023
** array
** File description:
** test
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "macros.h"
#include <stdio.h>
#include "my_server.h"

Test(str_to_word_array, basic) {
    const char* str = "hello word";
    char** test = str_to_word_array(str);

    cr_assert_neq(test[0], "test");
}

Test(str_to_word_array, noting) {
    const char* str = "";
    char** test = str_to_word_array(str);

    cr_assert_neq(test[0], "test");
}
