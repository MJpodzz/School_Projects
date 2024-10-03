//Mahmoud Hafez
//symbol.c
//Lab8_Part1: Symbol Program

#include "gfx.h"
#include <stdio.h>
#include <math.h>

#define SIZE 50

void drawSquare(int x, int y, int size);
void drawCircle(int x, int y, int diameter);
void drawTriangle(int x, int y, int size);
void drawPolygon(int x, int y, int sides, int radius);

int main() {
    char c;
    int x, y;

    // Initialize graphics window
    gfx_open(600, 400, "Symbol Typewriter");

    while(1) {
        c = gfx_wait(); // Wait for event
        x = gfx_xpos(); // Get mouse X position
        y = gfx_ypos(); // Get mouse Y position

        // Handle events
        if (c == 'q') { // Quit
            break;
        } else if (c == 1) { // Left mouse click
            gfx_color(0, 0, 255); // Set color to blue
            drawSquare(x, y, SIZE);
        } else if (c == 'c') {
            gfx_color(255, 255, 255); // Set color to white
            drawCircle(x, y, SIZE);
        } else if (c == 't') {
            gfx_color(0, 255, 0); // Set color to green
            drawTriangle(x, y, SIZE);
        } else if (c >= '3' && c <= '9') {
            gfx_color(128, 0, 128); // Set color to purple
            int sides = c - '0'; // Convert char to int
            drawPolygon(x, y, sides, SIZE / 2); // Diameter to radius conversion
        } else if (c == 27) { // ESC key
            gfx_clear();
        }
    }

    return 0;
}

// The Functions:
void drawSquare(int x, int y, int size) {
    int half = size / 2;
    gfx_line(x-half, y-half, x+half, y-half); // Top
    gfx_line(x+half, y-half, x+half, y+half); // Right
    gfx_line(x+half, y+half, x-half, y+half); // Bottom
    gfx_line(x-half, y+half, x-half, y-half); // Left
}

void drawCircle(int x, int y, int diameter) {
    double angle;
    int radius = diameter / 2;
    for(angle = 0; angle < 2 * M_PI; angle += 0.01) {
        int x1 = x + radius * cos(angle);
        int y1 = y + radius * sin(angle);
        int x2 = x + radius * cos(angle + 0.01);
        int y2 = y + radius * sin(angle + 0.01);
        gfx_line(x1, y1, x2, y2);
    }
}

void drawTriangle(int x, int y, int size) {
    int height = (int)(size * sqrt(3) / 2); // Height of the equilateral triangle
    int halfBase = size / 2;

    // Vertices of the triangle
    int x1 = x, y1 = y - (2*height/3); // Top vertex
    int x2 = x - halfBase, y2 = y + (height/3); // Bottom left
    int x3 = x + halfBase, y3 = y + (height/3); // Bottom right

    gfx_line(x1, y1, x2, y2); // Left side
    gfx_line(x2, y2, x3, y3); // Base
    gfx_line(x3, y3, x1, y1); // Right side
}

void drawPolygon(int x, int y, int sides, int radius) {
    double angleStep = 2 * M_PI / sides;
    int i;
    for(i = 0; i < sides; i++) {
        // Calculate the position of each vertex
        int x1 = x + radius * cos(i * angleStep);
        int y1 = y + radius * sin(i * angleStep);
        int x2 = x + radius * cos((i+1) * angleStep);
        int y2 = y + radius * sin((i+1) * angleStep);

        gfx_line(x1, y1, x2, y2); // Draw line between vertices
    }
}
