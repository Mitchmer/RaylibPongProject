#pragma once
#include <iostream>
#include <raylib.h>
#include <raymath.h>


class PowerUp {
public:

    enum PowerUpType {
        SPEEDUP,
        SLOWDOWN,
        REVERSE,
        DUPLICATE
    };


private:
    Vector2 position{Vector2{0.0f, 0.0f}};
    enum PowerUpType type{SPEEDUP};
    
public:

    Rectangle sprite{Rectangle{position.x, position.y, 1.0f, 1.0f}};
    
    PowerUp(
        Vector2 pos = Vector2{0.0f, 0.0f}, 
        PowerUpType type = SPEEDUP, 
        Rectangle sprite = Rectangle{0.0f, 0.0f, 1.0f, 1.0f}
    );

    void drawSprite();

};




