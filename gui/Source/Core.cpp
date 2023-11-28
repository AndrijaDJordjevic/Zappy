/*
** EPITECH PROJECT, 2023
** gui [WSL: Ubuntu]
** File description:
** _map
*/

#include "Core.hpp"
#include <stdexcept>

Core::Core(Network& server, Broadcaster& caster): _server(server), _caster(caster)
{
}

Core::~Core()
{
    CloseWindow();
    UnloadMusicStream(this->_caster.getMusic());
    CloseAudioDevice();
}

int Core::run(void)
{
    this->_server.initializeData(this->_caster.getData());

    while (!WindowShouldClose())
    {
        if (this->_caster.updateNeeded()) {
            this->_server.updateData(this->_caster.getData());
        }
        if (!this->_caster.broadcast())
            break;
    }
    return 0;
}
