#include <stdio.h>

/**
 *
 * @file word_per_line.c
 *
 * Here we are trying to print input, one word per line.
 * If a tab separates words we check and separate them using
 * states. IN and OUT
 */

#define IN 1
#define OUT 0

int main()
{
    int c, state = OUT;

    printf("Type paragraph/sentence to display line by line. Press Enter to see the count. Ctrl+D to quit.\n");

    while ((c = getchar()) != EOF)
    {
        // Check if there is a space or tab indicating the end of a word
        if (c == ' ' || c == '\t')
        {
            if (state == IN)
            {
                putchar('\n'); // end of a word
                state = OUT;
            }
        }
        else if (c == '\n')
        {
            if (state == IN)
            {
                putchar('\n');
                state = OUT;
            }

            printf("\nType paragraph/sentence to display line by line. Press Enter to see the count. Ctrl+D to quit.\n");
        }
        else
        {
            putchar(c); // part of a word
            state = IN;
        }
    }

    return 0;
}
