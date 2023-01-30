#include <iostream>
#include <vector>
using namespace std;
double average(vector<double> &vi) {
    double sum = 0;
    for (int i = 0; i < vi.size(); ++i) {
        sum += vi[i];
    }
    return sum /= vi.size();
}
int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int ncs, ne, count = 0;
        cin >> ncs >> ne;
        vector<double> cs;
        vector<double> e;
        double csavg = 0.0, eavg = 0.0;
        double iq;
        for (int i = 0; i < ncs + ne; ++i) {
            cin >> iq;
            if (i >= ncs) {
                e.push_back(iq);
                eavg += iq;
            } else {
                cs.push_back(iq);
                csavg += iq;
            }
        }
        eavg /= ne;
        csavg /= ncs;

        for(int i = 0; i < ncs; ++i) {
            int temp = cs[i];
            cs.erase(cs.begin() + i);
            e.push_back(temp);
            double ncsavg = average(cs);
            double neavg = average(e);
            if (eavg < average(e) && csavg < average(cs)) {
                count++;
            }
            cs.push_back(temp);
            e.pop_back();
        }
        cout << count << '\n';
        t--;
    }
    return 0;
}
