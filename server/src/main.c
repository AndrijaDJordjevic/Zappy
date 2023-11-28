/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** main
*/
#include <stdlib.h>
#include "macros.h"
#include "my_server.h"

static void free_2d_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; ++i) {
        free(array[i]);
    }
    free(array);
}

int main (int ac, char **av)
{
    params_t params = default_params();
    int ret = 0;

    switch (error_handling(av, (const int)ac)) {
        case FLAG_H:
            return SUCCESS;
        case ERROR:
            return ERROR;
        default:
            break;
    }
    if (arguments_handling(ac, av, &params) == ERROR) {
        free_2d_array(params.names);
        return ERROR;
    }
    if (is_params_valid(&params) == ERROR)
        return ERROR;
    ret = handle_server(&params);
    free_2d_array(params.names);
    return ret;
}
