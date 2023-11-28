/*
** EPITECH PROJECT, 2023
** Broadcaster.hpp
** File description:
** Broadcaster
*/
#ifndef _BROADCASTER_HPP
    #define _BROADCASTER_HPP
    extern "C" {
        #include <raylib.h>
    }
    #include <memory>
    #include <string>
    #include <unordered_map>
    #include "Game.hpp"
    #include "Menu.hpp"
    #define DEFAULT_CAMERA_WIDTH 800
    #define DEFAULT_CAMERA_HEIGHT 450
    #define PATH_TO_MUSIC "./gui/assets/music/main_theme.ogg"

enum SCENE {
    GAME,
    MENU,
};

class Broadcaster
{
    public:
        Broadcaster() = delete;
        Broadcaster(Game& game, Menu& menu);
        ~Broadcaster();

        void navigate(void);
        bool broadcast(void);
        Music& getMusic(void);
        bool updateNeeded(void) const;
        DataManager& getData(void);

    private:
        Game& _game;
        Menu& _menu;
        SCENE _activeScene;
        int _windowWidth;
        int _windowHeight;
        Music _music;
};

#endif
