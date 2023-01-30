#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char a[m+1]; // Plaintext
    a[m] = '\0';
    string an, b; // Last n chars of plaintext, Ciphertext
    cin >> an;
    cin >> b;
    for (int i = 0; i < n; ++i) { // adding an
        a[m - i -1] = an[n - i - 1];
    }
    for (int i = m - 1; i >= n; --i) {
        int temp = (26 - (a[i] - 'a') + (b[i] - 'a')) % 26;
        a[i - n] = temp + 'a';
    }

    cout << string(a) << '\n';
    return 0;
}

// pirpumsemoystoal
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
// a b c d e f g h i j k   l m   n  o p  q  r  s  t   u  v  w  x  y z

// for given decrypted char, add 26-key+char

// m a r y w a s n o s  y  a  g  a  i  n
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16

// key[n+i] = a[i]

// 16 - 5 = 11
// l(13) = n(13) + y(24) -> a[11] = y
// a(0) = i(8) + s(18) -> a[10] = s
// o(14) = a(0) + o(14) -> a[9] = o
// t(19) = g(6) + n(13) -> a[8] = n
// s(10) = a(0) + s(10) -> a[7] = s
// y(24) = a[11]=y(24) + a(0) -> a[6] = a
// o(14) = a[10]=s(18) + w(22) -> a[5] = w