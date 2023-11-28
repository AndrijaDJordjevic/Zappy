/*
** EPITECH PROJECT, 2023
** error
** File description:
** error
*/

#include "macros.h"
#include "my_server.h"
#include <stdio.h>

int error_handling(char** av, const int ac)
{
    if (ac == 2 && IS_ARG_HELP(av[1])) {
        display_help();
        return FLAG_H;
    } else if (ac < 11) {
        fprintf(stderr, INVALID_NB_ARGS);
        return ERROR;
    }
    return SUCCESS;
}
