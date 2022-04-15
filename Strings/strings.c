#include <stdio.h>
#include <stdlib.h>

int lengthOfString(char s[]) {
  int i;
  for (i = 0; s[i] != '\0'; i++)
    ;
  return i;
}

void upperToLower(char s[]) {
  int i;
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] >= 65 && s[i] <= 90)
      s[i] += 32;
  }
}

void toggleCase(char s[]) {
  int i;
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] >= 65 && s[i] <= 90)
      s[i] += 32;
    else if (s[i] >= 97 && s[i] <= 122)
      s[i] -= 32;
  }
}

void noOfWords(char s[]) {
  int i, count = 1;
  char prev;
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == ' ' && prev != ' ' && s[i + 1] != '\0') {
      count++;
    }
    prev = s[i];
  }
  printf("Count is %d \n", count);
}

void compareStrings(char s[], char s1[]) {
  int i, j;

  for (i = 0, j = 0; s[i] != '\0' && s1[j] != '\0'; i++, j++) {
    if (s[i] != s1[j]) {
      printf("Not Equal\n");
      return;
    }
  }
  printf("Equal\n");
}

void palindrome(char s[]) {
  int i, j;
  for (j = 0; s[j] != '\0'; j++)
    ;
  j--;
  for (i = 0; i < j; i++, j--) {
    if (s[i] != s[j]) {
      printf("Not palindrome.\n");
      return;
    }
  }
  printf("Palindrome.\n");
  return;
}

void anagram(char s[], char s1[]) {
  int h[26] = {0};
  int i;

  // Create a hash table for first string
  for (i = 0; s[i] != '\0'; i++) {
    h[s[i] - 97] += 1;
  }

  // Check in the hash table
  for (i = 0; s1[i] != '\0'; i++) {
    h[s1[i] - 97] -= 1;
    if (h[s1[i] - 97] == -1) {
      printf("Not anagram.\n");
      return;
    }
  }

  printf("Anagram.\n");
  return;
}

int main() {
  char s[] = "racecar";
  char s1[] = "Yash A";

  //* Lenght
  // printf("Length is %d\n", lengthOfString(s));

  //* Upper to lower
  //   upperToLower(s);

  //* Toggle case
  //   toggleCase(s);

  //* Count
  //   noOfWords(s);

  //* Compare Strings
  // compareStrings(s, s1);

  //* Palindrome
  // palindrome(s);

  //* Anagram
  anagram("medicak", "decimal");

  printf("%s\n", s);
}