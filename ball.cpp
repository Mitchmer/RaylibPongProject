#include <ball.h>
#include <raymath.h>

Ball::Ball(Vector2 p, float r, Color c)
    : position{p}, radius{r}, color{c} {}


void Ball::setPosition(Vector2 vec) { position = vec; }
Vector2 Ball::getPosition() const { return position; }

void Ball::setVelocity(Vector2 vec) { velocity = vec; }
Vector2 Ball::getVelocity() const { return velocity; }

void Ball::move() {
    position = Vector2Add(position, velocity);
}

void Ball::draw() const {
    DrawCircle(position.x, position.y, radius, color);
}

