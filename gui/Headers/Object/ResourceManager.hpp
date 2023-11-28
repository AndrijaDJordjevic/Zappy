/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** ResourceManager
*/

#pragma once

#include <raylib.h>
#include <map>

class ResourceManager {
    public:
        ResourceManager();
        ~ResourceManager();

        void LoadResources();
        void UnloadResources();

        Model GetFoodModel();
        Model GetLinemateModel();
        Model GetDeraumereModel();
        Model GetSiburModel();
        Model GetMendianeModel();
        Model GetPhirasModel();
        Model GetThystameModel();
        Model GetEggModel();

    private:
        Model _foodModel;
        Model _linemateModel;
        Model _deraumereModel;
        Model _siburModel;
        Model _mendianeModel;
        Model _phirasModel;
        Model _thystameModel;
        Model _eggModel;
};
