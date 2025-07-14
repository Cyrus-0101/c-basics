#include <stdio.h>
#include <stdlib.h>

/**
 *
 * @file main_menu.c
 *
 * @brief This file ensures a user can interact with all the C projects
 * built from The C Programming Language Handbook, 2nd Edition.
 */

void show_menu()
{
    printf("\n🔥 Mini Tool Suite 🔥\n");
    printf("-----------STRING OPS----------------\n");
    printf("1. Celsius to Fahrenheit Table\n");
    printf("2. Character Count\n");
    printf("3. Word Count\n");
    printf("4. Word Per Line\n");
    printf("\n----------ARRAY OPS----------------\n");
    printf("5. Count Frequencies (Histogram)\n");
    printf("6. Word Length (Vertical Histogram)\n");
    printf("\n-----------POINTER OPS-------------\n");
    printf("7. Function Pointers Demo\n");

    printf("\n-----------------------------------\n");
    printf("0. Exit\n");
    printf("Choose a program to run: ");
}

int main()
{
    int choice;

    while (1)
    {
        show_menu();
        scanf("%d", &choice);
        getchar(); // consume newline after number

        switch (choice)
        {
        case 1:
            system("./outputs/cel-to-fahr-converter");
            break;
        case 2:
            system("./outputs/char_count");
            break;
        case 3:
            system("./outputs/word_count");
            break;
        case 4:
            system("./outputs/word_per_line");
            break;
        case 5:
            system("./outputs/count_occurences");
            break;
        case 6:
            system("./outputs/word_length_vertical_histogram");
            break;
        case 7:
            system("./outputs/function_pointers");
            break;
        case 0:
            printf("Exiting shell...\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }

        printf("\n--- Press Enter to return to the menu ---\n");
        getchar(); // pause until user presses Enter
    }

    return 0;
}
