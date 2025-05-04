#include "betterRaylib.h"
#include "raylib.h"
#include "raymath.h"
#include <vector>
#include <cmath>

// Define global variables
Vector2 translation = {0, 0};
std::vector<Vector2> translations;
Vector4 strokeColor = {0, 0, 0, 255};
float weight = 1.0f;

// Function implementations
void Line(Vector2 start, Vector2 end)
{
    DrawLineEx({translation.x + start.x, translation.y + start.y}, {translation.x + end.x, translation.y + end.y}, weight, getStrokeColor());
    DrawCircle(translation.x + start.x, translation.y + start.y, weight / 2, getStrokeColor());
    DrawCircle(translation.x + end.x, translation.y + end.y, weight / 2, getStrokeColor());
}

void Arrow(Vector2 start, Vector2 end, float arrowSize)
{
    Line(start, end);
    Vector2 tri = {end.x, end.y};
    tri = Vector2Normalize(tri);
    tri = Vector2Multiply(tri, {arrowSize, arrowSize});
    push();
    translate(end.x - tri.x, end.y - tri.y);
    Line({tri.x, tri.y}, {-tri.y, tri.x});
    Line({tri.x, tri.y}, {tri.y, -tri.x});
    pop();
}

void push()
{
    translations.push_back(translation);
}

void pop()
{
    if (!translations.empty())
    {
        translation = translations.back();
        translations.pop_back();
    }
}

void translate(float dx, float dy)
{
    translation.x += dx;
    translation.y += dy;
}

void stroke(float val)
{
    strokeColor = {val, val, val, 255};
}

void stroke(float val, float a)
{
    strokeColor = {val, val, val, a};
}

void stroke(float r, float g, float b, float a)
{
    strokeColor = {r, g, b, a};
}

void strokeWeight(float value)
{
    weight = value;
}

Color getStrokeColor()
{
    unsigned char r = (unsigned char)Clamp(strokeColor.x * 255.0f, 0.0f, 255.0f);
    unsigned char g = (unsigned char)Clamp(strokeColor.y * 255.0f, 0.0f, 255.0f);
    unsigned char b = (unsigned char)Clamp(strokeColor.z * 255.0f, 0.0f, 255.0f);
    unsigned char a = (unsigned char)Clamp(strokeColor.w * 255.0f, 0.0f, 255.0f);

    Color newColor = {r, g, b, a};
    return newColor;
}
