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
    Vector2 center{Vector2{0.0f, 0.0f}};
    enum PowerUpType type{SPEEDUP};
    float rotation{0.0f};
    
public:

    Rectangle sprite{Rectangle{0.0f, 0.0f, 1.0f, 1.0f}};
    
    PowerUp(
        PowerUpType type = SPEEDUP, 
        Rectangle sprite = Rectangle{0.0f, 0.0f, 1.0f, 1.0f}
    );

    void drawSprite();
    void rotate(float rotation = 1.0f);

    // TODO: update CENTER when changing position
    // -> make position a private member, access & mtuation through member functions
};




