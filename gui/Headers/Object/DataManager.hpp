/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** DataManager
*/

#ifndef DATAMANAGER_HPP_
    #define DATAMANAGER_HPP_

#include "Map.hpp"
#include "Team.hpp"
#include "ResourceManager.hpp"
#include "Tile.hpp"

class DataManager {
    public:
        DataManager();
        ~DataManager();
        
        void addTeam(Team team);
        void addTile(Tile tile);
        void addPlayerTeam(Player player, std::string teamname);
        void addEgg(int x, int y, int egg);

        void setTeam(Team team);
        void setPosPlayer(int x, int y, int orient, int id);
        void setTile(Tile tile);
        void setSize(Vector2 size);
        void setUnitReq(int value);

        Player getPlayer(int id);
        Team getTeam(std::string name);
        Tile getTile(int x, int y);
        Vector2 getSize(void);
        int getUnitReq(void);

        std::vector<Team> getAllTeams(void);
        std::vector<Tile> getAllTiles();

        
        bool isTile(int x, int y);
        bool isTeam(std::string name);

        void displayTeamPlayer(void);
        void displayAllTiles(void);
        void displayMap(void);

        void LoadAllModel();
        void UnloadAllModel();

        void Clicked(void);

        void eject(int id, int orient, int x, int y);
        void Debug(void);

    private:
        std::vector<Team> _teams;
        std::vector<Tile> _tiles;
        ResourceManager _resourceManager;
        Map _map;

        int _timeUnit;
};

#endif /* !DataManager_HPP_ */
