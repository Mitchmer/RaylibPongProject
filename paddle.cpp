#include <paddle.h>

Paddle::Paddle(
    Rectangle r
) : sprite{r} {
    position.x = sprite.x;
    position.y = sprite.y;
}

void Paddle::drawPaddle() const {
    DrawRectangle(position.x, position.y, sprite.width, sprite.height, WHITE);
}

void Paddle::move(Vector2 direction) {
    position.x += direction.x * speedMultX;
    position.y += direction.y * speedMultY;

    sprite.x = position.x;
    sprite.y = position.y;
}

Rectangle Paddle::getSprite() const { return sprite; }

void Paddle::setPositionX(float posX) { position.x = posX; }
void Paddle::setPositionY(float posY) { position.y = posY; }
void Paddle::setPosition(Vector2 pos) { position = pos; }
Vector2 Paddle::getPosition() const { return position; }

void Paddle::setHeight(float h) { sprite.height = h; }
float Paddle::getHeight() const { return sprite.height; }
void Paddle::setWidth(float w) { sprite.width = w; }
float Paddle::getWidth() const { return sprite.width; }

KeyboardKey Paddle::getUpKey() const { return up; }
KeyboardKey Paddle::getDownKey() const { return down; }
KeyboardKey Paddle::getLeftKey() const { return left; }
KeyboardKey Paddle::getRightKey() const { return right; }

void Paddle::setSpeedMult(Vector2 multipliers) {
    speedMultX = multipliers.x;
    speedMultY = multipliers.y;
}

void Paddle::configureControls(KeyboardKey u, KeyboardKey d, KeyboardKey l, KeyboardKey r) {
    up = u;
    down = d;
    left = l;
    right = r;
}