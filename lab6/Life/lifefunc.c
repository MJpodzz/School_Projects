//Mahmoud Hafez
//lifefunc.c
//Lab6: Play life
//program that simulates the playing or animation of Conway's Game of Life on a 40-by-40 board, displayed as Xs (live cells) and blank spaces (dead cells)

#include "lifefunc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Print top border
    for (int i = 0; i < BOARD_SIZE + 2; i++) printf("-");
    printf("\n");

    // Print board contents
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("|"); // Left border
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("|\n"); // Right border
    }

    // Print bottom border
    for (int i = 0; i < BOARD_SIZE + 2; i++) printf("-");
    printf("\n");
}

void addCell(char board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
        board[x][y] = 'X';
    }
}

void removeCell(char board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
        board[x][y] = ' ';
    }
}

int countNeighbors(char board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // Skip the cell itself
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && board[nx][ny] == 'X') {
                count++;
            }
        }
    }
    return count;
}

void advance(char board[BOARD_SIZE][BOARD_SIZE]) {
    char tempBoard[BOARD_SIZE][BOARD_SIZE];
    memcpy(tempBoard, board, sizeof(char) * BOARD_SIZE * BOARD_SIZE); // Copy current board to temp

    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            int liveNeighbors = countNeighbors(board, x, y);
            if (board[x][y] == 'X') { // Live cell rules
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    tempBoard[x][y] = ' '; // Cell dies
                }
            } else { // Dead cell rules
                if (liveNeighbors == 3) {
                    tempBoard[x][y] = 'X'; // Cell becomes live
                }
            }
        }
    }

    memcpy(board, tempBoard, sizeof(char) * BOARD_SIZE * BOARD_SIZE); // Update the main board
}

void copyBoard(char source[BOARD_SIZE][BOARD_SIZE], char destination[BOARD_SIZE][BOARD_SIZE]) {
    memcpy(destination, source, sizeof(char) * BOARD_SIZE * BOARD_SIZE);
}
