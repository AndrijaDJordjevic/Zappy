/*
** EPITECH PROJECT, 2023
** model.hpp
** File description:
** model
*/

#ifndef MODEL_HPP_
#define MODEL_HPP_

#include <raylib.h>
#include <string>

enum TYPE {
    PLAYER = -1,
    FOOD = 0,
    LINEMATE = 1, // Green
    DERAUMERE = 2, // Orange
    SIBUR = 3,  // Yellow
    MENDIANE = 4, // Purple
    PHIRAS = 5, // Red
    THYSTAME = 6, // Blue
    EGG = 7
};

class Model3D {
    public:
        Model3D(std::string modelStr, std::string textureStr, int r, int g, int b, float x, float z, int orient, float scale, int type, int id);
        ~Model3D();
        void print(void);

        int getId(void);
        Vector3 getPos(void);
        TYPE getType(void);

    protected:
    private:
        Model *_model;
        Texture2D _texture;
        Vector3 _pos;
        Color _color;
        int _orient;
        float _scale;
        TYPE _type;
        int _id;
};

#endif /* !MODEL_HPP_ */
