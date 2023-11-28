/*
** EPITECH PROJECT, 2023
** Menu.hpp
** File description:
** Menu
*/
#ifndef _MENU_HPP
    #define _MENU_HPP
    extern "C" {
        #include <raylib.h>
    }
    #include "IScene.hpp"
    #include "Button.hpp"
    #include "Texture2D.hpp"


class Menu: public IScene
{
    public:
        Menu();
        ~Menu() = default;

        void display(void);
        void handleEvent();
        bool changeSceneRequested();
        void initTextures(void);
        void initButtons(void);
        void initScene(void);
        bool closeWindowRequested(void);
        void updatePositions(int width, int height);

    private:
        bool _changeScene;
        bool _closeWindow;
        bool _showOptions;
        obj::Texture _background;
        RecButton _playButton;
        RecButton _optionButton;
        RecButton _exitButton;
        RecButton _backButton;
        RecButton _res800x600Button;
        RecButton _res1920x1080Button;
};

#endif
