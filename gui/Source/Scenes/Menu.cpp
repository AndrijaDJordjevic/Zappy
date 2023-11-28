/*
** EPITECH PROJECT, 2023
** Menu.cpp
** File description:
** Menu
*/
#include <raylib.h>
#include "Menu.hpp"

Menu::Menu()
{
    this->_changeScene = false;
    this->_closeWindow = false;
    this->_showOptions = false;
}

void Menu::display(void)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    this->_background.draw();
    if (this->_showOptions) {
        this->_res800x600Button.draw();
        this->_res1920x1080Button.draw();
        this->_backButton.draw();
    } else {
        this->_playButton.draw();
        this->_optionButton.draw();
        this->_exitButton.draw();
    }
    EndDrawing();
}

void Menu::handleEvent(void)
{
    if (this->_showOptions) {
        if (this->_backButton.pressed())
            this->_showOptions = false;
        if (this->_res800x600Button.pressed())
            this->updatePositions(800, 600);
        if (this->_res1920x1080Button.pressed())
            this->updatePositions(1920, 1080);
        return;
    }
    if (this->_playButton.pressed())
        this->_changeScene = true;
    if (this->_exitButton.pressed())
        this->_closeWindow = true;
    if (this->_optionButton.pressed())
        this->_showOptions = true;
}

bool Menu::changeSceneRequested(void)
{
    if (this->_changeScene) {
        this->_changeScene = false;
        return true;
    }
    return false;
}

bool Menu::closeWindowRequested(void)
{
    return this->_closeWindow;
}


void Menu::initScene(void)
{
    this->initButtons();
    this->initTextures();
}

void Menu::initButtons(void)
{
    float screenCenterWidth = static_cast<float>(GetScreenWidth()) / 2;
    float screenCenterHeight = static_cast<float>(GetScreenHeight()) / 2;
    float spacing = 20.0f;
    Rectangle dest{.x = 100, .y = 100, .width = 200, .height = 100};

    this->_playButton = RecButton("./gui/assets/images/buttons/play.png", "./gui/assets/images/buttons/col_play.png", dest);
    this->_optionButton = RecButton("./gui/assets/images/buttons/options.png", "./gui/assets/images/buttons/col_options.png", dest);
    this->_exitButton = RecButton("./gui/assets/images/buttons/quit.png", "./gui/assets/images/buttons/col_quit.png", dest);
    this->_backButton = RecButton("./gui/assets/images/buttons/back.png", "./gui/assets/images/buttons/col_back.png", dest);
    this->_res800x600Button = RecButton("./gui/assets/images/buttons/res_800_600.png", "./gui/assets/images/buttons/col_res_800_600.png", dest);
    this->_res1920x1080Button = RecButton("./gui/assets/images/buttons/res_1920_1080.png", "./gui/assets/images/buttons/col_res_1920_1080.png", dest);

    float yPos = screenCenterHeight - this->_playButton.getHeight() - this->_playButton.getHeight() / 2;
    this->_playButton.move(Vector2{screenCenterWidth - this->_playButton.getWidth() / 2, yPos});
    yPos += spacing + this->_playButton.getHeight();
    this->_optionButton.move(Vector2{screenCenterWidth - this->_optionButton.getWidth() / 2, yPos});
    yPos += spacing + this->_optionButton.getHeight();
    this->_exitButton.move(Vector2{screenCenterWidth - this->_exitButton.getWidth() / 2, yPos});

    this->_res800x600Button.move(Vector2{screenCenterWidth - this->_res800x600Button.getWidth() - spacing, 100});
    this->_res1920x1080Button.move(Vector2{screenCenterWidth + spacing, 100});
    this->_backButton.move(Vector2{screenCenterWidth - this->_backButton.getWidth() / 2, screenCenterHeight + spacing});
}

void Menu::updatePositions(int width, int height)
{
    float screenCenterWidth = static_cast<float>(width) / 2;
    float screenCenterHeight = static_cast<float>(height) / 2;
    float spacing = 20.0f;


    SetWindowSize(width, height);
    SetWindowPosition(0, 0);
    this->_background.resize(width, height);

    float yPos = screenCenterHeight - this->_playButton.getHeight() - this->_playButton.getHeight() / 2;
    this->_playButton.move(Vector2{screenCenterWidth - this->_playButton.getWidth() / 2, yPos});
    yPos += spacing + this->_playButton.getHeight();
    this->_optionButton.move(Vector2{screenCenterWidth - this->_optionButton.getWidth() / 2, yPos});
    yPos += spacing + this->_optionButton.getHeight();
    this->_exitButton.move(Vector2{screenCenterWidth - this->_exitButton.getWidth() / 2, yPos});

    this->_res800x600Button.move(Vector2{screenCenterWidth - this->_res800x600Button.getWidth() - spacing, 100});
    this->_res1920x1080Button.move(Vector2{screenCenterWidth + spacing, 100});
    this->_backButton.move(Vector2{screenCenterWidth - this->_backButton.getWidth() / 2, screenCenterHeight + spacing});
}

void Menu::initTextures(void)
{
    this->_background.init("./gui/assets/images/menu_bg.png");

    this->_background.setParam(
    Rectangle{ 0, 0, static_cast<float>(this->_background.getWidth()), static_cast<float>(this->_background.getHeight()) },
    Rectangle{ 0, 0, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) },
    0.0f, WHITE);
}
