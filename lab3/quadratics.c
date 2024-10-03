//Mahmoud Hafez
//quadratics.c
//Lab3: Part I: Quadratic Calculator
//Finds the real roots of the quadratic equation


#include <stdio.h>
#include <math.h>

// Function to compute the discriminant
double discriminant(double a, double b, double c) {
    return b*b - 4*a*c;
}

int main() {
    double a, b, c, D;

    while(1) {
        printf("Enter coefficients a, b, and c: ");
        scanf("%lf %lf %lf", &a, &b, &c);

        // Check if a is 0, then terminate the program
        if(a == 0) {
            break;
        }

        D = discriminant(a, b, c); // Calculate the discriminant

        // Determine the nature of the roots based on the discriminant
        if(D > 0) {
            double root1 = (-b + sqrt(D)) / (2*a);
            double root2 = (-b - sqrt(D)) / (2*a);
            printf("Two distinct real roots: %.2lf and %.2lf\n", root1, root2);
        } else if(D == 0) {
            double root = -b / (2*a);
            printf("One real root: %.2lf\n", root);
        } else {
            printf("No real roots.\n");
        }
    }

    printf("Program terminated.\n");
    return 0;
}
