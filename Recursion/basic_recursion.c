#include <stdio.h>

void tail(int n) {
  if (n > 0) {
    printf("%d ", n);
    tail(n - 1);
  }
}
void head(int n) {
  if (n > 0) {
    head(n - 1);
    printf("%d ", n);
  }
}

int sumUsingStatic(int n) {
  static int x = 0;
  if (n == 0)
    return 0;
  else {
    x++;
    return x + sumUsingStatic(n - 1);
  }
}

int sumOfNumbers(int n) {
  if (n == 0)
    return 0;
  return n + sumOfNumbers(n - 1);
}

int factorial(int n) {
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}

int powerFun(int m, int n) {
  if (n == 0)
    return 1;
  else
    return powerFun(m, n - 1) * m;
}

int main() {

  //* Tail
  tail(5);

  //* Head
  head(5);

  //* using static variables
  //   printf("Sum of Number using static : %d\n", sumUsingStatic(5));

  //* Sum of numbers
  //   printf("Sum of Number : %d\n", sumOfNumbers(5));

  // * Factorial
  // printf("Factorial is %d", factorial(10));

  //* Power Function
  // printf("Power : %d", powerFun(2, 3));
}