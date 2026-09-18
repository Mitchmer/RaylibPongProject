#include <powerup.h>

PowerUp::PowerUp(
    Vector2 pos,
    PowerUpType t,
    Rectangle s
) : position{pos}, type{t}, sprite{s} {
    position.x -= s.width / 2;
    position.y -= s.height / 2;
    s.x = pos.x;
    s.y = pos.y;
}


void PowerUp::drawSprite(){
    DrawRectangle(position.x, position.y, sprite.width, sprite.height, RED);
}
