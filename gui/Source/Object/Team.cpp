/*
** EPITECH PROJECT, 2023
** team.cpp
** File description:
** team
*/

#include "Team.hpp"
#include "Player.hpp"
#include <stdexcept>
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <cstdlib>

Team::Team()
{
    _teamname = "Team";
    r = rand() % 255;
    g = rand() % 255;
    b = rand() % 255;
}

Team::Team(std::string name)
{
    _teamname = name;
    r = rand() % 255;
    g = rand() % 255;
    b = rand() % 255;
}

Team::~Team()
{
}

void Team::addPlayer(Player player)
{
    _players.push_back(player);
}

void Team::setPlayerPos(int x, int y, int orient, int id)
{
    for (auto &it : _players)
        if (it.getId() == id) {
            it.setPos(x, y);
            it.setOrient(orient);
        }
}

void Team::removePlayer(Player player)
{
    for (auto it = _players.begin(); it!= _players.end(); it++) {
        if (it->getId() == player.getId()) {
            it->setState(DEAD, nullptr);
            break;
        }
    }
}

void Team::setTeam(Team *team)
{
    setPlayers(team->getAllPlayers());
    setTeamname(team->getTeamname());
}

std::string Team::getTeamname(void) const
{
    return _teamname;
}

std::vector<Player> Team::getAllPlayers(void) const
{
    return _players;
}

Player Team::getPlayer(int id)
{
    for (auto it = _players.begin(); it!= _players.end(); it++)
        if ((*it).getId() == id)
            return *it;
    throw std::out_of_range("Player Not Found");
}

bool Team::isPlayer(int id)
{
    for (auto it = _players.begin(); it!= _players.end(); it++)
        if ((*it).getId() == id)
            return true;
    return false;
}

void Team::debug(void)
{
    std::cout << "Team name: " << _teamname << std::endl;
    for (auto it : _players) {
        std::cout << '\t';
        it.debug();
    }
}

void Team::displayTeamPlayer()
{
    for (auto it = _players.begin(); it != _players.end(); ) {
        if (it->getState() == -1) {
            it = _players.erase(it);
        } else {
            it->DrawPlayer(r, g, b);
            ++it;
        }
    }
}

void Team::end(void)
{
    std::cout << "Freeing all team" << _teamname << "players: START" << std::endl;
    for (int i = _players.size(); i > 0; i--) {
        _players.pop_back();
        std::cout << "\tPlayer freed" << std::endl;
    }
    std::cout << "Freeing all team" << _teamname << "players: SUCCESS. No errors detected" << std::endl;
    std::cout << "Freeing all team" << _teamname << "players: END" << std::endl;
}