#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
  int arr[6][6] = {{-9, -9, -9, 1, 1, 1}, {0, -9, 0, 4, 3, 2},
                   {-9, -9, -9, 1, 2, 3}, {0, 0, 8, 6, 6, 0},
                   {0, 0, 0, -2, 0, 0},   {0, 0, 1, 2, 4, 0}};
  int k, l, sum = 0;
  int i, j, arr2[4][4];
  int max = INT_MIN;

  for (i = 0; i <= 3; i++) {
    for (j = 0; j <= 3; j++) {

      for (k = i; k < 3 + i; k++) {
        for (l = j; l < 3 + j; l++) {

          // slip 2 values
          if (k == i + 1 && (l == j + 0 || l == j + 2)) {
            continue;
          } else {
            sum += arr[k][l];
            // printf("%d %d\n", k, l);
          }
        }
      }
      printf("%d %d ", i, j);
      printf("Sum %d\n", sum);
      arr2[i][j] = sum;
      sum = 0;
    }
  }

  for (i = 0; i <= 3; i++) {
    for (j = 0; j <= 3; j++) {
      if (arr2[i][j] > max) {
        max = arr2[i][j];
      }
    }
  }
  printf("Max is %d", max);

  //   for (k = 0; k < 3; k++) {
  //     for (l = 0; l < 3; l++) {

  //       // slip 2 values
  //       if (k == 1 && (l == 0 || l == 2)) {
  //         continue;
  //       } else {
  //         sum += arr[k][l];
  //         printf("%d %d\n", k, l);
  //       }
  //     }
  //   }
  //   printf("Sum %d", sum);
}