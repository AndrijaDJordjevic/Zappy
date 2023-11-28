/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** send_message
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>

int send_message(int fd, const char *message, const char *what)
{
    if (fd == -1) {
        fprintf(stderr, "Failed to send message: %s.\n", what);
        return -1;
    } else if (send(fd, message, strlen(message), 0) == -1) {
        fprintf(stderr, "Failed to send message: %s.\n", what);
        return -1;
    }
    return 0;
}
