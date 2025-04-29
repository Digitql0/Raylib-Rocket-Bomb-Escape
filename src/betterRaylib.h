#ifndef BETTER_RAYLIB_H
#define BETTER_RAYLIB_H

#include "raylib.h"
#include <vector>

// Declare global variables with extern
extern Vector2 translation;
extern std::vector<Vector2> translations;
extern Vector4 strokeColor;
extern float weight;

// Function declarations
void Line(Vector2 start, Vector2 end);
void Arrow(Vector2 start, Vector2 end, float arrowSize);
void push();
void pop();
void translate(float dx, float dy);
void stroke(float val);
void stroke(float val, float a);
void stroke(float r, float g, float b, float a);
void strokeWeight(float value);
Color getStrokeColor();

#endif