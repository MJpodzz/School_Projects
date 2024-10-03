#include <stdio.h>
#include <ctype.h>
#include <string.h>

const int ALPHABET_SIZE = 26; // Using a const int for the alphabet size

int main() {
    char filename[31];
    int letter_counts[ALPHABET_SIZE];
    int total_chars = 0, total_letters = 0;

    // Initialize the letter_counts array to zero
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        letter_counts[i] = 0;
    }

    // Prompt for filename
    printf("Enter the filename (max 30 characters): ");
    scanf("%30s", filename);

    // Open file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read characters from file and count letters
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        total_chars++;
        if (isalpha(ch)) {
            total_letters++;
            ch = tolower(ch);
            letter_counts[ch - 'a']++;
        }
    }

    // Close the file
    fclose(file);

    // Display results
    printf("Total characters: %d\n", total_chars);
    printf("Total letters: %d\n", total_letters);
    printf("Letter Frequencies:\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        double percentage = (double)letter_counts[i] / total_letters * 100;
        printf("%c: %d (%.1f%%)\n", 'a' + i, letter_counts[i], percentage);
    }

    return 0;
}
