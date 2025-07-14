#include <stdio.h>

/**
 * @file word_length_vertical_histogram.c
 * @brief Prints a vertical histogram of word lengths entered by the user.
 *
 * A word is defined as a sequence of characters separated by spaces, tabs, or newlines.
 * The histogram is displayed every time the user presses Enter.
 * The program resets the histogram after each line of input.
 */

#define MAX_WORD_LEN 15 // we count word lengths up to 14
#define IN 1            // inside a word
#define OUT 0           // outside a word

int main()
{
    int c;
    int word_len = 0;
    int state = OUT;
    int word_lengths[MAX_WORD_LEN];
    int max = 0;

    // Initialize frequency array
    for (int i = 0; i < MAX_WORD_LEN; ++i)
        word_lengths[i] = 0;

    printf("Type text. Press Ctrl+D (EOF) to see vertical word length histogram.\n");

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t')
        {
            if (state == IN)
            {
                state = OUT;
                if (word_len > 0 && word_len < MAX_WORD_LEN)
                {
                    ++word_lengths[word_len];
                }
                word_len = 0;
            }
        }
        else if (c == '\n')
        {
            // Register last word if we're inside one
            if (state == IN && word_len > 0 && word_len < MAX_WORD_LEN)
            {
                ++word_lengths[word_len];
                word_len = 0;
                state = OUT;
            }
            
            // Find max frequency for vertical height
            for (int i = 1; i < MAX_WORD_LEN; ++i)
            {
                if (word_lengths[i] > max)
                    max = word_lengths[i];
            }

            printf("\nWord Length Histogram (Vertical):\n\n");

            // Print histogram top-down
            for (int row = max; row > 0; --row)
            {
                for (int col = 1; col < MAX_WORD_LEN; ++col)
                {
                    if (word_lengths[col] >= row)
                        printf(" * ");
                    else
                        printf("   ");
                }
                putchar('\n');
            }

            // Print bottom border
            for (int col = 1; col < MAX_WORD_LEN; ++col)
                printf("---");

            putchar('\n');

            // Print length labels
            for (int col = 1; col < MAX_WORD_LEN; ++col)
                printf("%2d ", col);

            putchar('\n');

            // Zero out vars
            word_len = 0;
            state = OUT;
            max = 0;

            for (int i = 0; i < MAX_WORD_LEN; ++i)
                word_lengths[i] = 0;

            printf("\nType text. Press Ctrl+D (EOF) to see vertical word length histogram.\n");
        }
        else
        {
            if (state == OUT)
            {
                state = IN;
                word_len = 1;
            }
            else
            {
                ++word_len;
            }
        }
    }

    return 0;
}
