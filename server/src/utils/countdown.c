/*
** EPITECH PROJECT, 2023
** count
** File description:
** down
*/

#include "my_server.h"
#include "map.h"
#include "macros.h"
#include "player.h"
#include <stdio.h>
#include <time.h>

void countdown(int frequency, int time)
{
    int seconds = time / frequency;
    clock_t start_time = clock();
    double elapsed_seconds = 0;

    while (elapsed_seconds < seconds) {
        clock_t current_time = clock();
        elapsed_seconds = (double)(current_time - start_time) / CLOCKS_PER_SEC;
    }
    printf("%d seconds have passed.\n", seconds);
}
