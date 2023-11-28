/*
** EPITECH PROJECT, 2023
** player.hpp
** File description:
** player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_

    #include "Model.hpp"
    #include "Inventory.hpp"

    #include <string>
    #include <chrono>
    #include <vector>

enum PLAYERSTATE {
    IDLE = 0,
    INCANTING = 1,
    BROADCAST = 2,
    RECEIVING = 3,
    DEAD = -1
};

enum ORIENTATION {
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4
};

class Player {
    public:
        Player();
        Player(int id, int x, int z, int level, int orient);
        ~Player();

        void loadPSounds(void);
        void unloadPSounds(void);
        void destroyModel(void);

        void setId(int id);
        void setPos(int x, int y);
        void setLevel(int level);
        void setResource(int resID, bool add);
        void setOrient(int orient);
        void setState(int state, std::string);

        int getId(void) const;
        Vector3 getPos(void) const;
        int getLevel(void) const;
        int getOrient(void) const;
        int getState(void) const;
        std::string getMessage(void) const;
        Model getModel3D(void) const;

        void DrawPlayer(int r, int g, int b);
        void DrawUi(std::string teamname);

        bool checkCollision(void);
        bool isClicked(void);

        void resetTime(void);

        void setInventory(int food, int line, int dera, int sib, int mend, int phir, int thys);
        Inventory getInventory(void) const;
        void debug(void);

    protected:
    private:
        int _id;
        int _level;

        Vector3 _pos;
        Vector3 _oldPos;
        ORIENTATION _orient;
        PLAYERSTATE _state;
        std::string _message;

        Inventory _invent;

        bool _clicked;

        bool _ModelSet = false;
        Model _model;
        Texture2D _texture;

        std::chrono::steady_clock::time_point _start_time;
        std::chrono::steady_clock::time_point _current_time;
        int _elapsed_seconds;


};

#endif /* !PLAYER_HPP_ */
