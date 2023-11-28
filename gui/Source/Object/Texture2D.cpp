/*
** EPITECH PROJECT, 2023
** Texture2D.cpp
** File description:
** Texture2D
*/
#include <iostream>
#include "Texture2D.hpp"

obj::Texture::~Texture()
{
    // UnloadTexture(this->_texture);
}

void obj::Texture::init(const char *path)
{
    this->_texture = LoadTexture(path);

    if (IsTextureReady(this->_texture)) {
        std::cout << "Texture loaded from ----> " << path << std::endl;
    } else {
        std::cout << "Texture NOT loaded from ----> " << path << std::endl;
    }
}

void obj::Texture::setParam(Rectangle source, Rectangle dest, float rota, Color tint)
{
    this->_source = source;
    this->_dest = dest;
    this->_rotation = rota;
    this->_tint = tint;
}

void obj::Texture::draw(void) const
{
    DrawTexturePro(this->_texture, this->_source, this->_dest, Vector2{0, 0}, this->_rotation, this->_tint);
}

void obj::Texture::move(Vector2 pos)
{
    this->_dest.x = pos.x;
    this->_dest.y = pos.y;
}

int obj::Texture::getWidth(void) const
{
    return this->_texture.width;
}

int obj::Texture::getHeight(void) const
{
    return this->_texture.height;
}

void obj::Texture::resize(int width, int height)
{
    this->_dest.width = width;
    this->_dest.height = height;
}
