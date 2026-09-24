#include <powerup.h>

PowerUp::PowerUp(
    PowerUpType t,
    Rectangle s
) : type{t}, sprite{s} {
    position.x = s.x;
    position.y = s.y;
    center = Vector2{position.x + (sprite.width / 2.0f), position.y + (sprite.height / 2.0f)};
}


void PowerUp::drawSprite(){
    DrawRectanglePro(sprite, center, rotation, RED);
    std::cout << "Sprite: x: " << sprite.x << " y: " << sprite.y << std::endl;
    std::cout << "Position: x: " << position.x << " y: " << position.y << std::endl;
}

void PowerUp::rotate(float rot) {
    if (rotation > 360.0f)
        rotation -= (360.0f);
    rotation += rot;
}
