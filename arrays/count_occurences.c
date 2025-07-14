#include "stdio.h"

/**
 *
 * @file count_occurence.c
 *
 * @brief A program to count the number of occurences
 * of each digit, white space, tabs and blanks.
 * 12 categories of input
 *
 */

#define TOTAL_NUMS 10

int main()
{
    int c, i, nwhite, ntab, nother;
    int ndigit[TOTAL_NUMS];

    nwhite = ntab = nother = 0;

    for (i = 0; i < TOTAL_NUMS; ++i)
        ndigit[i] = 0;

    printf("Type any sequence of characters to count the number. Press Enter to see the count. Ctrl+D to quit.\n");

    while ((c = getchar()) != EOF)
    {
        // Numbers are stored in ASCII characters
        if (c >= '0' && c <= '9')
        {
            // We subtract to find the value for instance
            // '0' = 48, '1' = 49, ... so if  c = '3'
            // It becomes 51 - 48 = 3
            ++ndigit[c - '0'];
        }
        else if (c == ' ')
        {
            ++nwhite;
        }
        else if (c == '\t')
        {
            ++ntab;
        }
        else if (c == '\n')
        {
            printf("Digit frequencies (histogram):\n");
            for (i = 0; i < TOTAL_NUMS; ++i)
            {
                printf("%d: ", i);
                for (int j = 0; j < ndigit[i]; ++j)
                {
                    putchar('*');
                }
                putchar('\n');
            }

            printf("White spaces = %d, Tabs = %d, Other = %d\n", nwhite, ntab, nother);
            printf("Type any sequence of characters. Press Enter to see the count. Ctrl+D to quit.\n");

            for (i = 0; i < TOTAL_NUMS; ++i)
                ndigit[i] = 0;

            nwhite = ntab = nother = 0;
        }
        else
        {
            ++nother;
        }
    }

    return 0;
}