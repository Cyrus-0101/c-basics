#include "stdio.h"

/**
 *
 * @file char.c
 *
 * @brief Using getchar() and putchar() to read characters and output
 * characters.
 */

/**
 *
 * Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
 * Exercise 1-7. Write a program to print the value of EOF.
 */

int main()
{
    int c;

    // Print all characters back to the terminal
    // then when user presses Ctrl + D/ EOF end the program
    // while((c = getchar()) != EOF) {
    //     putchar(c);
    // }

    // This will print 1 for each character until EOF, then 0
    while ((c = getchar()) != EOF)
    {
        printf("getchar() != EOF: %d\n", c != EOF); // Always 1
    }

    // After EOF is received, loop breaks, show final result
    printf("getchar() != EOF: %d\n", c != EOF); // Should be 0
    return 0;
}