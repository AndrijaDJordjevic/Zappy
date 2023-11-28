/*
** EPITECH PROJECT, 2023
** objects.hpp
** File description:
** objects
*/
#ifndef _OBJECTS_HPP
    #define _OBJECTS_HPP
    extern "C" {
        #include <raylib.h>
    }

struct text_s {
    const char *text;
    Color color;
    Font font;
};


struct rectangle_s {
    Vector2 pos;
    int width;
    int height;
    float lineThick;
    Color color;
    Color borderColor;
};


using text_t = text_s;
using rectangle_t = rectangle_s;

#endif
