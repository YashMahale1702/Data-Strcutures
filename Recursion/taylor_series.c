#include <stdio.h>

double taylorSeries(int x, int n) {
  static double p = 1, f = 1;
  double result;

  if (n == 0)
    return 1;
  else {
    result = taylorSeries(x, n - 1);
    p = p * x;
    f = f * n;
    return result + (p / f);
  }
}

int main() { printf("Taylor series : %lf", taylorSeries(4, 20)); }