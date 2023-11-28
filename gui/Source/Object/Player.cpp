/*
** EPITECH PROJECT, 2023
** player.cpp
** File description:
** player
*/

#include "Player.hpp"
#include <iostream>
#include <ostream>

Player::Player()
{
    _message = "I am initialized";
    _invent.setInventory(10, 0, 0, 0, 0, 0, 0);
    _pos = {0, 0, 0};
    _level = 0;
}

Player::Player(int id, int x, int z, int level, int orient)
{
    _id = id;
    _pos = {float(x) + 0.5f, 0.9f, float(z) + 0.5f};
    _level = level;
    _state = IDLE;
    setOrient(orient);

    _model = LoadModel("gui/assets/models/temp_l.obj");
    _texture = LoadTexture("gui/assets/textures/char/texture_a.png");
    _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
    _ModelSet = true;
    std::cout << "Player " << id << ": Model set sucessfuly" << std::endl; 
}

Player::~Player() {}

void Player::destroyModel()
{
    if (_ModelSet == true) {
        UnloadModel(_model);
        std::cout << "Player " << _id << ": Model unload sucessfuly" << std::endl; 
        _ModelSet = false;
    }
}

void Player::setId(int id)
{
    _id = id;
}

void Player::setPos(int x, int z)
{
    _oldPos.x = _pos.x;
    _oldPos.z = _pos.z;
    _pos.x = float(x) + 0.5f;
    _pos.z = float(z) + 0.5f;

    std::cout << "PLAYER " << _id << ": pos X Y:" << _pos.x << " " << _pos.z << std::endl;
}

void Player::setLevel(int level)
{
    _level = level;
}


void Player::setOrient(int orient)
{
    switch (orient)
    {
        case 1:
            _orient = ORIENTATION::NORTH;
            _model.transform.m0 = 0.0f;
            _model.transform.m1 = 0.0f;
            _model.transform.m2 = 0.0f;
            _model.transform.m4 = 0.0f;
            _model.transform.m5 = 0.0f;
            _model.transform.m6 = 0.0f;
            _model.transform.m8 = 0.0f;
            _model.transform.m9 = 0.0f;
            _model.transform.m10 = 0.0f;
            break;
        case 2:
            _orient = ORIENTATION::EAST;
            _model.transform.m0 = 0.0f;
            _model.transform.m1 = 0.0f;
            _model.transform.m2 = 1.0f;
            _model.transform.m4 = 0.0f;
            _model.transform.m5 = 1.0f;
            _model.transform.m6 = 0.0f;
            _model.transform.m8 = -1.0f;
            _model.transform.m9 = 0.0f;
            _model.transform.m10 = 0.0f;
            break;
        case 3:
            _orient = ORIENTATION::SOUTH;
            _model.transform.m0 = -1.0f;
            _model.transform.m1 = 0.0f;
            _model.transform.m2 = 0.0f;
            _model.transform.m4 = 0.0f;
            _model.transform.m5 = 1.0f;
            _model.transform.m6 = 0.0f;
            _model.transform.m8 = 0.0f;
            _model.transform.m9 = 0.0f;
            _model.transform.m10 = -1.0f;
            break;
        case 4:
            _orient = ORIENTATION::WEST;
            _model.transform.m0 = 0.0f;
            _model.transform.m1 = 0.0f;
            _model.transform.m2 = -1.0f;
            _model.transform.m4 = 0.0f;
            _model.transform.m5 = 1.0f;
            _model.transform.m6 = 0.0f;
            _model.transform.m8 = 1.0f;
            _model.transform.m9 = 0.0f;
            _model.transform.m10 = 0.0f;
            break;
    }
}

void Player::setState(int state, std::string message)
{   
    switch (state)  
    {
        case -1:
            _state = PLAYERSTATE::DEAD;
            destroyModel();
            break;
        case 0:
            _state = PLAYERSTATE::IDLE;
            break;
        case 1:
            _state = PLAYERSTATE::INCANTING;
            break;
        case 2:
            _state = PLAYERSTATE::BROADCAST;
            _message = message;
            _start_time = std::chrono::steady_clock::now();
            break;
        case 3: 
            _state = PLAYERSTATE::RECEIVING;
            _start_time = std::chrono::steady_clock::now();
            break;
    }
}

void Player::setResource(int resID, bool add)
{
    switch (resID) {
        case 0:
            if (add)
                _invent.setFood(_invent.getFood() + 1);
            else
                _invent.setFood(_invent.getFood() - 1);
            break;
        case 1:
            if (add)
                _invent.setLinemate(_invent.getLinemate() + 1);
            else
                _invent.setLinemate(_invent.getLinemate() - 1);
            break;
        case 2:
            if (add)
                _invent.setDeraumere(_invent.getDeraumere() + 1);
            else
                _invent.setDeraumere(_invent.getDeraumere() - 1);
            break;
        case 3:
            if (add)
                _invent.setSibur(_invent.getSibur() + 1);
            else
                _invent.setSibur(_invent.getSibur() - 1);
            break;
        case 4:
            if (add)
                _invent.setMendiane(_invent.getMendiane() + 1);
            else
                _invent.setMendiane(_invent.getMendiane() - 1);
            break;
        case 5:
            if (add)
                _invent.setPhiras(_invent.getPhiras() + 1);
            else
                _invent.setPhiras(_invent.getPhiras() - 1);
            break;
        case 6:
            if (add)
                _invent.setThystame(_invent.getThystame() + 1);
            else
                _invent.setThystame(_invent.getThystame() - 1);
            break;
    }
}

int Player::getId() const
{
    return _id;
}

Vector3 Player::getPos() const
{
    return _pos;
}

int Player::getLevel() const
{
    return _level;
}

int Player::getOrient() const
{
    return _orient;
}

int Player::getState() const
{
    return _state;
}

std::string Player::getMessage() const
{
    return _message;
}

Model Player::getModel3D() const
{
    return _model;
}

void Player::DrawPlayer(int r, int g, int b)
{

    float scale = 0.002;
    Color colorTeam = (Color){ static_cast<unsigned char>(r), static_cast<unsigned char>(g), static_cast<unsigned char>(b), 255 };
    if (_state == INCANTING) {
        Color colors[14] = { ORANGE, RED, GOLD, LIME, BLUE, VIOLET, BROWN, LIGHTGRAY, PINK,
                         YELLOW, GREEN, SKYBLUE, PURPLE, BEIGE };
        DrawSphere(_pos, 0.5f, colors[GetRandomValue(0, 12)]);
        DrawModel(_model, _pos, scale, colorTeam);
    } else if (_state == DEAD) {
        destroyModel();
    } else {
        DrawModel(_model, _pos, scale, colorTeam);
        if (_state == BROADCAST) {
            _current_time = std::chrono::steady_clock::now();
            _elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(_current_time - _start_time).count();
            if (_elapsed_seconds >= 1)
                setState(1, "");
            DrawSphere( {_pos.x, _pos.y + 0.2f, _pos.z} , 1.0f, colorTeam);
        } else if (_state == RECEIVING) {
            _current_time = std::chrono::steady_clock::now();
            _elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(_current_time - _start_time).count();
            if (_elapsed_seconds >= 1 && _elapsed_seconds < 2)
                DrawSphere( {_pos.x, _pos.y + 0.2f, _pos.z}, 1.0f, RED);
            else if (_elapsed_seconds >= 2)
                setState(1, "");
        }
    }
}

void Player::DrawUi(std::string teamname)
{
    DrawRectangle( 10, 10, 320, 133, Fade(BLACK, 0.5f));
    DrawRectangleLines( 10, 10, 320, 133, BLACK);

    DrawText("Player ID: ", 20, 20, 10, WHITE);
    DrawText(std::to_string(_id).c_str(), 100, 20, 10, WHITE);
    DrawText("Player Level: ", 120, 20, 10, WHITE);
    DrawText(std::to_string(_level).c_str(), 230, 20, 10, WHITE);
    DrawText("Player Team:", 20, 40, 10, WHITE);
    DrawText(teamname.c_str(), 100, 40, 10, WHITE);
    DrawText("Player Inventory: ", 20, 60, 10, WHITE);
    DrawText("- Linemate:", 40, 80, 10, WHITE);
    DrawText("- Deraumere:", 40, 100, 10, WHITE);
    DrawText("- Sibur:", 40, 120, 10, WHITE);
    DrawText("- Mendiane:", 40, 140, 10, WHITE);
    DrawText("- Phyras:", 40, 160, 10, WHITE);
    DrawText("- Thystame:", 40, 180, 10, WHITE);
    DrawText("- Food:", 40, 200, 10, WHITE);
}

bool Player::isClicked()
{
    return _clicked;
}

bool Player::checkCollision()
{
    BoundingBox modelBounds = GetModelBoundingBox(_model);
    Rectangle rectangle = {
        modelBounds.min.x,
        modelBounds.min.y,
        modelBounds.max.x - modelBounds.min.x,
        modelBounds.max.y - modelBounds.min.y
    };

    Vector2 mousePosition = GetMousePosition();
    Vector2 mousePositionWindow = { mousePosition.x - GetWindowPosition().x, mousePosition.y - GetWindowPosition().y };

    if (CheckCollisionPointRec(mousePositionWindow, rectangle)) {
        std::cout << "--------------------------------------------------TOUCHED-----------------------------------" << std::endl;
        return true;
    }

    return false;
}

void Player::setInventory(int food, int line, int dera, int sib, int mend, int phir, int thys)
{
    _invent.setFood(food);
    _invent.setLinemate(line);
    _invent.setDeraumere(dera);
    _invent.setSibur(sib);
    _invent.setMendiane(mend);
    _invent.setPhiras(phir);
    _invent.setThystame(thys);
}

Inventory Player::getInventory() const
{
    return _invent;
}

void Player::resetTime()
{
    _elapsed_seconds = 0;
}

void Player::debug(void)
{
    std::cout << "Player: " << _id << std::endl;
    std::cout << "\tX: " << _pos.x << " Y: " << _pos.y << std::endl;
    std::cout << "\tFood: " << _invent.getFood() << std::endl;
    std::cout << "\tLinemate: " << _invent.getLinemate() << std::endl;
    std::cout << "\tDeraumere: " << _invent.getDeraumere() << std::endl;
    std::cout << "\tSibur: " << _invent.getSibur() << std::endl;
    std::cout << "\tMendiane: " << _invent.getMendiane() << std::endl;
    std::cout << "\tPhiras: " << _invent.getPhiras() << std::endl;
    std::cout << "\tThystame: " << _invent.getThystame() << std::endl;
}
