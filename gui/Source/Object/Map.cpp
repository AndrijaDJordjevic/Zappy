/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** Map
*/

#include "Map.hpp"
#include <iostream>

extern "C" {
    #include "rlgl.h"
}

Map::Map()
{
    _textureIsLoad = false;
}

Map::~Map() { }

void Map::setSize(Vector2 size)
{
    _mapSize = size;
    setMapTexture();
}


void Map::setMapTexture()
{
    if (_textureIsLoad == false ) {
        _mapTexture =  LoadTexture("gui/assets/textures/map/tileable_grass_00.png");
        _textureIsLoad = true;
        if (_mapTexture.id == 0) {
            std::cerr << "Error: loading path for map texture" << std::endl;
            exit(84); 
        }
    }
}

void Map::UnloadMapTexture()
{
    if (_textureIsLoad == true) {
        UnloadTexture(_mapTexture);
        _textureIsLoad = false;
    }
}

Vector2 Map::getSize()
{
    return _mapSize;
}

void Map::DrawMapTexture(Vector3 position)
{
    float x = position.x;
    float y = position.y;
    float z = position.z;

    Color color = WHITE;
    float width = 2.0f;
    float height = 1.0f;
    float length = 2.0f;

    rlSetTexture(_mapTexture.id);
        rlBegin(RL_QUADS);
            rlColor4ub(color.r, color.g, color.b, color.a);
            // Front Face
            rlNormal3f(0.0f, 0.0f, 1.0f);       // Normal Pointing Towards Viewer
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width/2, y - height/2, z + length/2);  // Bottom Left Of The Texture and Quad
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width/2, y - height/2, z + length/2);  // Bottom Right Of The Texture and Quad
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width/2, y + height/2, z + length/2);  // Top Right Of The Texture and Quad
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width/2, y + height/2, z + length/2);  // Top Left Of The Texture and Quad
            // Back Face
            rlNormal3f(0.0f, 0.0f, - 1.0f);     // Normal Pointing Away From Viewer
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width/2, y - height/2, z - length/2);  // Bottom Right Of The Texture and Quad
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width/2, y + height/2, z - length/2);  // Top Right Of The Texture and Quad
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width/2, y + height/2, z - length/2);  // Top Left Of The Texture and Quad
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width/2, y - height/2, z - length/2);  // Bottom Left Of The Texture and Quad
            // Top Face
            rlNormal3f(0.0f, 1.0f, 0.0f);       // Normal Pointing Up
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width/2, y + height/2, z - length/2);  // Top Left Of The Texture and Quad
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width/2, y + height/2, z + length/2);  // Bottom Left Of The Texture and Quad
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width/2, y + height/2, z + length/2);  // Bottom Right Of The Texture and Quad
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width/2, y + height/2, z - length/2);  // Top Right Of The Texture and Quad
            // Bottom Face
            rlNormal3f(0.0f, - 1.0f, 0.0f);     // Normal Pointing Down
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width/2, y - height/2, z - length/2);  // Top Right Of The Texture and Quad
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width/2, y - height/2, z - length/2);  // Top Left Of The Texture and Quad
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width/2, y - height/2, z + length/2);  // Bottom Left Of The Texture and Quad
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width/2, y - height/2, z + length/2);  // Bottom Right Of The Texture and Quad
            // Right face
            rlNormal3f(1.0f, 0.0f, 0.0f);       // Normal Pointing Right
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x + width/2, y - height/2, z - length/2);  // Bottom Right Of The Texture and Quad
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x + width/2, y + height/2, z - length/2);  // Top Right Of The Texture and Quad
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x + width/2, y + height/2, z + length/2);  // Top Left Of The Texture and Quad
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x + width/2, y - height/2, z + length/2);  // Bottom Left Of The Texture and Quad
            // Left Face
            rlNormal3f( - 1.0f, 0.0f, 0.0f);    // Normal Pointing Left
            rlTexCoord2f(0.0f, 0.0f); rlVertex3f(x - width/2, y - height/2, z - length/2);  // Bottom Left Of The Texture and Quad
            rlTexCoord2f(1.0f, 0.0f); rlVertex3f(x - width/2, y - height/2, z + length/2);  // Bottom Right Of The Texture and Quad
            rlTexCoord2f(1.0f, 1.0f); rlVertex3f(x - width/2, y + height/2, z + length/2);  // Top Right Of The Texture and Quad
            rlTexCoord2f(0.0f, 1.0f); rlVertex3f(x - width/2, y + height/2, z - length/2);  // Top Left Of The Texture and Quad
        rlEnd();
    rlSetTexture(0);
}

void Map::drawMap()
{
    for (float i = 1; i < _mapSize.x; i += 1.0) {
        for (float j = 1; j < _mapSize.y; j += 1.0) {
            DrawMapTexture((Vector3){ i, 0.0f, j });
            DrawCubeWires((Vector3){ i, 0.0f, j }, 2.01, 1.01f, 2.01f, BLACK);
        }
    }
}