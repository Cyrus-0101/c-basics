#include "stdio.h"

/**
 *
 * @file char_length_vertical_histogram.c
 *
 * @brief A program to count the number of occurences
 * of each prinatble ASCII character. We normalize
 * the letters (to lower case).
 *
 */

//  Track Printable ASCII Chars from 32 to tilde (126)
#define ASCII_START 32
// Last printable ASCII character
#define ASCII_END 126
// Efficient Space usage, bu ignoring unprintable chars
#define ASCII_RANGE (ASCII_END - ASCII_START + 1)

int main()
{
    int c;
    int ascii_freq[ASCII_RANGE] = {0}; ///< Frequency of each printable ASCII char
    int max = 0; // Tallest column 

    printf("Type any sequence of characters to count the number. Press Enter to see the count. Ctrl+D to quit.\n");

    while ((c = getchar()) != EOF)
    {
        // Convert uppercase letters to lowercase manually
        if (c >= 'A' && c <= 'Z')
        {
            c = c + ('a' - 'A'); // Normalize to lowercase
        }

        if (c == '\n')
        {
            // Find the max frequency
            max = 0;
            for (int i = 0; i < ASCII_RANGE; ++i)
            {
                if (ascii_freq[i] > max)
                    max = ascii_freq[i];
            }

            // Skip if no characters were typed
            if (max == 0)
            {
                printf("No printable characters typed.\n");
                printf("Type characters. Press Enter to see vertical histogram. Ctrl+D to quit.\n");
                continue;
            }

            // Print histogram top-down
            printf("\nVertical Histogram of Printable Characters:\n\n");

            for (int row = max; row > 0; --row)
            {
                for (int col = 0; col < ASCII_RANGE; ++col)
                {
                    if (ascii_freq[col] > 0)
                    {
                        if (ascii_freq[col] >= row)
                            printf(" * ");
                        else
                            printf("   ");
                    }
                }
                putchar('\n');
            }

            // Print separator
            for (int col = 0; col < ASCII_RANGE; ++col)
            {
                if (ascii_freq[col] > 0)
                    printf("---");
            }
            putchar('\n');

            // Print character labels
            for (int col = 0; col < ASCII_RANGE; ++col)
            {
                if (ascii_freq[col] > 0)
                    printf(" %c ", col + ASCII_START);
            }
            putchar('\n');

            // Reset state
            for (int i = 0; i < ASCII_RANGE; ++i)
                ascii_freq[i] = 0;

            printf("\nType characters. Press Enter to see vertical histogram. Ctrl+D to quit.\n");
        }
        else if (c >= ASCII_START && c <= ASCII_END)
        {
            ++ascii_freq[c - ASCII_START];
        }
    }

    return 0;
}