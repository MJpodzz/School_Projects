#include <stdio.h>
#include <math.h>

int main() 
{
    double voltage, resistance, power;

    // Ask the user for their input
    printf("Enter the voltage across the resistor (in volts): ");
    scanf("%lf", &voltage);
    printf("Enter the resistance of the resistor (in ohms): ");
    scanf("%lf", &resistance);

    // Calculate the power
    power = pow(voltage, 2) / resistance;

    // Display the result
    printf("Power dissipated in the resistor: %.2lf Watts\n", power);

    return 0;
}
