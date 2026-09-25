#include <raylib.h>
#include <raymath.h>
#include <powerup.h>
#include <paddle.h>
#include <ball.h>
#include <random>
using namespace std;

const float window_width{1280.0f};
const float window_height{720.0f};
const float POWER_UP_SPAWN_INTERVAL{4.0f};
const float GAME_MARGINS{20.0f};
const float DEFAULT_PADDLE_SPEED{7.5f};

Vector2 generateRandomPositon(float boundaryLeftX, float boundaryRightX, float boundaryY);
float generateRandomFloat(float begin = 0.0f, float end = 100.0f);
Ball initializeBall();

int main()
{

    InitWindow(window_width, window_height, "Simple Pong");
    SetTargetFPS(60);

    Rectangle basicPowerUpSprite{window_width / 2.0f, window_height / 2.0f, 100.0f, 100.0f};
    
    PowerUp currentPowerUp{PowerUp::PowerUpType::SPEEDUP, basicPowerUpSprite};
    float timeLastSpawned = 0.0f;
    float rotationSpeed = 1.0f;

    Ball ball = initializeBall();

    Paddle player1Paddle{Rectangle{GAME_MARGINS, GAME_MARGINS, 40.0f, 200.0f}};
    player1Paddle.setSpeedMult({0.0f, DEFAULT_PADDLE_SPEED});

    Paddle player2Paddle{Rectangle{GAME_MARGINS, GAME_MARGINS, 40.0f, 200.0f}};
    player2Paddle.setPositionX(window_width - GAME_MARGINS - player2Paddle.getWidth());
    player2Paddle.setSpeedMult({0.0f, DEFAULT_PADDLE_SPEED});
    player2Paddle.configureControls(KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT);

    while (!WindowShouldClose())
    {
        // float accumulator 
        const float currentTime = GetTime();
        
        // render
        BeginDrawing();

        if(currentTime - timeLastSpawned > POWER_UP_SPAWN_INTERVAL){
            Vector2 randomPosition = generateRandomPositon(
                currentPowerUp.boundaryDistance + GAME_MARGINS + player1Paddle.getWidth(), 
                currentPowerUp.boundaryDistance + GAME_MARGINS + player2Paddle.getWidth(),
                currentPowerUp.boundaryDistance
            );
            currentPowerUp.setPosition(randomPosition);
            timeLastSpawned = currentTime;
            rotationSpeed = generateRandomFloat(5.0f, 20.0f);
        }
        currentPowerUp.rotate(rotationSpeed);
        currentPowerUp.drawSprite();

        // player 1
        float x = 0.0f;
        float y = 0.0f;
        Vector2 position = player1Paddle.getPosition();
        if (IsKeyDown(player1Paddle.getUpKey())) {
            // check if it's against the top of the screen
            if (position.y > GAME_MARGINS)
                y = -1.0f;
            else 
                player1Paddle.setPositionY(GAME_MARGINS);
        } else if (IsKeyDown(player1Paddle.getDownKey())) {
            // check if it's against the bottom of the screen
            if ((position.y + player1Paddle.getHeight()) < (window_height - GAME_MARGINS))
                y = 1.0f;
            else 
                player1Paddle.setPositionY(window_height - GAME_MARGINS - player1Paddle.getHeight());
        }
        player1Paddle.move({x, y});

        // player 2
        x = 0.0f;
        y = 0.0f;
        position = player2Paddle.getPosition();
        if (IsKeyDown(player2Paddle.getUpKey())) {
            // check if it's against the top of the screen
            if (position.y > GAME_MARGINS)
                y = -1.0f;
            else 
                player2Paddle.setPositionY(GAME_MARGINS);
        } else if (IsKeyDown(player2Paddle.getDownKey())) {
            // check if it's against the bottom of the screen
            if ((position.y + player2Paddle.getHeight()) < (window_height - GAME_MARGINS))
                y = 1.0f;
            else
                player2Paddle.setPositionY(window_height - GAME_MARGINS - player2Paddle.getHeight());
        }
        player2Paddle.move({x, y});

        ball.move();
        
        player1Paddle.drawPaddle();
        player2Paddle.drawPaddle();
        ball.draw();

        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

Vector2 generateRandomPositon(float boundaryLeftX, float boundaryRightX, float boundaryY) {   
    random_device rd;
    mt19937 gen(rd()); 

    uniform_real_distribution<float> distrX(boundaryLeftX, window_width - boundaryRightX);
    uniform_real_distribution<float> distrY(boundaryY, window_height - boundaryY);   

    float x = distrX(gen);
    float y = distrY(gen);

    Vector2 vector{x, y};
    return vector;
}

float generateRandomFloat(float begin, float end) {   
    random_device rd;
    mt19937 gen(rd()); 

    uniform_real_distribution<float> distrX(begin, end); 

    return distrX(gen);
}

Ball initializeBall() {
    float velocityX = generateRandomFloat(2.5f, 5.0f);
    float velocityY = generateRandomFloat(2.5f, 2.5f);

    // change direction of ball

    Ball ball{{window_width / 2.0f, window_height / 2.0f}, 20.0f, WHITE};
    ball.setVelocity({velocityX, velocityY});

    return ball;
}