#include <raylib.h>
#include <raymath.h>
#include <powerup.h>
#include <paddle.h>
#include <random>
using namespace std;

const float window_width{1280.0f};
const float window_height{720.0f};
const float POWER_UP_SPAWN_INTERVAL{4.0f};

Vector2 generateRandomPositon(float boundaryX, float boundaryY) {   
    random_device rd;
    mt19937 gen(rd()); 

    uniform_real_distribution<float> distrX(boundaryX, window_width - boundaryX);
    uniform_real_distribution<float> distrY(boundaryY, window_height - boundaryY);   

    float x = distrX(gen);
    float y = distrY(gen);

    Vector2 vector{x, y};
    return vector;
}

float generateRandomFloat(float begin = 0.0f, float end = 100.0f) {   
    random_device rd;
    mt19937 gen(rd()); 

    uniform_real_distribution<float> distrX(begin, end); 

    return distrX(gen);
}

int main()
{

    InitWindow(window_width, window_height, "Simple Pong");
    SetTargetFPS(60);

    Rectangle basicPowerUpSprite{50.0f, 50.0f, 100.0f, 100.0f};
    
    PowerUp currentPowerUp{PowerUp::PowerUpType::SPEEDUP, basicPowerUpSprite};
    float timeLastSpawned = 0.0f;
    float rotationSpeed = 1.0f;

    Paddle player1Paddle{Rectangle{10.0f, 10.0f, 20.0f, 100.0f}};

    float basicRotation = 0.0f;

    while (!WindowShouldClose())
    {
        // float accumulator 
        const float currentTime = GetTime();
        
        // render
        BeginDrawing();
        player1Paddle.drawPaddle();
        
        if(currentTime - timeLastSpawned > POWER_UP_SPAWN_INTERVAL){
            Vector2 randomPosition = generateRandomPositon(currentPowerUp.boundaryDistance, currentPowerUp.boundaryDistance);
            currentPowerUp.setPosition(randomPosition);
            timeLastSpawned = currentTime;
            rotationSpeed = generateRandomFloat(5.0f, 20.0f);
        }
        currentPowerUp.rotate(rotationSpeed);
        currentPowerUp.drawSprite();
        ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
