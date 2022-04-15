#include <bits/stdc++.h>

using namespace std;

void oddEven(int n) {

  int result = n & 1;
  cout << (result == 0 ? "Even" : "Odd") << endl;
}

void get0thBit(int n) {

  int result = n & 1;
  cout << (result == 0 ? 0 : 1) << endl;
}

void getIthBit(int n, int i) {

  int mask = 1 << i;
  int result = n & mask;
  cout << (result == 0 ? 0 : 1) << endl;
}

void clearIthBit(int n, int i) {
  int mask = 1 << i;
  int result = n & ~mask;

  cout << result << endl;
}

void setIthBit(int n, int i) {
  int mask = 1 << i;
  int result = n | mask;

  cout << result << endl;
}

void updateIthBit(int n, int i, int val) {
  int mask = 1 << i;

  // clear the ith bit
  int result = n & ~mask;

  // update the bit
  result = result | mask;

  cout << result << endl;
}

void clearLastIthBits(int n, int i) {
  int mask = (~0) << i;
  int result = n & mask;

  cout << result << endl;
}

void clearbitsRange(int n, int i, int j) {
  int a = (~0) << (j + 1);
  int b = (1 << i) - 1;

  int mask = a | b;
  int result = n & mask;

  cout << result << endl;
}

int main() {

  int n, i, j;
  cin >> n;
  cin >> i;
  cin >> j;

  //   oddEven(n);
  //   clearIthBit(n, i);
  //   setIthBit(n, i);
  //   updateIthBit(n, i, 1);
  //   clearLastIthBits(n, i);
  clearbitsRange(n, i, j);
}