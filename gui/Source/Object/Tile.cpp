/*
** EPITECH PROJECT, 2023
** tile.cpp
** File description:
** Tile
*/

#include "Tile.hpp"
#include <iostream>
#include <ostream>

Tile::Tile()
{
    pos_.x = 0;
    pos_.y = 0.5f;
    pos_.z = 0;
    food_ = 0;
    linemate_ = 0;
    deraumere_ = 0;
    sibur_ = 0;
    mendiane_ = 0;
    phiras_ = 0;
    thystame_ = 0;
    egg_ = -1;
    _clicked = false;
}

Tile::Tile(int x, int y, int food, int line, int dera, int sib, int mend, int phir, int thys)
{
    pos_.x = x;
    pos_.y = 0.5f;
    pos_.z = y;
    food_ = food;
    linemate_ = line;
    deraumere_ = dera;
    sibur_ = sib;
    mendiane_ = mend;
    phiras_ = phir;
    thystame_ = thys;
    egg_ = -1;
    _clicked = false;
}

Tile::~Tile() {}

void Tile::setTile(Tile *tile)
{
    setPos(tile->getPos().x, tile->getPos().z);
    setFood(tile->getFood());
    setLinemate(tile->getLinemate());
    setDeraumere(tile->getDeraumere());
    setSibur(tile->getSibur());
    setMendiane(tile->getMendiane());
    setPhiras(tile->getPhiras());
    setThystame(tile->getThystame());
    setEgg(tile->getEgg());
}

void Tile::setPos(int x, int z)
{
    pos_.x = x;
    pos_.z = z;
}

void Tile::setResource(int resID, bool add)
{
    switch (resID) {
        case 0:
            if (add)
                setFood(getFood() + 1);
            else
                setFood(getFood() - 1);
            break;
        case 1:
            if (add)
                setLinemate(getLinemate() + 1);
            else
                setLinemate(getLinemate() - 1);
            break;
        case 2:
            if (add)
                setDeraumere(getDeraumere() + 1);
            else
                setDeraumere(getDeraumere() - 1);
            break;
        case 3:
            if (add)
                setSibur(getSibur() + 1);
            else
                setSibur(getSibur() - 1);
            break;
        case 4:
            if (add)
                setMendiane(getMendiane() + 1);
            else
                setMendiane(getMendiane() - 1);
            break;
        case 5:
            if (add)
                setPhiras(getPhiras() + 1);
            else
                setPhiras(getPhiras() - 1);
            break;
        case 6:
            if (add)
                setThystame(getThystame() + 1);
            else
                setThystame(getThystame() - 1);
            break;
    }
}

void Tile::setFood(int food)
{
    food_ = food;
}

void Tile::setLinemate(int linemate)
{
   linemate_ = linemate;
}

void Tile::setDeraumere(int deraumere)
{
    deraumere_ = deraumere;
}

void Tile::setSibur(int sibur)
{
    sibur_ = sibur;
}

void Tile::setMendiane(int mendiane)
{
    mendiane_ = mendiane;
}

void Tile::setPhiras(int mendiane)
{
    phiras_ = mendiane;
}

void Tile::setThystame(int thystame)
{
    thystame_ = thystame;
}

void Tile::setEgg(int egg)
{
    egg_ = egg;
}

Vector3 Tile::getPos(void)
{
    return pos_;
}

int Tile::getFood(void)
{
    return food_;
}

int Tile::getLinemate(void)
{
    return linemate_;
}

int Tile::getDeraumere(void)
{
    return deraumere_;
}

int Tile::getSibur(void)
{
    return sibur_;
}

int Tile::getMendiane(void)
{
    return mendiane_;
}

int Tile::getPhiras(void)
{
    return phiras_;
}

int Tile::getThystame(void)
{
    return thystame_;
}

int Tile::getEgg(void)
{
    return egg_;
}

void Tile::setFoodModel(Model model)
{
    _foodModel = model;
}

void Tile::setLinemateModel(Model model)
{
    _linemateModel = model;
}

void Tile::setDeraumereModel(Model model)
{
    _deraumereModel = model;
}

void Tile::setSiburModel(Model model)
{
    _siburModel = model;
}

void Tile::setMendianeModel(Model model)
{
    _mendianeModel = model;
}

void Tile::setPhirasModel(Model model)
{
    _phirasModel = model;
}

void Tile::setThystameModel(Model model)
{
    _thystameModel = model;
}

void Tile::setEggModel(Model model)
{
    _eggModel = model;
}

void Tile::printModelTile(void)
{
    if (food_ > 0)
        DrawModel(_foodModel, {pos_.x + 0.2f, pos_.y, pos_.z + 0.2f}, 0.8, WHITE);
    if (linemate_ > 0)
        DrawModel(_linemateModel, {pos_.x + 0.3f, pos_.y, pos_.z + 0.95f}, 0.035, GREEN);
    if (deraumere_ > 0)
        DrawModel(_deraumereModel, {pos_.x + 0.25f, pos_.y, pos_.z + 0.55f}, 0.035, ORANGE);
    if (sibur_ > 0)
        DrawModel(_siburModel, {pos_.x + 0.45f, pos_.y, pos_.z + 0.5f}, 0.035, YELLOW);
    if (mendiane_ > 0)
        DrawModel(_mendianeModel, {pos_.x + 0.9f, pos_.y, pos_.z + 0.15f}, 0.035, PURPLE);
    if (phiras_ > 0)
        DrawModel(_phirasModel, {pos_.x + 0.6f, pos_.y, pos_.z + 0.3f}, 0.035, RED);
    if (thystame_ > 0)
        DrawModel(_thystameModel, {pos_.x + 0.85f, pos_.y, pos_.z + 0.8f}, 0.035, BLUE);
    if (egg_ > 0)
        DrawModel(_eggModel, {pos_.x + 0.5f, pos_.y, pos_.z + 0.5f}, 1, WHITE);
}

void Tile::DrawUi()
{
    DrawRectangle( 10, 10, 320, 133, Fade(BLACK, 0.5f));
    DrawRectangleLines( 10, 10, 320, 133, BLACK);

    DrawText("Tile Pos: X: ", 20, 20, 10, WHITE);
    DrawText(std::to_string(pos_.x).c_str(), 120, 20, 10, WHITE);
    DrawText("Z: ", 130, 20, 10, WHITE);
    DrawText(std::to_string(pos_.z).c_str(), 150, 20, 10, WHITE);
    DrawText("Tile Ressources: ", 20, 40, 10, WHITE);
    DrawText("- Linemate:", 40, 60, 10, WHITE);
    DrawText("- Deraumere:", 40, 80, 10, WHITE);
    DrawText("- Sibur:", 40, 100, 10, WHITE);
    DrawText("- Mendiane:", 40, 120, 10, WHITE);
    DrawText("- Phyras:", 40, 140, 10, WHITE);
    DrawText("- Thystame:", 40, 160, 10, WHITE);
    DrawText("- Food:", 40, 180, 10, WHITE);
}

bool Tile::isClicked(void)
{
    return _clicked;
}

void Tile::debug(void)
{
    std::cout << "Tile X: " << pos_.x << " Z: " << pos_.z << std::endl;
    std::cout << "\tFood: " << food_ << std::endl;
    std::cout << "\tLinemate: " << linemate_ << std::endl;
    std::cout << "\tDeraumere: " << deraumere_ << std::endl;
    std::cout << "\tSibur: " << sibur_ << std::endl;
    std::cout << "\tMendiane: " << mendiane_ << std::endl;
    std::cout << "\tPhiras: " << phiras_ << std::endl;
    std::cout << "\tThystame: " << thystame_ << std::endl;
}
