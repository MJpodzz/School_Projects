//Mahmoud Hafez
//mysayings.c
//Lab5: Part 2: A sayings manager
//program that stores and manages many of your favorite sayings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SAYINGS 50
#define MAX_LENGTH 256
#define MAX_FILENAME 30

//Functions Prototypes
void loadSayings(char sayings[][MAX_LENGTH], const char *filename, int *count);
void displaySayings(const char sayings[][MAX_LENGTH], int count);
void addSaying(char sayings[][MAX_LENGTH], int *count);
void listSayingsContainingSubstring(const char sayings[][MAX_LENGTH], int count);
void saveSayings(const char sayings[][MAX_LENGTH], int count);
void displayMenu();

//Main function that calls the other function by using the switch
int main() {
    char sayings[MAX_SAYINGS][MAX_LENGTH];
    int count = 0;
    char filename[MAX_FILENAME];

    printf("Enter startup data file name: ");
    scanf("%s", filename);
    
    // Opening the file
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("File does not exist. Exiting program.\n");
        return 1;
    }
    fclose(file); //In case it does not exist

    loadSayings(sayings, filename, &count); //Func that loads the sayings

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: displaySayings(sayings, count); break;
            case 2: addSaying(sayings, &count); break;
            case 3: listSayingsContainingSubstring(sayings, count); break;
            case 4: saveSayings(sayings, count); break;
            case 5: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

//The Function that loads the saying from the input file
void loadSayings(char sayings[][MAX_LENGTH], const char *filename, int *count) {
    FILE *file = fopen(filename, "r");
    while (*count < MAX_SAYINGS && fgets(sayings[*count], MAX_LENGTH, file)) {
        sayings[*count][strcspn(sayings[*count], "\n")] = 0; // Remove newline
        (*count)++;
    }
    fclose(file);
}

//Function that diplays the sayings to the stdout:
void displaySayings(const char sayings[][MAX_LENGTH], int count) {
    printf("\n");
    for (int i = 0; i < count; i++) {
        printf("[%d] %s\n", i + 1, sayings[i]);
    }
}

//Function that allows the user ti input a new saying:
void addSaying(char sayings[][MAX_LENGTH], int *count) {
    if (*count >= MAX_SAYINGS) {
        printf("Database is full. Cannot add more sayings.\n");
        return;
    }
    printf("Enter the new saying: ");
    scanf(" %[^\n]", sayings[*count]);
    (*count)++;
}

// Search funtion for sayings contain "string" or "substring" from the user:
void listSayingsContainingSubstring(const char sayings[][MAX_LENGTH], int count) {
    char substring[MAX_LENGTH];
    printf("Enter substring to search for: ");
    scanf(" %[^\n]", substring);
    printf("\nHere are the sayings include [%s]:\n",substring);
    for (int i = 0; i < count; i++) {
        if (strstr(sayings[i], substring)) {
            printf("-> %s\n", sayings[i]);
        }
    }
}

//Function saves the data to an external file created
void saveSayings(const char sayings[][MAX_LENGTH], int count) {
    char newFilename[MAX_FILENAME];
    printf("Enter the filename to save to: ");
    scanf("%s", newFilename);
    FILE *file = fopen(newFilename, "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", sayings[i]);
    }
    fclose(file);
    printf("Sayings saved to %s\n", newFilename);
}

//Function that diplays the switch for the users to choose from:
void displayMenu() {
    printf("\n1. Display all sayings\n");
    printf("2. Enter a new saying\n");
    printf("3. List sayings that contain a given substring\n");
    printf("4. Save all sayings in a new text file\n");
    printf("5. Quit the program\n");
    printf("Enter your choice: ");
}

//That's it, Thank you for grading!
