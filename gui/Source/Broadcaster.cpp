/*
** EPITECH PROJECT, 2023
** Menu.cpp
** File description:
** Menu
*/
#include "Broadcaster.hpp"

Broadcaster::Broadcaster(Game& game, Menu& menu): _game(game), _menu(menu)
{
    this->_activeScene = SCENE::MENU;
    this->_windowWidth = DEFAULT_CAMERA_WIDTH;
    this->_windowHeight = DEFAULT_CAMERA_HEIGHT;

    InitWindow(this->_windowWidth, this->_windowHeight, "Zappy");
    SetTargetFPS(60);

    InitAudioDevice();
    this->_music = LoadMusicStream(PATH_TO_MUSIC);
    this->_music.looping = true;
    PlayMusicStream(this->_music);

    this->_menu.initScene();
    this->_game.initScene();
}

Broadcaster::~Broadcaster() { }

void Broadcaster::navigate(void)
{
    if (this->_activeScene == SCENE::GAME && this->_game.changeSceneRequested())
        this->_activeScene = SCENE::MENU;
    else if (this->_activeScene == SCENE::MENU && this->_menu.changeSceneRequested())
        this->_activeScene = SCENE::GAME;
}

Music& Broadcaster::getMusic(void)
{
    return this->_music;
}

bool Broadcaster::broadcast(void)
{
    UpdateMusicStream(this->_music);
    if (this->_activeScene == SCENE::GAME) {
        this->_game.display();
        this->_game.handleEvent();
        if (this->_game.closeWindowRequested())
            return false;
    }
    else {
        this->_menu.display();
        this->_menu.handleEvent();
        if (this->_menu.closeWindowRequested())
            return false;
    }
    this->navigate();
    return true;
}

bool Broadcaster::updateNeeded(void) const
{
    return this->_activeScene == SCENE::GAME;
}

DataManager& Broadcaster::getData(void)
{
    return this->_game.getData();
}
