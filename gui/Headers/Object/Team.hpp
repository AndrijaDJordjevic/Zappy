/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** team
*/

#ifndef TEAM_HPP_
    #define TEAM_HPP_

    #include <string>
    #include <vector>
    #include "Player.hpp"

class Team {
    public:
        Team();
        Team(std::string name);
        ~Team();

        void addPlayer(Player player);
        void setPlayerPos(int x, int y, int orient, int id);
        void removePlayer(Player player);

        std::string getTeamname(void) const;
        std::vector<Player> getAllPlayers(void) const;
        Player getPlayer(int id);
        bool isPlayer(int id);

        void setTeam(Team *team);

        void displayTeamPlayer(void);
        void debug(void);
        void end(void);

        int r;
        int g;
        int b;
    protected:
        std::vector<Player> _players;
        std::string _teamname;
    private:
        void setTeamname(std::string name) {_teamname = name;}
        void setPlayers(std::vector<Player> players) {while (_players.size() > 0) {_players.pop_back();} for (auto &it : players) {_players.push_back(it);}}
};

#endif /* !TEAM_HPP_ */
