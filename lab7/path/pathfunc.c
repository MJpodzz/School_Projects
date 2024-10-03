//Mahmoud Hafez
//pathfunc.c
//Lab7_Part1: Functions file for path program

#include <stdio.h>
#include <math.h>
#include "pathfunc.h"

int readPointsFromFile(const char *filename, Point points[], int maxPoints) {
    FILE *file = fopen(filename, "r");
    if (!file) return -1; // File opening failed

    int count = 0;
    while (fscanf(file, "%f %f", &points[count].x, &points[count].y) == 2 && count < maxPoints) {
        count++;
    }

    fclose(file);
    return count; // Number of points read
}

float calculateDistance(const Point *p1, const Point *p2) {
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

float calculateTotalPathLength(Point points[], int numPoints) {
    float totalLength = 0.0;
    for (int i = 1; i < numPoints; i++) {
        totalLength += calculateDistance(&points[i - 1], &points[i]);
    }
    return totalLength;
}
