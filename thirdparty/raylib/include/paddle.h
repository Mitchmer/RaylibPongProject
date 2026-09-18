#pragma once
#include <iostream>
#include <raylib.h>
#include <raymath.h>

class paddle{
private:
    Vector2 position{Vector2{0.0f, 0.0f}};

public:
    Rectangle paddle{Rectangle{position.x, position.y, 1.0f, 1.0f}};

    void drawPaddle();
}