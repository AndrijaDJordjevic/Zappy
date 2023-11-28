/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** my_strlen_2d
*/

#include <stdio.h>
#include "client_cmd.h"

int my_strlen_2d(char **args)
{
    int i = 0;

    if (!args)
        return -1;

    for (;args[i] != NULL; i++);
    return i;
}
