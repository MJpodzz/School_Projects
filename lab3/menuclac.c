//Mahmoud Hafez (mhafez)
//menucalc.c
//Lab 3: Part 3: text menu calculator
//displays a menu of arithmetic operations, prompts the user for their choice, and then asks for two numbers to perform the selected operation.


#include <stdio.h>

double add(double a, double b) {
    return a + b;
}  // Add Function declaration 

double subtract(double a, double b) {
    return a - b; 
}  // Subtract Function declaration

double multiply(double a, double b) {
    return a * b;
}  // Multiply function declaration

double divide(double a, double b) {
    if(b == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0; // Return an indicative value or handle error differently
    }
    return a / b;
} // dividing function declaration

void display_menu() {
    printf("Select an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Quit\n");
    printf("Enter your choice: ");
} //display function to the user to choose an operation

int main() {
    int choice;
    double num1, num2, result;

    while(1) {
        display_menu();
        scanf("%d", &choice);

        if(choice == 5) break; // Quit option

        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        switch(choice) {
            case 1:
                result = add(num1, num2);
                break;
            case 2:
                result = subtract(num1, num2);
                break;
            case 3:
                result = multiply(num1, num2);
                break;
            case 4:
                if(num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                    continue; // Go back to the menu without displaying a result
                }
                result = divide(num1, num2);
                break;
            default:
                printf("Invalid choice. Please choose a valid operation.\n");
                continue; // Go back to the menu without displaying a result
        }

        printf("Result: %.2lf\n", result); // Display the result
    }

    printf("Calculator exited. Goodbye!\n");
    return 0;
}
