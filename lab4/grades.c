//Mahmoud Hafez (mhafez)
//grades.c
//Lab 4: Part 1: a simple array
//display the grades' average and their standard deviation
#include <math.h>
#include <stdio.h>

// Function prototypes
float calculateAverage(int grades[], int size);
float calculateStandardDeviation(int grades[], int size, float average);

int main() {
    int grades[] = {96, 73, 62, 87, 80, 63, 93, 79, 71, 99, 82, 83, 80, 97, 89, 82, 93, 92, 95, 89, 71, 97, 91, 95, 63, 81, 76, 98, 64, 86, 74, 79, 98, 82, 77, 68, 87, 70, 75, 97,71, 94, 68, 87, 79};

    int size = sizeof(grades) / sizeof(grades[0]);
    printf("Number of grades: %d\n", size);

    float average = calculateAverage(grades, size);
    printf("Average grade: %.2f\n", average);

    float standardDeviation = calculateStandardDeviation(grades, size, average);
    printf("Standard Deviation: %.2f\n", standardDeviation);

    return 0;
}

// Function to calculate average
float calculateAverage(int grades[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += grades[i];
    }
    return (float)sum / size;
}

// Function to calculate standard deviation
float calculateStandardDeviation(int grades[], int size, float average) {
    float variance = 0;
    for (int i = 0; i < size; i++) {
        variance += pow(grades[i] - average, 2);
    }
    variance /= size;
    return sqrt(variance);
}
