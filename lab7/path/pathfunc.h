//Mahmoud Hafez
//pathfunc.h
//Lab7_Part1

#ifndef PATHFUNC_H
#define PATHFUNC_H

typedef struct {
  float x;
  float y;
} Point;

// Function prototypes
int readPointsFromFile(const char *filename, Point points[], int maxPoints);
float calculateDistance(const Point *p1, const Point *p2);
float calculateTotalPathLength(Point points[], int numPoints);

#endif // PATHFUNC_H
