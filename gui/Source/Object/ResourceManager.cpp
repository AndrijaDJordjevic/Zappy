/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** ResourceManager
*/

#include "ResourceManager.hpp"

ResourceManager::ResourceManager() {}

ResourceManager::~ResourceManager() {}

void ResourceManager::LoadResources()
{
    _foodModel = LoadModel("gui/assets/models/fruit.obj");
    _foodModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("gui/assets/textures/food/fruits.png");

    _linemateModel = LoadModel("gui/assets/models/mineral.obj");
    _linemateModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("gui/assets/textures/mineral/Green.png");

    _deraumereModel = LoadModel("gui/assets/models/mineral.obj");
    _deraumereModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("gui/assets/textures/mineral/Orange.png");

    _siburModel = LoadModel("gui/assets/models/mineral.obj");
    _siburModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("gui/assets/textures/mineral/Yellow.png");

    _mendianeModel = LoadModel("gui/assets/models/mineral.obj");
    _mendianeModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("gui/assets/textures/mineral/Purple.png");

    _phirasModel = LoadModel("gui/assets/models/mineral.obj");
    _phirasModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("gui/assets/textures/mineral/Red.png");

    _thystameModel = LoadModel("gui/assets/models/mineral.obj");
    _thystameModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("gui/assets/textures/mineral/Blue.png");

    _eggModel = LoadModel("gui/assets/modes/egg.obj");
    _eggModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("gui/assets/texture/egg.png");
}

void ResourceManager::UnloadResources()
{

}

Model ResourceManager::GetFoodModel()
{
    return _foodModel;
}

Model ResourceManager::GetLinemateModel()
{
    return _linemateModel;
}

Model ResourceManager::GetDeraumereModel()
{
    return _deraumereModel;
}

Model ResourceManager::GetSiburModel()
{
    return _siburModel;
}

Model ResourceManager::GetMendianeModel()
{
    return _mendianeModel;
}

Model ResourceManager::GetPhirasModel()
{
    return _phirasModel;
}

Model ResourceManager::GetThystameModel()
{
    return _thystameModel;
}

Model ResourceManager::GetEggModel()
{
    return _eggModel;
}
