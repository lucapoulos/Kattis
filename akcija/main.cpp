#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        arr[i] = b;
        p += b;
    }
    sort(arr, arr+n, greater<>());
    for (int i = 2; i < n; i +=3) {
        p -= arr[i];
    }
    cout << p;

    return 0;
}
