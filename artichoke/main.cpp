#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c, d, p, n, price, front, back, max = 0;
    cin >> p >> a >> b >> c >> d >> n;
    for (int k = 1; k <= n; ++k) {
        price = p * (sin(a*k + b) + cos(c*k + d) + 2);
        if (k == 1 || back < price) {
            front = price;
            back = price;
        } else if (front < price) {
            front = price;
        }
        if (price < back) {
            front = price;
            max = (max < (back - price))?back-price:max;
        }
    }
    cout << fixed << setprecision(9);
    cout << max << endl;
    return 0;
}
