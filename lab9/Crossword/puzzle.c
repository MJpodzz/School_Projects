// Mahmoud Hafez
// puzzle.c
// Lab9: Functions File
//  Contains the functions needed for the crossword game to operate

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "puzzle.h"

#define MAX_WORDS 20
#define MAX_LENGTH 15

/*I've utilized a bubbleSort() function, which operates by accepting an array of words as its parameter,
and iteratively arranges the array based on word length until it's fully sorted. The function accomplishes this by examining
if the preceding word in the array is shorter; if it is, a swap occurs using a temporary array and strcpy.*/

void bubbleSort(char words[][MAX_LENGTH + 1], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strlen(words[j]) < strlen(words[j + 1]))
            {
                char temp[MAX_LENGTH + 1];
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }
}

/* A function that ascertain whether a word meets the criteria for inclusion in the words array.
If the word exceeds a certain length or is too short, it is discarded.
Additionally, if the input contains any special characters or numbers, the word is also discarded.*/

bool isValidWord(const char *word)
{
    int length = strlen(word);
    if (length < 2 || length > 15)
    {
        return false;
    }
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (!isalpha((unsigned char)word[i]))
        {
            return false;
        }
    }
    return true;
}


void toUppercase(char *word) //function converting the input words into capitalized letters. 
{
    for (int i = 0; i < strlen(word); i++)
    {
        word[i] = toupper(word[i]);
    }
}

//function takes in 2D array as input, and sets eachvalue in the 2D to a "."*/
void initializeBoard(char board[MAX_LENGTH][MAX_LENGTH])
{
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        for (int j = 0; j < MAX_LENGTH; j++)
        {
            board[i][j] = '.';
        }
    }
}

//takes the longest word in the array (iow, the 1st word in the array after being sorted), and places it in the middle of the teh board
void placeLongestWord(char board[MAX_LENGTH][MAX_LENGTH], char *word)
{
    int i;
    int length = strlen(word);
    int start = (MAX_LENGTH - length) / 2;
    printf("%d, %d ", start + i, MAX_LENGTH / 2);
    for (i = 0; i < length; i++)
    {
        board[MAX_LENGTH / 2][start + i] = word[i];
    }
    printf(" Across ");
    strfry(word);
    printf(" %2s\n", word);
}

//displays the current state of the 2D array board:
void printBoard(char board[MAX_LENGTH][MAX_LENGTH])
{
    for (int i = 0; i < MAX_LENGTH + 2; i++)
    {
        printf("-");
    }
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        printf("\n|");
        for (int j = 0; j < MAX_LENGTH; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("|");
    }
    printf("\n");
    for (int i = 0; i < MAX_LENGTH + 2; i++)
    {
        printf("-");
    }
    printf("\n");
}


//Places empty space if the character is in the alphabet, and '#' if the character is NOT in the alphabet:
void printPuzzle(char board[MAX_LENGTH][MAX_LENGTH])
{
    for (int i = 0; i < MAX_LENGTH + 2; i++)
    {
        printf("-");
    }
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        printf("\n|");
        for (int j = 0; j < MAX_LENGTH; j++)
        {
            if (isalpha(board[i][j]))
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("|");
    }
    printf("\n");
    for (int i = 0; i < MAX_LENGTH + 2; i++)
    {
        printf("-");
    }
    printf("\n");
}

/* placeWords() function puts all words on the board except the longest (iow, the 1st one).
1. Iterates through each word, assigning to a pointer.
2. Nested For-Loop traverses each 2D array character, starting at 0,0.
3. While-Loop iterates through each character in the word.
4. Checks for horizontal and vertical placement possibilities.
5. Uses horizontal() and vertical() functions to determine placement.
6. Two for-loops place characters around the intersection.
7. Boolean "found" tracks successful placement. Unsuccessful words are added to "missedWords".
*/

void placeWords(char board[MAX_LENGTH][MAX_LENGTH], char words[][MAX_LENGTH + 1], int count, char missedWords[MAX_WORDS][MAX_LENGTH + 1], int *p)
{
    *p = 0;
    for (int idx = 1; idx < count; idx++)
    {
        char *word = words[idx];
        int wordLength = strlen(word);
        bool found = false;
        for (int i = 0; i < MAX_LENGTH; i++)
        {
            for (int j = 0; j < MAX_LENGTH; j++)
            {
                int indx = 0;
                while (word[indx] != '\0')
                {
                    if (board[i][j] == word[indx])
                    {
                        bool hor = (j - indx >= 0) && (j + (wordLength - indx) <= MAX_LENGTH)

                                   && horizontal(board, wordLength, i, j);

                        bool ver = (i - indx >= 0) && (i + (wordLength - indx) <= MAX_LENGTH)

                                   && vertical(board, wordLength, i, j);
                        if (hor)
                        {
                            int k;
                            for (k = indx; k > 0; k--)
                            {
                                board[i][j - k] = word[indx - k];
                            }
                            printf("%d, %d ", j - indx, i - k); // clues
                            for (k = 0; k < wordLength - indx; k++)
                            {
                                board[i][j + k] = word[indx + k];
                            }
                            printf(" Across ");
                            strfry(word);
                            printf(" %2s\n", word);
                            found = true;
                            break;
                        }

                        else if (ver)
                        {
                            int k;
                            for (k = indx; k > 0; k--)
                            {
                                board[i - k][j] = word[indx - k];
                            }
                            printf("%d, %d ", j - k, i - indx); // clues
                            for (k = 0; k < wordLength - indx; k++)
                            {
                                board[i + k][j] = word[indx + k];
                            }
                            printf(" Down ");
                            strfry(word);
                            printf(" %2s\n", word);
                            found = true;
                            break;
                        }
                    }
                    indx++;
                    if (found)
                    {
                        break;
                    }
                }
                if (found)
                {
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }
        if (!found)
        {
            strcpy(missedWords[*p], word);
            (*p)++;
        }
    }
}

// horizontal() checks if a word can be placed horizontally in the 2D array. It starts from the right side, checking for available space directly and ensuring empty spaces above and below, avoiding direct neighbors
bool horizontal(char board[MAX_LENGTH][MAX_LENGTH], int sz, int x, int y)
{
    for (int i = y - 1; i >= y - (sz - 1) && i >= 0; i--)
    {
        if (board[x][i] != '.')
            return false;
        if (i - 1 >= 0 && board[x][i - 1] != '.')
            return false;
        if (x + 1 < MAX_LENGTH && board[x + 1][i] != '.')
            return false;
        if (x - 1 >= 0 && board[x - 1][i] != '.')
            return false;
    }
    for (int i = y + 1; i < y + sz && i < MAX_LENGTH; i++)
    {
        if (board[x][i] != '.')
            return false;
        if (i + 1 < MAX_LENGTH && board[x][i + 1] != '.')
            return false;
        if (x + 1 < MAX_LENGTH && board[x + 1][i] != '.')
            return false;
        if (x - 1 >= 0 && board[x - 1][i] != '.')
            return false;
    }
    return true;
}

// vertical() function mirrors horizontal() but checks vertical placement, ensuring no direct neighbors to the left or right:
bool vertical(char board[MAX_LENGTH][MAX_LENGTH], int sz, int x, int y)
{
    for (int i = x - 1; i >= x - (sz - 1) && i >= 0; i--)
    {
        if (board[i][y] != '.')
            return false;
        if (i - 1 >= 0 && board[i - 1][y] != '.')
            return false;
        if (y + 1 < MAX_LENGTH && board[i][y + 1] != '.')
            return false;
        if (y - 1 >= 0 && board[i][y - 1] != '.')
            return false;
    }
    for (int i = x + 1; i < x + sz && i < MAX_LENGTH; i++)
    {
        if (board[i][y] != '.')
            return false;
        if (i + 1 < MAX_LENGTH && board[i + 1][y] != '.')
            return false;
        if (y + 1 < MAX_LENGTH && board[i][y + 1] != '.')
            return false;
        if (y - 1 >= 0 && board[i][y - 1] != '.')
            return false;
    }
    return true;
}

//Mirrors the functionality of another function, taking a file as input and printing clues and boards to it using fprintf instead of printf:
void printWords(char board[MAX_LENGTH][MAX_LENGTH], char words[][MAX_LENGTH + 1], int count, char missedWords[MAX_WORDS][MAX_LENGTH + 1], int *pt, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf("Error opening file\n");
        exit(1);
    }
    int idx;
    int length = strlen(words[0]);
    int start = (MAX_LENGTH - length) / 2;
    char *p = words[0];
    fprintf(file, "Clues: \n");
    fprintf(file, "%d, %d ", start + idx, MAX_LENGTH / 2); // clues
    for (idx = 0; idx < length; idx++)
    {
        board[MAX_LENGTH / 2][start + idx] = *p;
        p++;
    }
    fprintf(file, " Across ");
    strfry(words[0]);
    fprintf(file, " %2s\n", words[0]);
    for (int idx = 1; idx < count; idx++)
    {
        char *word = words[idx];
        int wordLength = strlen(word);
        bool found = false;
        for (int i = 0; i < MAX_LENGTH; i++)
        {
            for (int j = 0; j < MAX_LENGTH; j++)
            {
                int indx = 0;
                while (word[indx] != '\0')
                {
                    if (board[i][j] == word[indx])
                    {

                        bool hor = (j - indx >= 0) && (j + (wordLength - indx) <= MAX_LENGTH)

                                   && horizontal(board, wordLength, i, j);

                        bool ver = (i - indx >= 0) && (i + (wordLength - indx) <= MAX_LENGTH)

                                   && vertical(board, wordLength, i, j);
                        if (hor)
                        {
                            int k;
                            for (k = indx; k > 0; k--)
                            {
                                board[i][j - k] = word[indx - k];
                            }
                            fprintf(file, "%d, %d ", j - indx, i - k); // clues
                            for (k = 0; k < wordLength - indx; k++)
                            {
                                board[i][j + k] = word[indx + k];
                            }
                            fprintf(file, " Across ");
                            strfry(word);
                            fprintf(file, " %2s\n", word);
                            found = true;
                            break;
                        }
                        else if (ver)
                        {
                            int k;
                            for (k = indx; k > 0; k--)
                            {
                                board[i - k][j] = word[indx - k];
                            }
                            fprintf(file, "%d, %d ", j - k, i - indx); // clues
                            for (k = 0; k < wordLength - indx; k++)
                            {
                                board[i + k][j] = word[indx + k];
                            }
                            fprintf(file, " Down ");
                            strfry(word);
                            fprintf(file, " %2s\n", word);
                            found = true;
                            break;
                        }
                    }
                    indx++;
                    if (found)
                    {

                        break;
                    }
                }
                if (found)
                {
                    break;
                }
            }
            if (found)
            {
                break;
            }
        }
        if (!found)
        {
            strcpy(missedWords[*pt], word);
            (*pt)++;
        }
    }
    // print the solution
    fprintf(file, "\nSolution: \n");
    for (int i = 0; i < MAX_LENGTH + 2; i++)
    {
        fprintf(file, "-");
    }
    fprintf(file, "\n");
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        fprintf(file, "|");
        for (int j = 0; j < MAX_LENGTH; j++)
        {
            fprintf(file, "%c", board[i][j]);
        }
        fprintf(file, "|\n");
    }
    for (int i = 0; i < MAX_LENGTH + 2; i++)
    {
        fprintf(file, "-");
    }
    fprintf(file, "\n");
    // print crossword puzzle
    fprintf(file, "\nCrossword puzzle: \n");
    for (int i = 0; i < MAX_LENGTH + 2; i++)
    {

        fprintf(file, "-");
    }
    fprintf(file, "\n");
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        fprintf(file, "|");
        for (int j = 0; j < MAX_LENGTH; j++)
        {
            if (isalpha(board[i][j]))
            {
                fprintf(file, " ");
            }
            else
            {
                fprintf(file, "#");
            }
        }
        fprintf(file, "|\n");
    }
    for (int i = 0; i < MAX_LENGTH + 2; i++)
    {
        fprintf(file, "-");
    }
    fprintf(file, "\n");
    fprintf(file, "Words that could not be placed: ");
    if (*pt > 0)
    {
        for (int i = 0; i < *pt; i++)
        {
            fprintf(file, "%s ", missedWords[i]); // display all the missed words
        }
    }
    else
    {
        fprintf(file, "N/A\n");
    }
}

//Gets all of the words in a file, and contiously adds the words to an array until a "." is found:
void readWords(char filename[], char words[MAX_WORDS][MAX_LENGTH + 1], int *count)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while (*count < MAX_WORDS && fscanf(file, "%s", words[*count]) == 1)
    {
        if (strcmp(words[*count], ".") == 0)
        {
            break;
        }
        if (isValidWord(words[*count]))
        {
            toUppercase(words[*count]);
            (*count)++;
        }
        else
        {
            printf("Invalid word found in file: %s\n", words[*count]);
        }
    }
}

//That's it! Thank you for Grading!
