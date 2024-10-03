// Mahmoud Hafez
// puzzle.h
//Lab9: Header File for crosswords.c

#define MAX_WORDS 20
#define MAX_LENGTH 15

void bubbleSort(char words[][MAX_LENGTH + 1], int count);
bool isValidWord(const char *word);
void initializeBoard(char board[MAX_LENGTH][MAX_LENGTH]);
void placeLongestWord(char board[MAX_LENGTH][MAX_LENGTH], char *word);
void placeWords(char board[MAX_LENGTH][MAX_LENGTH], char words[][MAX_LENGTH + 1], int
count, char missedWords[MAX_WORDS][MAX_LENGTH + 1], int *p);
void printBoard(char board[MAX_LENGTH][MAX_LENGTH]);
void printPuzzle(char board[MAX_LENGTH][MAX_LENGTH]);
bool horizontal(char board[MAX_LENGTH][MAX_LENGTH], int sz, int x, int y);
bool vertical(char board[MAX_LENGTH][MAX_LENGTH], int sz, int x, int y);
void readWords(char filename[], char words[MAX_WORDS][MAX_LENGTH + 1], int* count);
void printWords(char board[MAX_LENGTH][MAX_LENGTH], char words[][MAX_LENGTH + 1], int
count, char missedWords[MAX_WORDS][MAX_LENGTH + 1], int *pt, const char *filename);
void toUppercase(char *word);
