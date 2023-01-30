#include <bits/stdc++.h>
using namespace std;

int  main() {
    int n, b, h, w, p, a;
    cin >> n >> b >> h >> w;
    int min = 500001;
    for (int i = 0; i < h; ++i) {
        int cost = 0;
        cin >> p;
        for (int j = 0; j < w; ++j) {
            cin >> a;
            if (a > 0 && n <= a) {
                cost = n * p;
                if (cost < min) min = cost;
            }
        }

    }

    if (min > b) cout << "stay home" << endl;
    else cout << min << endl;

    return 0;
}