#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int n;
        cin >> n;
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            long long candies;
            cin >> candies;
            sum += candies % n; // mod n before adding candies
        }
        if (sum % n == 0) cout << "YES\n";
        else cout << "NO\n";
        t--;
    }
    return 0;
}
/*

2

5
5
2
7
3
8

6
7
11
2
7
3
4
 */
//YES
//      NO
