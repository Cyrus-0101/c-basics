#include "stdio.h"

/**
 *
 * @file word_count
 *
 * @brief A simple wrapper around wc. A simple word counter
 * Count lines, words, and characters in input
 *
 */

#define IN 1  /** inside a word */
#define OUT 0 /** outside a word */

int main()
{
    int c, new_line, new_word, new_char, state;

    state = OUT;

    new_line = new_word = new_char = 0;

    printf("Type characters. Press Enter to see the count. Ctrl+D to quit.\n");

    while ((c = getchar()) != EOF)
    {
        ++new_char;

        if (c == '\n')
        {
            ++new_line;

            printf("Number of lines: %d\tNumber of words: %d\tNumber of chars: %d\n",
                   new_line, new_word, new_char - 1); // -1 to exclude '\n' from char count

            // Reset for next line
            new_word = 0;
            new_char = 0;
            state = OUT;

            printf("\nType characters. Press Enter to see the count. Ctrl+D to quit.\n");
        }
        else if (c == ' ' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++new_word;
        }
    }

    return 0;
}