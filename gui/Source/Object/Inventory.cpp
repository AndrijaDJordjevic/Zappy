/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** Inventory
*/

#include "Inventory.hpp"

Inventory::Inventory() {}

Inventory::~Inventory() {}

void Inventory::setInventory(int food, int line, int dera, int sib, int mend, int phir, int thys)
{
    this->setFood(food);
    this->setLinemate(line);
    this->setDeraumere(dera);
    this->setSibur(sib);
    this->setMendiane(mend);
    this->setPhiras(phir);
    this->setThystame(thys);
}

void Inventory::setFood(int food)
{
    this->food_ = food;
}

void Inventory::setLinemate(int line)
{
    this->linemate_ = line;
}

void Inventory::setDeraumere(int dera)
{
    this->deraumere_ = dera;
}

void Inventory::setSibur(int sib)
{
    this->sibur_ = sib;
}

void Inventory::setMendiane(int mend)
{
    this->mendiane_ = mend;
}

void Inventory::setPhiras(int phir)
{
    this->phiras_ = phir;
}

void Inventory::setThystame(int thys)
{
    this->thystame_ = thys;
}


int Inventory::getFood()
{
    return this->food_;
}

int Inventory::getLinemate()
{
    return this->linemate_;
}

int Inventory::getDeraumere()
{
    return this->deraumere_;
}

int Inventory::getSibur()
{
    return this->sibur_;
}

int Inventory::getMendiane()
{
    return this->mendiane_;
}

int Inventory::getPhiras()
{
    return this->phiras_;
}

int Inventory::getThystame()
{
    return this->thystame_;
}