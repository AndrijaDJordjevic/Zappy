/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** Map
*/

#ifndef MAP_HPP_
    #define MAP_HPP_

    extern "C" {
        #include "raylib.h"
    }

    #include <vector>
    #include <string>


class Map {
    public:
        Map();
        ~Map();

        void setSize(Vector2 size);
        
        Vector2 getSize(void);

        void setMapTexture(void);
        void UnloadMapTexture(void);

        void drawMap();
 
    private:
        Vector2 _mapSize;
        Texture _mapTexture;

        bool _textureIsLoad;

        void DrawMapTexture(Vector3 position);
};

#endif /* !MAP_HPP_ */
