#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
// NOT SOLVED

int main() {
    double m, n, r, ax, ay, bx, by;
    double d = 0.0; // distance
    double d2 = 0.0;
    cin >> m >> n >> r >> ax >> ay >> bx >> by;
    d += abs(ay - by);
    double ringangle = M_PI / m;
    double ringlength = r / n;
    double theta = ringangle * abs(ax - bx);
    d += ringlength * theta;
    cout << fixed << setprecision(14);
    cout << d << endl;
    return 0;
}
