#include "stdio.h"

/**
 *
 * @file exponentiation.c
 *
 * @brief We are writing a custom function to find the
 * power(m, n), where m is raised to a positive integer n
 */

#define CONST 10

int power(int base, int n) {
  int i, power;

  power = 1;

  for (i = 1; i <= n; ++i) {
    power = power * base;
  }

  return power;
}

int main() {
  int base, iterations;

  printf("Enter the base number: ");
  scanf("%d", &base);

  printf("Enter the number of iterations (exponents from 0 to n-1): ");
  scanf("%d", &iterations);

  printf("\nPower table for base %d up to %d iterations:\n", base, iterations);
  printf("%3s\tbase^n\n", "n");

  for (int i = 0; i < iterations; ++i) {
    printf("%3d\t%3d\n", i, power(base, i));
  }

  return 0;
}