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
void Paddle::move(Vector2 vec) {}

Rectangle Paddle::getSprite() const { return sprite; }

void Paddle::setPositionX(float posX) { position.x = posX; }
void Paddle::setPositionY(float posY) { position.y = posY; }
void Paddle::setPosition(Vector2 pos) { position = pos; }
void Paddle::setHeight(float h) { sprite.height = h; }
float Paddle::getHeight() const { return sprite.height; }
void Paddle::setWidth(float w) { sprite.width = w; }
float Paddle::getWidth() const { return sprite.width; }