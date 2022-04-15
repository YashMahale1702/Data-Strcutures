#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

  char *s;
  s = malloc(1024 * sizeof(char));
  scanf("%[^\n]", s);
  s = realloc(s, strlen(s) + 1);
  // Write your logic to print the tokens of the sentence here.
  int length = strlen(s);
  int i = 0, j = 0;
  while (j <= 8) {
    while (s[i] != ' ') {
      printf("%c", s[i]);
      i++;
    }
    i++;
    printf("\n");
    j = i;
  }
  return 0;
}