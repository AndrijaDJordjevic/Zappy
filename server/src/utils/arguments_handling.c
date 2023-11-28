/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** arguments_handling
*/
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "my_server.h"
#include "macros.h"

params_t default_params(void)
{
    params_t params;

    params.names = NULL;
    params.clients = -1;
    params.freq = -1;
    params.height = -1;
    params.width = -1;
    params.port = -1;
    params.nbr_teams = 0;
    return params;
}

int is_params_valid(params_t *params)
{
    if (params->names == NULL)
        return ERROR;
    if (params->clients <= 0 || params->freq <= 0 || params->port <= 0)
        return ERROR;
    if (params->height <= 0 || params->width <= 0)
        return ERROR;
    return SUCCESS;
}

static void argument_to_int(int option, params_t *params)
{
    switch (option) {
        case 'p':
            params->port = atoi(optarg);
            break;
        case 'x':
            params->width = atoi(optarg);
            break;
        case 'y':
            params->height = atoi(optarg);
            break;
        case 'c':
            params->clients = atoi(optarg);
            break;
        case 'f':
            params->freq = atoi(optarg);
        default:
            break;
    }
}

static void get_teams_name(int argc, char**argv, params_t *params)
{
    int count = 0;

    optind--;
    while (optind < argc && *argv[optind] != '-') {
        params->names = realloc(params->names, sizeof(char *) * (count + 1));
        if (params->names == NULL)
            break;
        params->names[count] = malloc(strlen(argv[optind]) + 1);
        if (params->names[count] == NULL)
            break;
        strcpy(params->names[count], argv[optind]);
        params->nbr_teams++;
        count++;
        optind++;
    }
    params->names = realloc(params->names, sizeof(char *) * (count + 2));
    if (params->names != NULL) {
        params->names[count] = strdup("GRAPHIC");
        params->names[count + 1] = NULL;
    }
}

int arguments_handling(int argc, char **argv, params_t *params)
{
    int option;

    while ((option = getopt(argc, argv, "p:x:y:n:c:f:")) != -1)
        switch (option) {
            case 'p':
            case 'x':
            case 'y':
            case 'c':
            case 'f':
                argument_to_int(option, params);
                break;
            case 'n':
                get_teams_name(argc, argv, params);
                break;
            default:
                return ERROR;
        }
    if (params->freq <= 0)
        return ERROR;
    return SUCCESS;
}
