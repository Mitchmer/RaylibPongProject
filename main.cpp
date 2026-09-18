#include <raylib.h>
#include <raymath.h>
#include <powerup.h>
#include <random>
using namespace std;

const float window_width{1280.0f};
const float window_height{720.0f};
const float POWER_UP_SPAWN_INTERVAL{10.0f};

Vector2* generateRandomPositon(Rectangle rectangle) {   
    random_device rd;
    mt19937 gen(rd());

    uniform_real_distribution<float> distrX(0, window_width);
    uniform_real_distribution<float> distrY(0, window_height);   
      
    float x = distrX(gen);
    float y = distrY(gen);
    if( x < rectangle.width) {
        x = rectangle.width;
    }else if(x > window_width - rectangle.width){
        x = window_width - rectangle.width;
    }
    if( y < rectangle.height) {
        y = rectangle.height;
    }else if(y > window_height - rectangle.height){
        x = window_height - rectangle.height;
    }
    
    Vector2* vector = new Vector2{x, y};
    
    return vector;
}

int main()
{

    InitWindow(window_width, window_height, "Simple Pong");
    SetTargetFPS(60);

    PowerUp currentPowerUp{};
    Vector2* spritePostion;
    float timeLastSpawned = 0.0f;

    while (!WindowShouldClose())
    {
        // float accumulator 
        const float currentTime = GetTime();
        
        // render
        BeginDrawing();
        Rectangle basicPowerUpSprite{0, 0, 100.0f, 100.0f};
        
        if(currentTime - timeLastSpawned > POWER_UP_SPAWN_INTERVAL){
            spritePostion = generateRandomPositon(basicPowerUpSprite);
            currentPowerUp = PowerUp{*spritePostion, PowerUp::PowerUpType::SPEEDUP, basicPowerUpSprite};
            delete spritePostion;
            timeLastSpawned = currentTime;
        }
        currentPowerUp.drawSprite();
        ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
