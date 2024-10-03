//Mahmoud Hafez
//polar.c
//Lab 3: Part 2: quadrants and polar coordinates
//determines which quadrant the point lies in, calculates the point's radius and angle in degrees, and then displays this information.

#include <stdio.h>
#include <math.h> // Include for math functions

// Function prototypes
int get_quadrant(double, double);
double get_radius(double, double);
double get_angle(double, double);
void show_info(int, double, double);

// Function to determine the quadrant of a point
int get_quadrant(double x, double y) {
    if (x > 0 && y > 0) return 1; // First quadrant
    if (x < 0 && y > 0) return 2; // Second quadrant
    if (x < 0 && y < 0) return 3; // Third quadrant
    if (x > 0 && y < 0) return 4; // Fourth quadrant
    return 0; // Axis case, which we are ignoring as per instructions
}

// Function to calculate the radius of a point from the origin
double get_radius(double x, double y) {
    return sqrt(x * x + y * y); // Uses Pythagorean theorem
}

// Function to calculate the angle of a point in degrees
double get_angle(double x, double y) {
    double angleRadians = atan2(y, x); // atan2 handles all quadrants correctly
    return angleRadians * (180 / M_PI); // Convert radians to degrees
}

// Function to display the quadrant, radius, and angle of a point
void show_info(int quadrant, double radius, double angle) {
    printf("Quadrant: %d\n", quadrant);
    printf("Radius: %.2f\n", radius);
    printf("Angle: %.2f degrees\n", angle);
}

// Main function
int main() {
    double x, y;

    // Prompt user for x and y coordinates
    printf("Enter the x coordinate: ");
    scanf("%lf", &x);
    printf("Enter the y coordinate: ");
    scanf("%lf", &y);

    // Calculate quadrant, radius, and angle
    int quadrant = get_quadrant(x, y);
    double radius = get_radius(x, y);
    double angle = get_angle(x, y);

    // Display the information
    show_info(quadrant, radius, angle);

    return 0; // End of program
}




