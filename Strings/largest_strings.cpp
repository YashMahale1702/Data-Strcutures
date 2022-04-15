#include <bits/stdc++.h>

using namespace std;

int main() {

  char sentence[1000], largest[1000];
  int largest_len, n;

  cin >> n;
  cin.get(); // to read the garbage /n char

  while (n--) {
    cin.getline(sentence, 1000);
    if (strlen(sentence) > largest_len) {
      largest_len = strlen(sentence);
      strcpy(largest, sentence);
    }
  }
}