/*
** EPITECH PROJECT, 2023
** tools
** File description:
** tool
*/

#include "client_cmd.h"
#include "player.h"
#include "my_server.h"
#include "macros.h"
#include <stdio.h>
#include <stdlib.h>

char* inttochar(int number)
{
    char* result = (char*)malloc(20 * sizeof(char));

    sprintf(result, "%d", number);
    return result;
}

int arraylen(char** array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return i;
}

void free_array(char **arr)
{
    if (arr == NULL)
        return;
    int size = arraylen(arr);

    for (int i = 0; i < size; i++) {
        if (arr[i] != NULL) {
            free(arr[i]);
            arr[i] = NULL;
        }
    }
    free(arr);
}

int get_team_index(params_t *param, char* team)
{
    for (int i = 0; param->names[i] != NULL; i++) {
        if (strcmp(param->names[i], team) == SUCCESS)
            return i;
    }
    return -1;
}
