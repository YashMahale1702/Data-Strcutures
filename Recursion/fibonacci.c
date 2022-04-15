#include <stdio.h>

int fib(int n) {

  if (n <= 1)
    return n;
  else
    return fib(n - 2) + fib(n - 1);
}

int f[10] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
};

int fib2(int n) {

  if (n <= 1) {
    f[n] = n;
    return n;
  } else {
    if (f[n - 1] == -1)
      f[n - 1] = fib2(n - 1);
    if (f[n - 2] == -1)
      f[n - 2] = fib2(n - 2);
    return f[n - 2] + f[n - 1];
  }
}

int main() {
  printf("%d \n", fib(6));
  printf("%d ", fib2(6));
}