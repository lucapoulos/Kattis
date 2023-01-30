#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;

    while (cin >> num) {
        int sum = 1;
        int bot = (int)sqrt(num) + 1;
        for (int i = 2; i < bot; ++i) {
            if (num % i == 0) {
                int num2 = num /i;
                sum += i;
                if (i != num2) sum+=num2;
            }
        }

        if (sum == num) cout << num << " perfect\n";
        else if (abs(num - sum) < 3) cout << num << " almost perfect\n";
        else cout << num << " not perfect\n";
    }
    return 0;
}

