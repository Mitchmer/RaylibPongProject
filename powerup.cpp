#include <powerup.h>
#include <math.h>

PowerUp::PowerUp(
    PowerUpType t,
    Rectangle s
) : type{t}, sprite{s} {
    position.x = s.x;
    position.y = s.y;
    center = Vector2{sprite.width / 2.0f, sprite.height / 2.0f};
    boundaryDistance = Vector2Distance(position, Vector2{position.x + center.x,position.y + center.y});
}


void PowerUp::drawSprite(){
    DrawRectanglePro(sprite, center, rotation, RED);
    // std::cout << "Sprite: x: " << sprite.x << " y: " << sprite.y << std::endl;
    // std::cout << "Position: x: " << position.x << " y: " << position.y << std::endl;
}

void PowerUp::rotate(float rot) {
    if (rotation > 360.0f)
        rotation -= (360.0f);
    rotation += rot;
}

void PowerUp::setPositionX(float x) {
    sprite.x = x;
    position.x = x;
    center.x = sprite.width / 2.0f;
}
void PowerUp::setPositionY(float y) {
    sprite.y = y;
    position.y = y;
    center.y = sprite.height / 2.0f;
}

void PowerUp::setPosition(const Vector2& v) {
    sprite.x = v.x;
    sprite.y = v.y;

    position.x = v.x;
    position.y = v.y;

    center.x = sprite.width / 2.0f;
    center.y = sprite.height / 2.0f;
}

float PowerUp::getPositionX() const {
    return center.x;
}

float PowerUp::getPositionY() const {
    return center.y;
}

Vector2 PowerUp::getPosition() const {
    //Vector2 c{center};
    return center;
}

float PowerUp::getWidth() const {
    return sprite.width;
}

float PowerUp::getHeight() const {
    return sprite.height;
}