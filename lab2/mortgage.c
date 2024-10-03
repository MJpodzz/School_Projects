//Mahmoud Hafez (mhafez)
//Mortgage.c
//Lab2: Part II: Mortgage Calculator
//Program: display an amortization table based on the user inputs

#include <stdio.h>

int main() {
    double principal, annualInterestRate, monthlyPayment;
    double monthlyInterestRate, interest, payment, totalPayments = 0;
    int month = 0;

    // User inputs with validation
    printf("Enter the loan principal: ");
    while (scanf("%lf", &principal), principal < 0) {
        printf("Error: Principal cannot be negative. Please enter a valid loan principal: ");
    }

    printf("Enter the annual interest rate (%%): ");
    while (scanf("%lf", &annualInterestRate), annualInterestRate < 0) {
        printf("Error: Interest rate cannot be negative. Please enter a valid annual interest rate (%%): ");
    }

    printf("Enter the desired monthly payment: ");
    while (scanf("%lf", &monthlyPayment), monthlyPayment < 0) {
        printf("Error: Monthly payment cannot be negative. Please enter a valid monthly payment: ");
    }

    // Calculate the monthly interest rate
    monthlyInterestRate = annualInterestRate / 12 / 100;

    // Check if monthly payment is less than first month's interest
    if (monthlyPayment <= (principal * monthlyInterestRate)) {
        printf("Error: Monthly payment is too small to cover the interest. Please enter a higher payment.\n");
        return 1; // Stop execution with an error code
    }

    printf("\nMonth\tPayment\tInterest  Balance\n");

    // Amortization schedule calculation
    while (principal > 0) {
        month++;
        interest = principal * monthlyInterestRate;
        payment = (principal + interest < monthlyPayment) ? principal + interest : monthlyPayment;
        if (principal < payment) { // Final payment adjustment
            payment = principal + interest;
        }
        principal = principal + interest - payment;
        totalPayments += payment;

        printf("%d\t$%.2f\t$%.2f\t$%.2f\n", month, payment, interest, principal > 0 ? principal : 0.0); // Avoid displaying negative balance

        if (principal < 1.0) principal = 0; // To handle floating point imprecision
    }

    // Calculate and display total time and amount paid
    printf("\nYou paid a total of $%.2f over %d years and %d months.\n", totalPayments, month / 12, month % 12);

    return 0;
}
