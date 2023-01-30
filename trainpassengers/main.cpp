#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, n, onTrain = 0;
    cin >> c >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, cc;
        cin >> a >> b >> cc;
        onTrain += b - a;
        if ((i == 0 && a != 0) || (i == n-1 && (b != 0 || cc != 0 || onTrain != 0)))
            goto no;
        if(onTrain > c || onTrain < 0 || (cc > 0 && onTrain < c))
            goto no;
    }
    cout << "possible\n";
    return 0;
    no: cout << "impossible\n";
    return 0;
}
