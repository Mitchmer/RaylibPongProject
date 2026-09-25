#pragma once
#include <raylib.h>

class Ball {
    private:
        Vector2 position{0.0f,0.0f};
        float radius{1.0f};
        Color color{WHITE};
        Vector2 velocity{1.0f, 1.0f};

    public:

        Ball(
            Vector2 position,
            float radius,
            Color color
        );

        void setPosition(Vector2 vec);
        Vector2 getPosition() const;
        void setVelocity(Vector2 vec);
        Vector2 getVelocity() const;

        void setColor(Color color);
        Color getColor() const;

        void move();
        void draw() const;
};