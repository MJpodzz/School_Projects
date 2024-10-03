//Mahmoud Hafez
//usastates.c
//Lab7_Part2: US States and Capitals
//Program Main that provide an educational tool for schoolers where they can learn basic info about the US States

#include "statesfunc.h"
#include <stdio.h>

int main() {
    const int MAX_STATES = 100;
    State states[MAX_STATES];
    int count = 0;

    char fileName[256];
    printf("Enter the data file name: ");
    scanf("%s", fileName);

    loadData(fileName, states, &count);

    int choice;
    do {
        displayMenu(); // Move inside the loop to display every time
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                listAllStates(states, count);
                break;
            case 2:
                findStateInfo(states, count);
                break;
            case 3:
                findCapitalInfo(states, count);
                break;
            case 4:
                listStatesByYear(states, count);
                break;
            case 5:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while(choice != 5); // Loop until the user chooses to exit

    return 0;
}

//Thanks for Grading!
