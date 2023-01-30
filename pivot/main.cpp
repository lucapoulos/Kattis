#include <bits/stdc++.h>
using namespace std;

int main() {
    long maxLeft = -1, minRight = 999999999999999999;
    int n, count = 0;
    cin >> n;
    unordered_map<int,long> maxL;
    unordered_map<int,long> minR;
    vector<long> vl (n);

    for (int i = 0; i < n; ++i) {// go through left
        cin >> vl[i];
        if (vl[i] > maxLeft) {
            maxLeft = vl[i];
        }
        maxL[i] = maxLeft;
    }

    for (int i = n - 1; i > 0; --i) {
        if (vl[i] < minRight) {
            minRight = vl[i];
        }
        minR[i] = minRight;
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0 && vl[i] < minR[i+1] || (i == n-1 && vl[i] > maxL[i-1])) {
            count++;
            continue;
        }
        if (vl[i] < minR[i+1] && vl[i] > maxL[i-1]) count++;
    }
    cout << count << '\n';

    return 0;
}
