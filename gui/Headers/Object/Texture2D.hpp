/*
** EPITECH PROJECT, 2023
** Texture2D.hpp
** File description:
** Texture2D
*/
#ifndef _TEXTURE_2D_HPP
    #define _TEXTURE_2D_HPP
    extern "C" {
        #include <raylib.h>
    }

namespace obj {

    class Texture
    {
        public:
            Texture() = default;
            ~Texture();

            void init(const char *path);
            void setParam(Rectangle source, Rectangle dest, float rota, Color tint);
            void draw(void) const;
            void move(Vector2 pos);
            int getWidth(void) const;
            int getHeight(void) const;
            void resize(int width, int height);

        private:
            Texture2D _texture;
            Vector2 _pos;
            Rectangle _source;
            Rectangle _dest;
            float _rotation;
            Color _tint;
    };

}

#endif
