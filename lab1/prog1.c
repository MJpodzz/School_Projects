#include <stdio.h>

int main() {
    int touchdowns, extraPoints, fieldGoals, safeties, totalScore;
 
    // Ask the user for their inputs
    printf("Enter the number of touchdowns: ");
    scanf("%d", &touchdowns);
    printf("Enter the number of extra points: ");
    scanf("%d", &extraPoints);
    printf("Enter the number of field goals: ");
    scanf("%d", &fieldGoals);
    printf("Enter the number of safeties: ");
    scanf("%d", &safeties);

    // Calculate total score
    totalScore = (touchdowns * 6) + extraPoints + (fieldGoals * 3) + (safeties * 2);

    // Display the result
    printf("Total number of points scored by the team: %d\n", totalScore);

    return 0;
}
