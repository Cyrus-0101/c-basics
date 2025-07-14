#include "stdio.h"
#include "unistd.h"

/**
 *
 * @file char_count.c
 *
 * @brief In this we count characters in from user input using getchar()
 * Its Big 'O' is Space Complexity = O(1), Time complexity: O(n).
 * In the loop each character is processed in constant time O(1).
 * Accomplish exercises 1-8 to 1-9 The C Programming Language.
 * We use getchar() and read() to compare
 */

int main()
{
    // long nc;

    // nc = 0;
    // while (getchar() != EOF)
    // {
    //     ++nc;
    // }

    // printf("%ld\n", nc);

    // double nc;

    // for (nc = 0; getchar() != EOF; ++nc)
    //     ;
    // printf("%.0f\n", nc);

    // return 0;

    int c;
    int count = 0;
    int tab = 0;
    int blank = 0;
    int in_blank = 0;

    printf("Type characters. Press Enter to see the count. Ctrl+D to quit.\n");

    while ((c = getchar()) != EOF)
    {
        count++;

        if (c == ' ')
        {
            blank++;
            if (!in_blank)
            {
                putchar(' '); // print first space only
                in_blank = 1;
            }
        }
        else if (c == '\t')
        {
            tab++;
        }
        else if (c == '\n')
        {
            printf("Number of chars: %d\n", count - 1);
            printf("Number of blanks: %d\n", blank);
            printf("Number of tabs: %d\n", tab);

            count = 0; // reset count for next line
            tab = 0;
            blank = 0;
            printf("Type characters. Press Enter to see the count. Ctrl+D to quit.\n");
        }
    }

    return 0;

    // char buffer[1024]; // Input buffer
    // ssize_t n;         // Number of bytes read
    // char *ptr;         // Pointer for walking buffer
    // int count = 0;

    // printf("Type something and press Enter. Ctrl+D to quit.\n");

    // // Read from stdin (file descriptor 0)
    // while ((n = read(0, buffer, sizeof(buffer))) > 0)
    // {
    //     ptr = buffer;

    //     // Walk through buffer using pointer arithmetic
    //     while (ptr < buffer + n)
    //     {
    //         if (*ptr == '\n')
    //         {
    //             printf("number of chars: %d\n", count); // include newline
    //             count = 0;
    //         }
    //         else
    //         {
    //             count++;
    //         }
    //         ptr++;
    //     }
    // }

    // return 0;
}