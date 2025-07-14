#include <stdio.h>

// Macro definitions for cleaner code
#define F fflush(stdout) // Shorthand for flushing stdout buffer
#define ADDITION 1       // Constants for operation selection
#define DIVISION 2
#define MUTLTIPLICATION 3
#define SUBTRACTION 4

/**
 * Addition function
 * @param target: Pointer to store the result
 * @param a: First operand
 * @param b: Second operand
 */
void addition(float *target, float a, float b)
{
    *target = a + b;
    return;
}

/**
 * Division function
 * @param target: Pointer to store the result
 * @param a: Dividend
 * @param b: Divisor (should not be 0)
 */
void division(float *target, float a, float b)
{
    *target = a / b;
    return;
}

/**
 * Multiplication function
 * @param target: Pointer to store the result
 * @param a: First operand
 * @param b: Second operand
 */
void multiplication(float *target, float a, float b)
{
    *target = a * b;
    return;
}

/**
 * Subtraction function
 * @param target: Pointer to store the result
 * @param a: Minuend (number being subtracted from)
 * @param b: Subtrahend (number being subtracted)
 */
void subtraction(float *target, float a, float b)
{
    *target = a - b;
    return;
}

int main()
{
    // Variable declarations
    float x, y,result;
    int op;

    // Function pointer declaration - should include types/signature
    void (*fp)(float *, float, float);

    // User interface for input
    printf("Press 1 for addition, 2 for division, 3 for multiplication, 4 for subtraction, and  0 to quit \n");
    scanf("%d", &op);

    // Break when user selects 0
    if (op == 0)
        return 0;

    printf("Number 1: ");
    F; // Flush output buffer to ensure prompt is displayed
    scanf("%f", &x);
    
    printf("Number 2: ");
    F; // Flush output buffer
    scanf("%f", &y);

    // Assign appropriate function to function pointer based on operation choice
    switch (op)
    {
    case ADDITION:
        fp = addition;
        break;

    case DIVISION:
        fp = division;
        break;

    case MUTLTIPLICATION:
        fp = multiplication;
        break;

    case SUBTRACTION:
        fp = subtraction;
        break;

    default:
        fp = NULL; // Handle invalid operation
        break;
    }

    // Execute the selected operation and display result
    if (fp != NULL)
    {
        fp(&result, x, y);
        printf("Result:   %.2f\n", result);
    }

    return 0;
}