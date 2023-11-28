/*
** EPITECH PROJECT, 2023
** Tile.hpp
** File description:
** TIle
*/

#ifndef TILE_HPP_
#define TILE_HPP_

#include "Player.hpp"
#include <vector>

class Tile {
    public:
        Tile();
        Tile(int x, int y, int food, int line, int dera, int sib, int mend, int phir, int thys);
        ~Tile();

        //Set Values
        void setTile(Tile *tile);

        void setPos(int x, int y);
        void setResource(int resID, bool add);
        void setFood(int food);
        void setLinemate(int linemate);
        void setDeraumere(int deraumere);
        void setSibur(int sibur);
        void setMendiane(int mendiane);
        void setPhiras(int mendiane);
        void setThystame(int thys);
        void setEgg(int egg);

        void setFoodModel(Model);
        void setLinemateModel(Model);
        void setDeraumereModel(Model);
        void setSiburModel(Model);
        void setMendianeModel(Model);
        void setPhirasModel(Model);
        void setThystameModel(Model);
        void setEggModel(Model);

        // Get Values
        Vector3 getPos(void);
        int getFood(void);
        int getLinemate(void);
        int getDeraumere(void);
        int getSibur(void);
        int getMendiane(void);
        int getPhiras(void);
        int getThystame(void);
        int getEgg(void);

        void printModelTile(void);
        void DrawUi(void);
        bool isClicked(void);
        void debug(void);

    protected:
        Vector3 pos_;
        int food_;
        int linemate_;      // Green
        int deraumere_;     // Orange
        int sibur_;         // Yellow
        int mendiane_;      // Purple
        int phiras_;        // Red
        int thystame_;      // Blue
        int egg_;

        bool _clicked;
    private:
        Model _foodModel;
        Model _linemateModel;      // Green
        Model _deraumereModel;     // Orange
        Model _siburModel;         // Yellow
        Model _mendianeModel;      // Purple
        Model _phirasModel;        // Red
        Model _thystameModel;      // Blue
        Model _eggModel;
};

#endif /* !TILE_HPP_ */
