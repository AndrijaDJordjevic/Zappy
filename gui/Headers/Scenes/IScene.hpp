/*
** EPITECH PROJECT, 2023
** IScene.hpp
** File description:
** IScene
*/
#ifndef _ISCENE_HPP
    #define _ISCENE_HPP
    #include <string>

class IScene {
    public:
        virtual ~IScene() = default;

        virtual void display(void) = 0;
        virtual void handleEvent(void) = 0;
        virtual bool changeSceneRequested(void) = 0;
        virtual bool closeWindowRequested(void) = 0;
        virtual void initScene(void) = 0;

    private:
};

#endif
