/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Button
*/
#ifndef _BUTTON_HPP
    #define _BUTTON_HPP

    extern "C" {
        #include <raylib.h>
    }

    #include <string>
    #include "Texture2D.hpp"
    #include "objects.hpp"
    #define DEFAULT_FONTSIZE 10

class RecButton
{
    public:
        RecButton();
        RecButton(const char *boxPath, const char *hoverBoxPath, Rectangle dest);

        void draw(void);
        void move(Vector2 pos);
        bool pressed(void);
        float getWidth() const;
        float getHeight() const;

        Vector2 getPos() const;

        bool disabled;

    private:
        Rectangle _dest;
        obj::Texture _boxTexture;
        obj::Texture _hoverBoxTexture;


        bool hover(void);
};

#endif
