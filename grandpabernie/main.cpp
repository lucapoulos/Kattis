#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    int n, q;
    unordered_map<string,vector<int>> trips;
    unordered_set<string> sorted;
    while(cin >> n) {
        string cit;
        int yea;
        for(int i = 0; i < n; ++i) {
            cin >> cit >> yea;
            sorted.insert(cit);
            trips[cit].emplace_back(yea);
        }
        cin >> q;
        for (auto s: sorted){// AVOIDING DOUBLE SORTING
            sort(trips[s].begin(), trips[s].end());
        }
        for (int i = 0; i < q; ++i) {
            cin >> cit >> yea; // 1 based index = yea
            cout << trips[cit][yea-1] << '\n';
        }
    }
    return 0;
}
