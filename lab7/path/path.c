//Mahmoud Hafez
//path.c
//Lab7_Part1: Path Program
//finds the distance length of a path through a sequence of points in an x-y plane

#include <stdio.h>
#include "pathfunc.h"

#define MAX_POINTS 30

int main() {
    Point points[MAX_POINTS];
    char filename[256];

    printf("Enter the data file name: ");
    scanf("%s", filename);

    int numPoints = readPointsFromFile(filename, points, MAX_POINTS);
    if (numPoints == -1) {
        printf("Could not open file.\n");
        return 1;
    }

    printf("There are %d points:\n\n", numPoints);
    printf("   x   |   y\n");
    printf(" ------+--------\n");
    for (int i = 0; i < numPoints; i++) {
        printf("%6g | %6g\n", points[i].x, points[i].y);  // Using %g for compact float representation
    }

    float totalLength = calculateTotalPathLength(points, numPoints);
    printf("\nThe length of the path through them is %.2f\n", totalLength);  // %.2f for two decimal places

    return 0;
}
