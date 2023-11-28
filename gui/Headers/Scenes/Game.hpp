/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** Game
*/

#ifndef GAME_HPP_
    #define GAME_HPP_

    #include "IScene.hpp"
    #include "DataManager.hpp"
    #include "Team.hpp"

class Game: public IScene
{
    public:
        Game();
        ~Game();

        void display(void);
        void handleEvent();
        bool changeSceneRequested();
        DataManager& getData(void);
        void initScene(void);
        bool closeWindowRequested(void);

    private:
        bool _changeScene;

        DataManager _data;
        Camera _camera;
};

#endif /* !GAME_HPP_ */
