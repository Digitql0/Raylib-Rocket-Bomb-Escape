#include "rocket.h"
#include "raylib.h"
#include "raymath.h"
#include "betterRaylib.h"
#include <cmath>

Rocket::Rocket(float x, float y, float rotation)
{
    pos = {x, y};
    angle = rotation;
}

void Rocket::move()
{
    if (IsKeyDown(KEY_A)) // Turn left
    {
        angle -= turning;
    }

    if (IsKeyDown(KEY_D)) // Turn right
    {
        angle += turning;
    }

    if (IsKeyDown(KEY_LEFT_SHIFT) && (turning != slowTurning || speed != slowSpeed))
    {
        turning = slowTurning;
        speed = slowSpeed;
    }

    if (IsKeyDown(KEY_SPACE) && (turning != turboTurning || speed != turboSpeed))
    {
        turning = turboTurning;
        speed = turboSpeed;
    }

    if (((!IsKeyDown(KEY_SPACE) && !IsKeyDown(KEY_LEFT_SHIFT)) || IsKeyDown(KEY_SPACE) && IsKeyDown(KEY_LEFT_SHIFT)) && (turning != normalTurning || speed != normalSpeed))
    {
        turning = normalTurning;
        speed = normalSpeed;
    }

    angle = fmod(angle, 360.0f); // Keep angle within 0-360 degrees

    // Convert angle to radians for trigonometric functions
    float radianAngle = DEG2RAD * angle;

    pos.x += sin(radianAngle) * speed * GetFrameTime(); // Update X position
    pos.y -= cos(radianAngle) * speed * GetFrameTime(); // Update Y position
}

void Rocket::show()
{
    DrawCircle(pos.x, pos.y, radius, color);
    DrawCircleLines(pos.x, pos.y, radius, arrowColor);

    // Convert angle to radians for the arrow direction
    float radianAngle = DEG2RAD * angle;

    push();
    translate(pos.x, pos.y);
    stroke(arrowColor.r, arrowColor.g, arrowColor.b, arrowColor.a);
    strokeWeight(5);
    Arrow({0, 0}, {sin(radianAngle) * arrowSize, -cos(radianAngle) * arrowSize}, 5);
    pop();

    if (pos.x > GetScreenWidth() || pos.x < 0 || pos.y < 0 || pos.y > GetScreenHeight()) // If the Rocket is OOB
    {
        Vector2 arrowPosition = {Clamp(pos.x, arrowDistanceFromBorder, GetScreenWidth() - arrowDistanceFromBorder), Clamp(pos.y, arrowDistanceFromBorder, GetScreenHeight() - arrowDistanceFromBorder)}; // Arrow is on Rocket but clamped In Bounds with some Margin.

        float positionMagnitude = sqrt(pow(pos.x - arrowPosition.x, 2) + pow(pos.y - arrowPosition.y, 2)); // Magnitude of the Vector from the Arrow to the Rocket

        push();
        translate(arrowPosition.x, arrowPosition.y);
        Arrow({0, 0}, {(pos.x - arrowPosition.x) / positionMagnitude * arrowSize, (pos.y - arrowPosition.y) / positionMagnitude * arrowSize}, 5);
        pop();
    }
}
