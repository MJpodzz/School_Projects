//Mahmoud Hafez
//crossword.c
//Lab9: Main File
//A program that generates a crossword game board followed by the solutions and clues that help the user to solve it.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "puzzle.h"

#define MAX_WORDS 20
#define MAX_LENGTH 15

int main(int argc, char *argv[]) {
    char words[MAX_WORDS][MAX_LENGTH + 1];
    char board[MAX_LENGTH][MAX_LENGTH];
    int count = 0;
    char missedWords[MAX_WORDS][MAX_LENGTH + 1];
    int pct;

    initializeBoard(board);
        if (argc == 1) {
        printf("Please enter your words for the crossword followed by a \".\" \n");
        char input[MAX_LENGTH + 1];

        while (count < MAX_WORDS) {
            scanf("%s", input);
            if (strcmp(input, ".") == 0) {
            break;
            }

            if (isValidWord(input)) {
                toUppercase(input);
                strcpy(words[count], input);
                count++;
            } else {
            printf("Invalid input, try again.\n");
            }
        }

    bubbleSort(words, count);
        
        } else if (argc == 2) {
            readWords(argv[1], words, &count);
            bubbleSort(words, count);
        } else if (argc == 3) {
            readWords(argv[1], words, &count);
            bubbleSort(words, count);
        } else {
            printf("Error: Incorrect number of arguments. Please Try Again!\n");
            return 1;
        }

        if(argc == 1 || argc == 2){
            printf("Clues: \n");
            placeLongestWord(board, words[0]);
            placeWords(board, words, count, missedWords, &pct);
            printf("\nSolution:\n");
            printBoard(board);
            printf("\nCrossword puzzle:\n");
            printPuzzle(board);
            printf("Words that could not be placed: ");
            if(pct > 0){
                for(int i = 0; i < pct; i++){
                printf("%s ", missedWords[i]); // display the words that failed to be placed
                }
                printf("\n");
            } else {
                printf("All were placed sucssesfully\n");
            }
        }

        if (argc == 3){
            printWords(board, words, count, missedWords, &pct, argv[2]);
            printf("Outputs haven been writtien to this file: \"%s\"\n", argv[2]);
        }

return 0;
}

//That's all. Thank you for Grading!
