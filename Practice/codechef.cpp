// #include <iostream>
// #include <string.h>

// using namespace std;

// int main() {
//   // your code goes here
//   int t, n, k, count, i, j;
//   string s;

//   cin >> t;
//   while (t--) {
//     cin >> n >> k >> s;
//     count = 0;
//     for (i = 0, j = s.size() - 1; i < j; i++, j--) {
//       if (s[i] != s[j])
//         count++;
//     }

//     if (count <= k)
//       cout << count << "YES\n";
//     else
//       cout << count << "NO\n";
//   }

//   return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//   // your code goes here
//   int t, i, j, n;
//   cin >> t;

//   while (t--) {
//     string str;
//     int flag = 0;
//     int hash[26] = {0};
//     cin >> str;
//     n = str.size();

//     if (n % 2 == 0) {
//       for (i = 0, j = (n / 2); i < (n / 2); i++, j++) {
//         hash[str[i] - 97]++;
//         hash[str[j] - 97]--;
//       }

//     } else {

//       for (i = 0, j = ((n / 2) + 1); i < (n / 2); i++, j++) {
//         hash[str[i] - 97]++;
//         hash[str[j] - 97]--;
//       }
//     }

//     for (i = 0; i < 26; i++) {
//       cout << hash[i] << " ";
//     }
//     // if(flag == 0){
//     //     cout<<"YES\n";
//     // }
//     cout << "\n";
//   }

//   return 0;
// }

/*
class Box{
    private:
        int l,b,h;

    public:
        // default
        Box(){
            this->l = this->h = this->b = 0;
        }
        Box(int l, int b,int h){
            this->l = l;
            this->b = b;
            this->h = h;
        }
        Box(Box& box){
            this->h = box.h;
            this->b = box.b;
            this->l = box.l;
        }

        int getLength(){
            return this->l;
        }
        int getBreadth(){
            return this->b;
        }
        int getHeight(){
            return this->h;
        }
        long long CalculateVolume(){
            return this->l * this->b * this->h;
        }

};


*/

// #include <iostream>
// #include <string>

// using namespace std;

// int main() {
//   // your code goes here
//   unsigned int t, n, k, count, i, j;
//   string s;

//   cin >> t;
//   while (t--) {
//     int flag = 0;
//     cin >> n >> k;
//     cin >> s;
//     count = 0;

//     // even
//     if (n % 2 == 0) {
//       for (i = 0, j = n - 1; i < j; i++, j--) {
//         cout << i << " " << j;
//         if (s[i] != s[j])
//           count++;
//         else
//           count += 2;

//         if (count == k) {
//           cout << "YES\n";
//           flag = 1;
//           break;
//         }
//       }

//       if (flag == 0) {
//         cout << "NO\n";
//       }
//     }
//     if (n % 2 != 0) {
//       for (i = 0, j = n - 1; i <= j; i++, j--) {
//         cout << i << " " << j;

//         if (s[i] != s[j])
//           count++;
//         else
//           count += 2;

//         if (i == j)
//           count++;

//         if (count == k) {
//           cout << "YES\n";
//           flag = 1;
//           break;
//         }
//       }

//       if (flag == 0) {
//         cout << "NO\n";
//       }
//     }

//     // if(count == k) cout<<"YES\n";
//     // else cout<<"NO\n";
//   }

//   return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {
//   // your code goes here
//   long long t;
//   cin >> t;

//   while (t--) {
//     unsigned long long n, count = 0, temp, i;
//     cin >> n;

//     for (i = 5; i <= n; i += 5) {
//       temp = i;
//       while (temp >= 5) {
//         if (temp % 5 == 0)
//           count++;
//         temp = temp / 5;
//       }
//     }
//     cout << count << "\n";
//   }
//   return 0;
// }

#include <iostream>
using namespace std;

int main() {
  long int t;
  cin >> t;

  while (t--) {
    long long int x[100000001] = {0}, y[100000001] = {0}, n, temp1, temp2,
                  count = 0, i;
    cin >> n;

    while (n--) {
      cin >> temp1 >> temp2;
      x[temp1]++;
      y[temp2]++;
    }

    for (i = 0; i <= 100000000; i++) {
      if (x[i] >= 1)
        count++;
      if (y[i] >= 1)
        count++;
    }

    cout << count << endl;
  }

  return 0;
}

/*
#include <iostream>
#include <string>

using namespace std;

int main() {
  // your code goes here
  unsigned int t, n, k, count, i, j;
  string s;

  cin >> t;
  while (t--) {
    int flag = 0;
    cin >> n >> k;
    cin >> s;
    count = 0;

    for (i = 0, j = n - 1; i < j; i++, j--) {
        if (s[i] != s[j])
          k--;
    }

    if (k >= 0 && k % 2 == 0) {
      cout << "YES" << endl;
    } else if (k >= 0 && n % 2 == 1) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }

  return 0;
}
*/