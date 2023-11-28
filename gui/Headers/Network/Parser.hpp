/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** Parser
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_

#include "DataManager.hpp"
#include "Player.hpp"
#include "Team.hpp"
#include "Tile.hpp"

#include <functional>
#include <map>
#include <string>

class Parser {
    public:
        Parser();
        ~Parser();

        std::vector<std::string> splitMessage(const std::string& message, char delimiter);
        std::string splitAndTake(const std::string& message, char delimiter, int nbr_pos);

        std::map<std::string, std::function<DataManager(const std::string&, DataManager map)>> setupMap(void);
        DataManager parser(std::string command, std::string value, DataManager map);
        DataManager parsing_str(DataManager map, const char *str);
        DataManager parsing_msg(DataManager map, std::string message);

        DataManager setMapSize(std::string value, DataManager map);
        DataManager tileContent(std::string value, DataManager map);
        DataManager setTeamNames(std::string value, DataManager map);
        DataManager newPlayer(std::string value, DataManager map);
        DataManager posPlayer(std::string value, DataManager map);
        DataManager lvlPlayer(std::string value, DataManager map);
        DataManager invPlayer(std::string value, DataManager map);
        DataManager expPlayer(std::string value, DataManager map);
        DataManager msgPlayer(std::string value, DataManager map);
        DataManager incPlayer(std::string value, DataManager map);
        DataManager incEndPlayer(std::string value, DataManager map);
        DataManager eggPlayer(std::string value, DataManager map);
        DataManager resDropPlayer(std::string value, DataManager map);
        DataManager resGetPlayer(std::string value, DataManager map);
        DataManager deathPlayer(std::string value, DataManager map);
        DataManager eggByPlayer(std::string value, DataManager map);
        DataManager eggConnection(std::string value, DataManager map);

        //not finish
        DataManager eggDeath(std::string value, DataManager map);
        DataManager timeUnitReq(std::string value, DataManager map);
        DataManager timeUnitMod(std::string value, DataManager map);
        DataManager endGame(std::string value, DataManager map);
        DataManager serverMsg(std::string value, DataManager map);
        DataManager unknownCommand(std::string value, DataManager map);
        DataManager commandParam(std::string value, DataManager map);
        DataManager endProg(std::string value, DataManager map);
};

#endif /* !PARSER_HPP_ */