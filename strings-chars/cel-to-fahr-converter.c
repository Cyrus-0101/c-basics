#include "stdio.h"

// Symbolic Constant. Good Practice to avoid obscurity

#define LOWER 0.0   /* lower limit of table */
#define UPPER 300.0 /* upper limit */
#define STEP 20.0   /* step size */

/**
 * @file cel-to-fahr-converter.c
 *
 * @brief A file that converts celsius to Fahrenheit, from 1 to 300
 * in a step of 20. The formula used is: Celsius=(5/9)(Fahrenheit-32)
 */

int main()
{
    // // Variables to hold Fahrenheit and celsius
    // float fahr, celsius;

    // // Here we user the lower bound of 0, upper-bound of 300 and a ste of 20.
    // // Why?
    // float lower, upper, step;

    // lower = 0;
    // upper = 300;
    // step = 20;

    // fahr = lower;
    printf("Cel\tFahrenheit\n");

    // while (fahr <= upper)
    // {
    //     celsius = (5.0 / 9.0) * (fahr - 32);
    //     // %3d formats the numbers in 3 digits alignment ...
    //     printf("%3.0f\t%6.1f\n", fahr, celsius);
    //     fahr = fahr + step;
    // }

    float fahr;

    for (fahr = UPPER; fahr >= 0; fahr = fahr - STEP)
    {
        // %3d formats the numbers in 3 digits alignment ...
        printf("%3.0f\t%6.1f\n", fahr, ((5.0 / 9.0) * (fahr - 32)));
    }

    return 0;
}