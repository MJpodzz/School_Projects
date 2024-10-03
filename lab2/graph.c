//Mahmoud Hafez (mhafez)
//graph.c
//Lab2: Part III: ASCII Plot
//Program: generates a simple plot of a mathematical function

#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {
    double x, y;
    double minX = -4 * PI, maxX = 4 * PI;
    double maxY = -1e9, minY = 1e9; // Start with extreme values for min and max
    double step = 0.1; // Increment step for x
    double maxXValue, minXValue, yValue;

    printf("Plot for the function y = sin(x) + cos(2*x) from %.2f to %.2f\n\n", minX, maxX);

    for(x = minX; x <= maxX; x += step) {
        y = sin(x) + cos(2*x);

        // Check for max and min values
        if (y > maxY) {
            maxY = y;
            maxXValue = x;
        }
        if (y < minY) {
            minY = y;
            minXValue = x;
        }

        // Print the x and y values and the bar
        printf("x=%.2f y=%.2f ", x, y);
        int barLength = (int)(10 * (y + 2)); // Adjusting scale and shift for visualization
        for (int i = 0; i < barLength; i++) {
            printf("#");
        }
        printf("\n");
    }

    // Display max and min values
    printf("\nMaximum occurs at x = %.2f, y = %.2f\n", maxXValue, maxY);
    printf("Minimum occurs at x = %.2f, y = %.2f\n", minXValue, minY);

    return 0;
}
