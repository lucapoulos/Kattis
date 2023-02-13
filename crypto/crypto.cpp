#include <iostream>
#include <cmath>
using namespace std;

int solve(int n, int b){
    int count = 0;

    while(true) {
        int remainder = n % b;
        n /= b;
        if (remainder == 0)
            count++;
        else 
            break;
    }
    return count;
}
int main(){
    int n, b = 2, maxbase = 0, max = 0;
    cin >> n;
    while (b <= n) {

        int val = solve(n,b);
        if (val > max) {
            max = val;
            maxbase = b;
        }
        b++;
    }
    cout << maxbase << endl;
    return 0;
}
