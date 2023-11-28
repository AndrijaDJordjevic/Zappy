/*
** EPITECH PROJECT, 2023
** parser.cpp
** File description:
** parser
*/

#include "Parser.hpp"
#include <iostream>
#include <sstream>

Parser::Parser() {}

Parser::~Parser() {}

std::vector<std::string> Parser::splitMessage(const std::string& message, char delimiter)
{
    std::vector<std::string> result;
    std::string::size_type start = 0;
    std::string::size_type end = message.find(delimiter);

    while (end != std::string::npos)
    {
        result.push_back(message.substr(start, end - start));
        start = end + 1;
        end = message.find(delimiter, start);
    }

    result.push_back(message.substr(start));

    return result;
}

std::string Parser::splitAndTake(const std::string& message, char delimiter, int nbr_pos)
{
    std::vector<std::string> str = splitMessage(message, delimiter);

    return str[nbr_pos];
}

std::map<std::string, std::function<DataManager(const std::string&, DataManager)>> Parser::setupMap(void)
{
    std::map<std::string, std::function<DataManager(const std::string&, DataManager)>> commandAction;

    auto assignLambda = [this](std::function<DataManager(const std::string&, DataManager)>& func,DataManager (Parser::*memberFunc)(std::string, DataManager)) {
            func = [this, memberFunc](const std::string& value, DataManager map) { return (this->*memberFunc)(value, map); };
        };

    assignLambda(commandAction["msz"], &Parser::setMapSize);
    assignLambda(commandAction["msz"], &Parser::setMapSize);
    assignLambda(commandAction["bct"], &Parser::tileContent);
    assignLambda(commandAction["tna"], &Parser::setTeamNames);
    assignLambda(commandAction["pnw"], &Parser::newPlayer);
    assignLambda(commandAction["ppo"], &Parser::posPlayer);
    assignLambda(commandAction["plv"], &Parser::lvlPlayer);
    assignLambda(commandAction["pin"], &Parser::invPlayer);
    assignLambda(commandAction["pex"], &Parser::expPlayer);
    assignLambda(commandAction["pbc"], &Parser::msgPlayer);
    assignLambda(commandAction["pic"], &Parser::incPlayer);
    assignLambda(commandAction["pie"], &Parser::incEndPlayer);
    assignLambda(commandAction["pfk"], &Parser::eggPlayer);
    assignLambda(commandAction["pdr"], &Parser::resDropPlayer);
    assignLambda(commandAction["pgt"], &Parser::resGetPlayer);
    assignLambda(commandAction["pdi"], &Parser::deathPlayer);
    assignLambda(commandAction["enw"], &Parser::eggByPlayer);
    assignLambda(commandAction["ebo"], &Parser::eggConnection);
    assignLambda(commandAction["edi"], &Parser::eggDeath);
    assignLambda(commandAction["sgt"], &Parser::timeUnitReq);
    assignLambda(commandAction["sst"], &Parser::timeUnitMod);
    assignLambda(commandAction["seg"], &Parser::endGame);
    assignLambda(commandAction["smg"], &Parser::serverMsg);
    assignLambda(commandAction["suc"], &Parser::unknownCommand);
    assignLambda(commandAction["sbp"], &Parser::commandParam);
    assignLambda(commandAction["END"], &Parser::endProg);
    return commandAction;
}

DataManager Parser::parser(std::string command, std::string value, DataManager map)
{
    std::map<std::string, std::function<DataManager(const std::string&, DataManager map)>> commandAction = setupMap();

    if (commandAction.find(command) != commandAction.end()) {
        std::function<DataManager(const std::string&, DataManager map)> action = commandAction[command];
        map = action(value, map);
    } else {
        std::cout << "No Actions for the input" << command << std::endl;
    }
    return (map);
}

DataManager Parser::parsing_str(DataManager map, const char *str)
{
    std::string string(str);
    if (!string.empty() && string.back() == '\n') {
        string.erase(string.length() - 1);
    }
    std::string command = string.substr(0, string.find(" "));
    std::string values = string.substr(string.find_first_of(" \t")+1);

    map = parser(command, values, map);
    return (map);
}

DataManager Parser::parsing_msg(DataManager map, std::string messages)
{
    std::vector<std::string> splitMessages;

    splitMessages = splitMessage(messages, '\n');

    for (const std::string& message : splitMessages) {
        std::cout << message << std::endl;
        map = parsing_str(map, message.c_str());
    }

    return map;
}

DataManager Parser::setMapSize(std::string value, DataManager map)
{
    std::istringstream iss(value);
    int width, height;

    if (iss >> width >> height) {
        map.setSize(Vector2{float(width), float(height)});
        std::cout << "Set Map Size: Operation Successful." << std::endl;
    } else {
        std::cout << "Set Map Size: Operation Failed, invalid input!" << std::endl;
    }
    return (map);
}

DataManager Parser::tileContent(std::string value, DataManager map)
{
    std::istringstream iss(value);
    int x, y, food, line, dera, sib, mend, phir, thys;

    if (iss >> x >> y >> food >> line >> dera >> sib >> mend >> phir >> thys) {
        Tile tile(x, y, food, line, dera, sib, mend, phir, thys);
        if (map.isTile(x, y) == false)
            map.addTile(tile);
        else
            map.setTile(tile);
        std::cout << "Tile Content: Operation Successful." << std::endl;
    } else {
        std::cout << "Tile Content: Operation Failed, invalid input!" << std::endl;
    }
    return (map);
}

DataManager Parser::setTeamNames(std::string value, DataManager map)
{
    Team team(value);
    if (map.isTeam(value) == false)
        map.addTeam(team);
    else
        map.setTeam(team);
    std::cout << "Set Team Names: Operation Successful." << std::endl;
    return (map);
}

DataManager Parser::newPlayer(std::string value, DataManager map)
{
    std::stringstream ss(value);
    std::vector<int> numericalValues;
    std::string playersTeamName;


    int tempInt;

    for (int i = 0; i < 5; ++i) {
        ss >> tempInt;
        numericalValues.push_back(tempInt);
    }
    ss >> playersTeamName;
    Player player(numericalValues[0], numericalValues[1], numericalValues[2], numericalValues[3], numericalValues[4]);
    map.addPlayerTeam(player, playersTeamName);
    std::cout << "Add New Player (id = "<< numericalValues[0] << "): Operation Successful." << std::endl;
    return (map);
}

DataManager Parser::posPlayer(std::string value, DataManager map)
{
    std::istringstream iss(value);
    int id, x, y, orient;

    if (iss >> id >> x >> y >> orient)
        map.setPosPlayer(x, y, orient, id);
    else
        std::cout << "Set Position Player: Operation Failed, invalid Input";
    return map;
}

DataManager Parser::lvlPlayer(std::string value, DataManager map)
{
    std::istringstream iss(value);
    int id, level;
    bool success = false;

    if (iss >> id >> level) {
        for (auto &team : map.getAllTeams()) {
            for (auto &player : team.getAllPlayers())
                if (player.getId() == id) {
                    player.setLevel(level);
                    std::cout << "Set Level Player: Operation Sucessful.";
                    success = true;
                }
        }
        if (!success)
            std::cout << "Set Level Player: Operation Failed, invalid ID.";
    } else {
        std::cout << "Set Level Player: Operation Failed, invalid Input";
    }
    return (map);
}

DataManager Parser::invPlayer(std::string value, DataManager map)
{
    std::istringstream iss(value);
    int id, food, line, dera, sib, mend, phir, thys;
    bool success = false;

    if (iss >> id >> food >> line >> dera >> sib >> mend >> phir >> thys) {
        for (auto &team : map.getAllTeams()) {
            for (auto &player : team.getAllPlayers())
                if (player.getId() == id) {
                    player.setInventory(food, line, dera, sib, mend, phir, thys);
                    std::cout << "Set Inventory Player: Operation Sucessful.";
                    success = true;
                }
        }
        if (!success)
            std::cout << "Set Inventory Player: Operation Failed, invalid ID.";
    } else {
        std::cout << "Set Inventory Player: Operation Failed, invalid Input";
    }
    return (map);
}

DataManager Parser::expPlayer(std::string value, DataManager map)
{
    std::istringstream iss(value);
    int id;
    bool success = false;

    if (iss >> id) {
        for (auto &team : map.getAllTeams()) {
            for (auto &player : team.getAllPlayers())
                if (player.getId() == id) {
                    map.eject(id, player.getOrient(), player.getPos().x, player.getPos().y);
                    std::cout << "Eject Players: Operation Sucessful.";
                    success = true;
                }
        }
        if (!success)
            std::cout << "Eject Players: Operation Failed, invalid ID.";
    } else {
        std::cout << "Eject Players: Operation Failed, invalid ID";
    }
    return (map);
}

DataManager Parser::msgPlayer(std::string value, DataManager map)
{
    std::stringstream ss(value);
    int id;
    std::string message;
    bool success = false;

    ss >> id;
    ss >> message;
    for (auto &team : map.getAllTeams()) {
        for (auto &player : team.getAllPlayers())
            if (player.getId() == id) {
                player.setState(2, message);
                std::cout << "Message Player: Operation Sucessful.";
                success = true;
            } else {
                player.setState(3, "");
            }
    }
    if (!success)
        std::cout << "Message Player: Operation Failed, invalid ID.";
    return (map);
}

DataManager Parser::incPlayer(std::string value, DataManager map)
{
    std::stringstream ss(value);
    int x, y, level;
    std::vector<int> ids;
    bool success = false;

    ss >> x >> y >> level;
    int n;
    while(ss >> n)
        ids.push_back(n);
    for (long unsigned int i = 0; i < ids.size(); ++i) {
        for (auto &team : map.getAllTeams()) {
            for (auto &player : team.getAllPlayers()) {
                if (player.getId() == ids[i]) {
                    player.setState(2, "");
                    success = true;
                }
            }
        }
    }
    if (!success)
        std::cout << "Message Player: Operation Failed, invalid ID.";
    else
        std::cout << "Message Player: Operation Sucessful.";
    return (map);
}

DataManager Parser::incEndPlayer(std::string value, DataManager map)
{
    std::istringstream iss(value);
    int id;
    bool success = false;

    if (iss >> id) {
        for (auto &team : map.getAllTeams()) {
            for (auto &player : team.getAllPlayers())
                if (player.getId() == id) {
                    player.setState(0, "");
                    std::cout << "Incantation End Player: Operation Sucessful.";
                    success = true;
                }
        }
    if (!success)
        std::cout << "Incantation End Player: Operation Failed, invalid ID.";
    } else {
        std::cout << "Incantation End Player: Operation Failed, invalid ID.";
    }
    return (map);
}

DataManager Parser::eggPlayer(std::string value, DataManager map)
{
    std::istringstream iss(value);
    int id, egg;
    bool success = false;

    if (iss >> id >> egg) {
        for (auto &team : map.getAllTeams()) {
            for (auto &player : team.getAllPlayers())
                if (player.getId() == id) {
                    map.addEgg(player.getPos().x, player.getPos().y, egg);
                    std::cout << "Egg Player: Operation Sucessful.";
                    success = true;
                }
        }
    if (!success)
        std::cout << "Egg Player: Operation Failed, invalid ID.";
    } else {
        std::cout << "Egg Player: Operation Failed, invalid ID.";
    }
    return (map);
}

DataManager Parser::resDropPlayer(std::string value, DataManager map)
{
    std::istringstream iss(value);
    int id, resource;
    bool success = false;

    if (iss >> id >> resource) {
        for (auto &team : map.getAllTeams()) {
            for (auto &player : team.getAllPlayers())
                if (player.getId() == id) {
                    player.setResource(resource, false);
                    map.getTile(player.getPos().x, player.getPos().y).setResource(resource, true);
                    success = true;
                }
        }
    if (!success)
        std::cout << "Resource Dropped by Player: Operation Failed, invalid ID.";
    } else {
        std::cout << "Resource Dropped by Player: Operation Failed, invalid ID.";
    }
    return (map);
}

DataManager Parser::resGetPlayer(std::string value, DataManager map)
{
    std::istringstream iss(value);
    int id, resource;
    bool success = false;

    if (iss >> id >> resource) {
        for (auto &team : map.getAllTeams()) {
            for (auto &player : team.getAllPlayers())
                if (player.getId() == id) {
                    player.setResource(resource, true);
                    map.getTile(player.getPos().x, player.getPos().y).setResource(resource, false);
                    success = true;
                }
        }
    if (!success)
        std::cout << "Resource Get by Player: Operation Failed, invalid ID.";
    } else {
        std::cout << "Resource Get by Player: Operation Failed, invalid ID.";
    }
    return (map);
}

DataManager Parser::deathPlayer(std::string value, DataManager map)
{
    std::istringstream iss(value);
    int id;
    bool success = false;

    if (iss >> id) {
        for (auto &team : map.getAllTeams()) {
            for (auto &player : team.getAllPlayers())
                if (player.getId() == id) {
                    player.setState(-1, "");
                    std::cout << "Death of Player: Operation Sucessful.";
                    success = true;
                }
        }
    if (!success)
        std::cout << "Death of Player: Operation Failed, invalid ID.";
    } else {
        std::cout << "Death of Player: Operation Failed, invalid ID.";
    }
    return (map);
}

DataManager Parser::eggByPlayer(std::string value, DataManager map)
{
    std::istringstream iss(value);
    int eggId, id, x, y;
    bool success = false;

    if (iss >> eggId >> id >> x >> y) {
        for (auto &tile : map.getAllTiles())
            if (tile.getPos().x == x && tile.getPos().y == y)
                tile.setEgg(eggId);
    }
    if (!success)
         std::cout << "Set Inventory Player: Operation Failed, invalid ID.";
    else
        std::cout << "Set Inventory Player: Operation Failed, invalid Input";
    return (map);
    return (map);
}

DataManager Parser::eggConnection(std::string value, DataManager map)
{
    std::istringstream iss(value);
    int eggId;
    bool success = false;

    if (iss >> eggId) {
        for (auto &tile : map.getAllTiles())
            if (tile.getEgg() == eggId)
                tile.setEgg(-1);
    if (!success)
        std::cout << "Death of Player: Operation Failed, invalid ID.";
    } else {
        std::cout << "Death of Player: Operation Failed, invalid ID.";
    }
    return (map); 
}

DataManager Parser::eggDeath(std::string value, DataManager map)
{
    std::cout << "eggDeath " << value << std::endl;
    return (map);
}

DataManager Parser::timeUnitReq(std::string value, DataManager map)
{
    map.setUnitReq(atoi(value.c_str()));
    std::cout << "timeUnitReq " << value << std::endl;
    return (map);
}

DataManager Parser::timeUnitMod(std::string value, DataManager map)
{
    map.setUnitReq(atoi(value.c_str()));
    std::cout << "timeUnitMod " << value << std::endl;
    return (map);
}

DataManager Parser::endGame(std::string value, DataManager map)
{
    std::cout << "endGame " << value << std::endl;
    return (map);
}

DataManager Parser::serverMsg(std::string value, DataManager map)
{
    std::cout << "serverMsg" << value << std::endl;
    return (map);
}

DataManager Parser::unknownCommand(std::string value, DataManager map)
{
    std::cout << "UnknownCommand " << value << std::endl;
    return (map);
}

DataManager Parser::commandParam(std::string value, DataManager map)
{
    std::cout << "commandParam " << value << std::endl;
    return (map);
}

DataManager Parser::endProg(std::string value, DataManager map)
{
    std::cout << value << std::endl;
    return (map);
}