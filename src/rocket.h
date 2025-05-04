#ifndef ROCKET_H
#define ROCKET_H

#include "raylib.h"

class Rocket
{
public:
    Rocket(float x, float y, float rotation);
    void move();
    void show();

private:
    Vector2 pos;
    const float radius = 30;
    const float arrowSize = 20;
    const float arrowDistanceFromBorder = 50;
    float speed = 200;
    float slowSpeed = 100;
    float normalSpeed = 200;
    float turboSpeed = 500;
    float turning = 1.5;
    float slowTurning = 3;
    float normalTurning = 1.5;
    float turboTurning = 0.5;
    float angle;
    Color color = BLACK;
    Color arrowColor = GRAY;
};

#endif
