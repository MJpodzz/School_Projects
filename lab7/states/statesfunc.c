//Mahmoud Hafez
//statesfunc.c
//Lab7_Part2: US States and Capitals


#include "statesfunc.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Utility function to convert string to uppercase
void toUpperCase(char *str) {
    while (*str) {
        *str = toupper((unsigned char) *str);
        str++;
    }
}

// Load data from CSV file
void loadData(const char* fileName, State states[], int* count) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    while (fscanf(file, "%[^,],%[^,],%[^,],%d\n", states[*count].abbreviation, states[*count].name, states[*count].capital, &states[*count].yearJoined) != EOF) {
        toUpperCase(states[*count].abbreviation); // Ensure abbreviation is uppercase for consistent comparisons
        (*count)++;
        if (*count >= 100) break; // Prevent exceeding the maximum array size
    }

    fclose(file);
}

// Display menu options to the user
void displayMenu() {
    printf("\nMenu Options:\n");
    printf("1. List all states\n");
    printf("2. Find state info by abbreviation\n");
    printf("3. Find capital info by state name or abbreviation\n");
    printf("4. List states by year\n");
    printf("5. Exit\n");
}

// List all states
void listAllStates(const State states[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s (%s) - Capital: %s, Joined: %d\n", states[i].name, states[i].abbreviation, states[i].capital, states[i].yearJoined);
    }
}

// Find state info by abbreviation
void findStateInfo(const State states[], int count) {
    char abbreviation[4];
    printf("Enter state abbreviation: ");
    scanf("%3s", abbreviation);
    toUpperCase(abbreviation);

    for (int i = 0; i < count; i++) {
        if (strcmp(states[i].abbreviation, abbreviation) == 0) {
            printf("State: %s, Capital: %s, Year Joined: %d\n", states[i].name, states[i].capital, states[i].yearJoined);
            return;
        }
    }

    printf("State with abbreviation '%s' not found.\n", abbreviation);
}

// Find capital info by state name or abbreviation
void findCapitalInfo(const State states[], int count) {
    char input[50];
    printf("Enter state name or abbreviation: ");
    scanf("%49s", input);
    toUpperCase(input);

    for (int i = 0; i < count; i++) {
        if (strcmp(states[i].abbreviation, input) == 0 || strcasecmp(states[i].name, input) == 0) {
            printf("Capital of %s is %s.\n", states[i].name, states[i].capital);
            return;
        }
    }

    printf("No matching state found for '%s'.\n", input);
}

// List states by year
void listStatesByYear(const State states[], int count) {
    int year;
    printf("Enter year: ");
    scanf("%d", &year);

    printf("States joined in %d or earlier:\n", year);
    for (int i = 0; i < count; i++) {
        if (states[i].yearJoined <= year) {
            printf("%s (%s) - Joined: %d\n", states[i].name, states[i].abbreviation, states[i].yearJoined);
        }
    }
}
