#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    while (n != 0 && m != 0) {
        vector<pair<int, int>> phones;
        int start, end;
        for (int i = 0; i < n; ++i) {
            cin >> start >> end >> start >> end;
            phones.emplace_back(start, start + end);
        }
        for (int i = 0; i < m; ++i) {
            int count = 0;
            int opStart, opEnd;
            cin >> opStart >> opEnd;
            opEnd += opStart;
            for (auto & phone : phones) {
                start = get<0>(phone);
                end = get<1>(phone);
                if (start < opEnd && opStart < end) count++;
            }
            cout << count << endl;
        }
        cin >> n >> m;
    }
    return 0;
}
