/*
** EPITECH PROJECT, 2023
** gui
** File description:
** Button
*/
#include "Button.hpp"

RecButton::RecButton(): disabled(false)
{
}

RecButton::RecButton(const char *boxPath, const char *hoverBoxPath, Rectangle dest)
{
    this->_dest = dest;
    this->_boxTexture.init(boxPath);
    this->_hoverBoxTexture.init(hoverBoxPath);


    Rectangle source{.x = 0,
                    .y = 0,
                    .width = static_cast<float>(this->_boxTexture.getWidth()),
                    .height = static_cast<float>(this->_boxTexture.getHeight())
                    };

    this->_boxTexture.setParam(source, dest, 0.0f, WHITE);
    this->_hoverBoxTexture.setParam(source, dest, 0.0f, WHITE);
    this->disabled = false;
}

void RecButton::draw(void)
{
    if (this->disabled)
        return;
    if (this->hover()) {
        this->_hoverBoxTexture.draw();
    } else {
        this->_boxTexture.draw();
    }
}

void RecButton::move(Vector2 pos)
{
    this->_dest.x = pos.x;
    this->_dest.y = pos.y;
    this->_boxTexture.move(pos);
    this->_hoverBoxTexture.move(pos);
}

bool RecButton::pressed(void)
{
    Vector2 mousePos = GetMousePosition();
    bool collision = CheckCollisionPointRec(mousePos, this->_dest);
    bool pressed = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    if (collision && pressed && this->disabled == false) {
        return true;
    } else
        return false;
}

bool RecButton::hover(void)
{
    Vector2 mousePos = GetMousePosition();

    return CheckCollisionPointRec(mousePos, this->_dest) && !this->disabled;
}

float RecButton::getWidth(void) const
{
    return this->_dest.width;
}

float RecButton::getHeight(void) const
{
    return this->_dest.height;
}

Vector2 RecButton::getPos(void) const
{
    return Vector2{this->_dest.x, this->_dest.y};
}
