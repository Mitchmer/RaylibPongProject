#pragma once
#include <iostream>
#include <raylib.h>
#include <raymath.h>

class Paddle{
private:
    Vector2 position{Vector2{0.0f, 0.0f}};
    Rectangle sprite{0.0f, 0.0f, 1.0f, 1.0f};

public:
    Paddle(Rectangle r);

    Rectangle paddle{Rectangle{position.x, position.y, 1.0f, 1.0f}};

    void drawPaddle() const;
    void move(Vector2 vec);
    Rectangle getSprite() const;
    void setPosition(Vector2 pos);
    void setPositionX(float posX);
    void setPositionY(float posY);

    void setHeight(float h);
    float getHeight() const;

    void setWidth(float w);
    float getWidth() const;
};