//Mahmoud Hafez (mhafez)
//table.c
//Lab2: Part I: Multiplication Table
//Program: display a multiplication table for x and y axes that are entered by the user


#include <stdio.h>

int main() {
    int x, y; // Variables to store the dimensions of the table.

    // Prompt the user for the size of the table on the X axis and read the input.
    printf("Enter the size of the table on the X axis: ");
    scanf("%d", &x);
    // Prompt the user for the size of the table on the Y axis and read the input.
    printf("Enter the size of the table on the Y axis: ");
    scanf("%d", &y);

    // Print the header row of the table.
    printf("  * ");
    for(int i = 1; i <= x; i++) {
        printf("%4d", i); // Print each column header.
    }

    // Print the separator line between headers and table content.
    printf("\n    ");
    for (int w = 1; w <= x; w++) {
        printf("----"); // Print dashes for each column.
    }
    printf("\n");

    // Loop over each row in the table.
    for(int k = 1; k <= y; k++) {
        printf("%3d|", k); // Print the row label.
        // Loop over each column in the current row.
        for(int j = 1; j <= x; j++) {
            printf("%4d", k * j); // Calculate and print the product for the current cell.
        }
        printf("\n"); // Move to the next line after printing a row.
    }

    return 0; // Indicate successful completion of the program.
}
