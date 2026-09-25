#pragma once
#include <iostream>
#include <raylib.h>
#include <raymath.h>

class Paddle{
private:
    Rectangle sprite{0.0f, 0.0f, 1.0f, 1.0f};

    Vector2 position{Vector2{0.0f, 0.0f}};
    float speedMultX{1.0f};
    float speedMultY{1.0f};

    KeyboardKey up{KEY_W};
    KeyboardKey down{KEY_S};
    KeyboardKey left{KEY_A};
    KeyboardKey right{KEY_D};

public:
    Paddle(Rectangle r);

    Rectangle paddle{Rectangle{position.x, position.y, 1.0f, 1.0f}};

    Rectangle getSprite() const;
    void drawPaddle() const;

    void move(Vector2 vec);

    void setPosition(Vector2 pos);
    void setPositionX(float posX);
    void setPositionY(float posY);
    Vector2 getPosition() const;

    void setHeight(float h);
    float getHeight() const;

    void setWidth(float w);
    float getWidth() const;

    void configureControls(
        KeyboardKey u,
        KeyboardKey d,
        KeyboardKey l,
        KeyboardKey r
    );

    KeyboardKey getUpKey() const;
    KeyboardKey getDownKey() const;
    KeyboardKey getLeftKey() const;
    KeyboardKey getRightKey() const;

    void setSpeedMult(Vector2 multipliers);
};