/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
    this->_changeScene = false;
    _camera.position = (Vector3){5.0f, 5.0f, 5.0f};
    _camera.target = (Vector3){0.0f, 2.0f, 0.0f};
    _camera.up = (Vector3){0.0f, 3.0f, 0.0f};
    _camera.fovy = 45.0f;
    _camera.projection = CAMERA_PERSPECTIVE;
}

Game::~Game()
{
    _data.UnloadAllModel();
}

void Game::display()
{
    UpdateCamera(&_camera, CAMERA_FIRST_PERSON);
    ClearBackground(RAYWHITE);

    BeginDrawing();
    DrawFPS(10, 10);
    BeginMode3D(_camera);

    _data.displayMap();
    _data.displayAllTiles();
    _data.displayTeamPlayer();

    EndMode3D();
    EndDrawing();
}

void Game::handleEvent()
{
    if (IsKeyDown(KEY_ESCAPE) || IsKeyDown(KEY_P))
        _changeScene = true;
}

bool Game::changeSceneRequested()
{
    if (this->_changeScene) {
        this->_changeScene = false;
        return true;
    } else
        return false;
}

void Game::initScene(void)
{
    this->_data.LoadAllModel();
}   

DataManager& Game::getData(void)
{
    return this->_data;
}

bool Game::closeWindowRequested(void)
{
    return false;
}
