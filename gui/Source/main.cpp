/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** main
*/

extern "C" {
    #include <unistd.h>
}
#include <cstring>
#include <stdlib.h>
#include <memory>
#include "Map.hpp"
#include "Core.hpp"
#include "Macros.hpp"
#include "Broadcaster.hpp"
#include "Menu.hpp"
#include "Game.hpp"


void displayHelp()
{
    std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
}

int startGui(int port, const char* machine)
{
    Network network(port, machine);
    Game game;
    Menu menu;
    Broadcaster caster(game, menu);


    Core core(network, caster);
    core.run();
    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    srand(time(NULL));
    const char* machine = LOCALHOST;
    int port = 0;

    if (IS_ARG_HELP) {
        displayHelp();
        return EXIT_SUCCESS;
    }

    for (int i = 1; i < argc; i++) {
        if (std::strcmp(argv[i], "-p") == 0 && i + 1 < argc) {
            port = std::atoi(argv[i + 1]);
            i++;
        } else if (std::strcmp(argv[i], "-h") == 0 && i + 1 < argc) {
            machine = argv[i + 1];
            i++;
        } else {
            std::cerr << "Invalid arguments" << std::endl;
            displayHelp();
            return EXIT_FAILURE;
        }
    }

    if (port == 0) {
        std::cerr << "Missing port argument" << std::endl;
        displayHelp();
        return EXIT_FAILURE;
    }
    return startGui(port, machine);
}
