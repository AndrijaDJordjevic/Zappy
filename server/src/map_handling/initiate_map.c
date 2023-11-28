/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** initiate_map
*/

#include "my_server.h"
#include "macros.h"

int initiate_map(serv_t *serv)
{
    if (!serv) {
        fprintf(stderr, "Error: the server is null.\n");
        return ERROR;
    }
    serv->map = create_map(serv->param->width, serv->param->height);

    if (!serv->map) {
        fprintf(stderr, "Error: the map couldn't be created.\n");
        return ERROR;
    }
    serv->map = generate_world_ressources(serv->map,
    serv->param->width, serv->param->height);
    serv->ressources_time = time(NULL);
    return SUCCESS;
}

void handle_ressources_generation(serv_t *serv)
{
    time_t current_time = time(NULL);

    if (current_time - serv->ressources_time >= serv->ressources_time_unit) {
        serv->map = generate_world_ressources(serv->map,
        serv->param->width, serv->param->height);
        serv->ressources_time = current_time;
    }
}
