/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** Map
*/

#include "DataManager.hpp"
#include <iostream>

DataManager::DataManager() { }

DataManager::~DataManager() { }

void DataManager::addTeam(Team team)
{
    _teams.push_back(team);
}

void DataManager::addTile(Tile tile)
{
    tile.setFoodModel(_resourceManager.GetFoodModel());
    tile.setLinemateModel(_resourceManager.GetLinemateModel());
    tile.setDeraumereModel(_resourceManager.GetDeraumereModel());
    tile.setSiburModel(_resourceManager.GetSiburModel());
    tile.setMendianeModel(_resourceManager.GetMendianeModel());
    tile.setPhirasModel(_resourceManager.GetPhirasModel());
    tile.setThystameModel(_resourceManager.GetThystameModel());
    tile.setEggModel(_resourceManager.GetEggModel());

    _tiles.push_back(tile);
}

void DataManager::addPlayerTeam(Player player, std::string teamname)
{
    for (auto &it : _teams) {;
        if (it.getTeamname() == teamname)
            it.addPlayer(player);
    }
}

void DataManager::addEgg(int x, int y, int egg)
{
    for (auto &tile : _tiles) 
    {
        if (tile.getPos().x == x && tile.getPos().y == y)
            tile.setEgg(egg);
    }
}

void DataManager::setTeam(Team team)
{
    std::string teamname = team.getTeamname();
    for (auto& it : _teams) {
        if (it.getTeamname() == teamname) {
            it.setTeam(&team);
            return;
        }
    }
}

void DataManager::setPosPlayer(int x, int y, int orient, int id)
{
    for (auto &it : _teams)
        it.setPlayerPos(x, y, orient, id);
}

void DataManager::setTile(Tile tile)
{
    for (auto& it : _tiles) {
        if (it.getPos().x == tile.getPos().x 
        && it.getPos().y == tile.getPos().y) {
            it.setTile(&tile);
            return;
        }
    }
}

void DataManager::setSize(Vector2 size)
{
    _map.setSize(size);
}

void DataManager::setUnitReq(int value)
{
    _timeUnit = value;
}

Player DataManager::getPlayer(int id)
{
    for (auto &team : _teams) {
        if (team.isPlayer(id))
            return team.getPlayer(id);
    }
    throw std::out_of_range("Player Not Found");
}

Team DataManager::getTeam(std::string name)
{
    for (auto &team : _teams) {
        if (team.getTeamname() == name)
            return team;
    }
    throw std::out_of_range("Team Not Found");
}

Tile DataManager::getTile(int x, int z)
{
    for (auto &tile : _tiles) {
        if (tile.getPos().x == x && tile.getPos().z == z)
            return tile;
    }
    throw std::out_of_range("Tile Not Found");
}

Vector2 DataManager::getSize(void)
{
    return _map.getSize();
}

int DataManager::getUnitReq(void)
{
    return _timeUnit;
}

std::vector<Team> DataManager::getAllTeams()
{
    return _teams;
}


std::vector<Tile> DataManager::getAllTiles()
{
    return _tiles;
}

bool DataManager::isTile(int x, int y)
{
    for (auto &tile : _tiles) {
        if (tile.getPos().x == x && tile.getPos().y == y)
            return (true);;
    }
    return (false);
}

bool DataManager::isTeam(std::string name)
{
    for (auto &team : _teams) {
        if (team.getTeamname() == name)
            return (true);
    }
    return (false);
}

void DataManager::displayTeamPlayer()
{
    for (auto team : getAllTeams())
        team.displayTeamPlayer();
}

void DataManager::displayAllTiles()
{
    for (auto tile : getAllTiles())
        tile.printModelTile();
}

void DataManager::displayMap()
{
    _map.drawMap();
}

void DataManager::Clicked()
{
    for (auto team : getAllTeams())
        for (auto player : team.getAllPlayers())
            if (player.isClicked())
                player.DrawUi(team.getTeamname());
    for (auto tile : getAllTiles())
        if (tile.isClicked())
            tile.DrawUi();
}

void DataManager::eject(int id, int orient, int x, int y)
{
    for (auto &team : _teams) {
        for (auto &player : team.getAllPlayers()) {
            if (player.getPos().x == x && player.getPos().y == y && player.getId() != id) {
                switch (orient) {
                    case 1:
                        if (player.getPos().y == _map.getSize().x)
                            player.setPos(player.getPos().x, 0);
                        else
                            player.setPos(player.getPos().x, player.getPos().y + 1);
                        break;
                    case 2:
                        if (player.getPos().x == _map.getSize().y)
                            player.setPos(0, player.getPos().y);
                        else
                            player.setPos(player.getPos().x + 1, player.getPos().y);
                        break;
                    case 3:
                        if (player.getPos().y == 0)
                            player.setPos(player.getPos().x, _map.getSize().x);
                        else
                            player.setPos(player.getPos().x, player.getPos().y - 1);
                        break;
                    case 4:
                        if (player.getPos().x == 0)
                            player.setPos(_map.getSize().y, player.getPos().y);
                        else
                            player.setPos(player.getPos().x - 1, player.getPos().y);
                        break;
                }
            }
        }
    }
}

void DataManager::LoadAllModel()
{
    _resourceManager.LoadResources();
}


void DataManager::UnloadAllModel()
{
    _resourceManager.UnloadResources();
}

void DataManager::Debug()
{
    for (auto team : getAllTeams())
        team.debug();
    for (auto tile : getAllTiles())
        tile.debug();
}
