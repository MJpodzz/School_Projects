// Mahmoud Hafez
// ndfootball.c
// Lab4: Part 3: ND football
// Displays menu funtions for the user to have fun with the ndfootball data

#include <stdio.h>

// Global arrays for wins and losses
int wins[] = 
 { 6, 8, 6, 8, 5, 5, 6, 6, 8, 7, 4, 6,
   7, 7, 6, 7, 8, 6, 3, 9, 9, 10, 8, 9,
   10, 7, 9, 7, 5, 9, 10, 6, 6, 3, 6, 7, 
   6, 6, 8, 7, 7, 8, 7, 9, 8, 7, 8, 9,
   9, 10, 4, 7, 7, 9, 9, 8, 2, 7, 6, 5, 
   2, 5, 5, 2, 9, 7, 9, 8, 7, 8, 10, 8, 
   8, 11, 10, 8, 9, 11, 9, 7, 9, 5, 6, 7, 
   7, 5, 5, 8, 12, 12, 9, 10, 10, 11, 6, 9, 
   8, 7, 9, 5, 9, 5, 10, 5, 6, 9, 10, 3, 
   7, 6, 8, 8, 12, 9, 8, 10, 4, 10, 12, 11, 
   10, 11, 9, 10 };

int losses[] = 
 { 3, 1, 2, 0, 3, 4, 1, 0, 1, 0, 1, 0,
   0, 0, 2, 1, 1, 1, 1, 0, 0, 1, 1, 1,
   0, 2, 1, 1, 4, 0, 0, 2, 2, 5, 3, 1,
   2, 2, 1, 2, 2, 0, 2, 1, 2, 2, 0, 0,
   0, 0, 4, 2, 2, 0, 1, 2, 8, 3, 4, 5,
   8, 5, 5, 7, 1, 2, 0, 2, 2, 2, 1, 2,
   3, 0, 2, 3, 3, 1, 3, 4, 2, 6, 4, 5,
   5, 6, 6, 4, 0, 1, 3, 3, 1, 1, 5, 3,
   3, 6, 3, 7, 3, 6, 3, 7, 6, 3, 3, 9,
   6, 6, 5, 5, 1, 4, 5, 3, 8, 3, 1, 2,
   2, 2, 4, 3 };
   
int numYears = sizeof(wins) / sizeof(wins[0]); // Calculate the number of years

// Function declarations
void displayRecordForYear(int year);
void displayYearsWithMinLosses(int minLosses);
void displayYearsWithMinWins(int minWins);
void displayWinningStreaks();
void displayYearsWithNoLosses();

int main() {
    int choice, year, minLosses, minWins;

    do {
        // Display menu
        printf("1: Display the record for a given year.\n");
        printf("2: Display years with at least 'n' losses.\n");
        printf("3: Display years with at least 'n' wins.\n");
        printf("4: Display years with winning streaks.\n");
        printf("5: Display years with no losses.\n");
        printf("6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the year: ");
                scanf("%d", &year);
                displayRecordForYear(year);
                break;
            case 2:
                printf("Enter minimum number of losses: ");
                scanf("%d", &minLosses);
                displayYearsWithMinLosses(minLosses);
                break;
            case 3:
                printf("Enter minimum number of wins: ");
                scanf("%d", &minWins);
                displayYearsWithMinWins(minWins);
                break;
            case 4:
                displayWinningStreaks();
                break;
            case 5:
                displayYearsWithNoLosses();
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

//Function Definitions:

//Function displayes the exact record of winning and losing in a specific year
void displayRecordForYear(int year) {
    int index = year - 1900;
    if (index >= 0 && index < numYears) {
        printf("Wins: %d, Losses: %d\n", wins[index], losses[index]);
    } else {
        printf("Data for the year %d is not available.\n", year);
    }
}

// Function diplays the years that has the input min losses
void displayYearsWithMinLosses(int minLosses) {
    printf("Years with at least %d losses: ", minLosses);
    for (int i = 0; i < numYears; i++) {
        if (losses[i] >= minLosses) {
            printf("%d ", 1900 + i);
        }
    }
    printf("\n");
}


// Function diplays the years that has the input min Wins
void displayYearsWithMinWins(int minWins) {
    printf("Years with at least %d wins: ", minWins);
    for (int i = 0; i < numYears; i++) {
        if (wins[i] >= minWins) {
            printf("%d ", 1900 + i);
        }
    }
    printf("\n");
}

//Function displays the winning streaks in arow:
void displayWinningStreaks() {
int startYear = 0;
    int currentStreak = 0;
    int year = 1900;
    int i = 0;

    while (wins[i] != '\0') { // Assuming the arrays are null-terminated
        if (wins[i] > losses[i]) {
            if (currentStreak == 0) {
                startYear = year + i; // Begin new streak
            }
            currentStreak++;
        } else {
            if (currentStreak > 0) {
                // End of a streak, print it
                printf("Winning streak from %d to %d\n", startYear, startYear + currentStreak - 1);
                currentStreak = 0;
            }
        }
        i++;
    }

    // Check if there's a streak at the end of the data
    if (currentStreak > 0) {
        printf("Winning streak from %d to %d\n", startYear, startYear + currentStreak - 1);
    
    }
    }

//Function returns the years that has no losses
void displayYearsWithNoLosses() {
    printf("Years with no losses: ");
    for (int i = 0; i < numYears; i++) {
        if (losses[i] == 0) {
            printf("%d ", 1900 + i);
        }
    }
    printf("\n");
}
