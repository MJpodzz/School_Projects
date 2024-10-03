//Mahmoud Hafez
//bounce.c
//Lab8_Part2: Bouncing Ball
//A program that conveys a prison for the cicle moving around in a constant velocity vector and a new magunitude keeps getting assigned to it once the mouse is clicked.

#include "gfx.h"
#include <unistd.h> // For usleep
#include <stdlib.h> // For rand() and srand()
#include <time.h> // For time(), to seed random

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define BALL_RADIUS 20
#define VELOCITY_RANGE 10 // Max velocity component magnitude


int main() {
    int x = WIN_WIDTH / 2, y = WIN_HEIGHT / 2; // Start position of the ball
    int vx = 5, vy = 5; // Initial velocity of the ball

    // Seed random number generator
    srand(time(NULL));

    gfx_open(WIN_WIDTH, WIN_HEIGHT, "Bouncing Ball");
    gfx_color(255, 255, 255); // Set ball color to white

    while (1) {
        // Update position based on velocity
        x += vx;
        y += vy;

        // Check for collisions with walls and reflect velocity if needed
        if (x <= BALL_RADIUS || x >= WIN_WIDTH - BALL_RADIUS) {
            vx = -vx; // Reflect horizontal velocity
            x += vx; // Move ball away from the wall to prevent sticking
        }
        if (y <= BALL_RADIUS || y >= WIN_HEIGHT - BALL_RADIUS) {
            vy = -vy; // Reflect vertical velocity
            y += vy; // Move ball away from the wall to prevent sticking
        }

        // Clear screen, draw ball, and flush output
        gfx_clear();
        gfx_circle(x, y, BALL_RADIUS);
        gfx_flush();

        // Check for user input
        if (gfx_event_waiting()) {
            char c = gfx_wait();
            if (c == 1) { // Mouse button 1
                x = gfx_xpos();
                y = gfx_ypos();
                // Assign new random velocity
                vx = (rand() % (VELOCITY_RANGE * 2)) - VELOCITY_RANGE;
                vy = (rand() % (VELOCITY_RANGE * 2)) - VELOCITY_RANGE;
            }
        }

        // Sleep for smooth animation which I can adjust as much as I need
        usleep(20000); 
    }

    return 0;
}

//That's it, Thank you for Grading!
