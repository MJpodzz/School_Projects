//Mahmoud Hafez
//playlife.c
//Lab6: PlayLife
//program that simulates the playing or animation of Conway's Game of Life on a 40-by-40 board, displayed as Xs (live cells) and blank spaces (dead cells).

#include "lifefunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For usleep

// Function Declarations
void runInteractiveMode();
void runBatchMode(const char *filename);
void processCommand(char board[BOARD_SIZE][BOARD_SIZE], char command, int x, int y);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        // Interactive mode
        runInteractiveMode();
    } else if (argc == 2) {
        // Batch mode
        runBatchMode(argv[1]);
    } else {
        fprintf(stderr, "Usage: %s [data file]\n", argv[0]);
        return 1;
    }

    return 0;
}

void runInteractiveMode() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);
    char command;
    int x, y;

    do {
        system("clear");
        displayBoard(board);
        printf("Enter command (a x y, r x y, n, q, p): ");
        scanf(" %c", &command);
        if (command == 'a' || command == 'r') {
            scanf("%d %d", &x, &y);
            processCommand(board, command, x, y);
        } else if (command == 'n') {
            advance(board);
        } else if (command == 'p') {
            while (1) {
                advance(board);
                system("clear");
                displayBoard(board);
                usleep(200000); // Adjust delay as needed
            }
        }
    } while (command != 'q');
}

void runBatchMode(const char *filename) {
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char command;
    int x, y;
    while (fscanf(file, " %c %d %d", &command, &x, &y) == 3) {
        if (command == 'a') {
            addCell(board, x, y);
        }
    }
    fclose(file);

    while (1) {
        advance(board);
        system("clear");
        displayBoard(board);
        usleep(200000); // Adjust delay as needed
    }
}

void processCommand(char board[BOARD_SIZE][BOARD_SIZE], char command, int x, int y) {
    if (command == 'a') {
        addCell(board, x, y);
    } else if (command == 'r') {
        removeCell(board, x, y);
    }
}