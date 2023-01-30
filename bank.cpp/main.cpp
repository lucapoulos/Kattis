#include <bits/stdc++.h>
using namespace std;
class person {
public:
    int cash, time;

    person(int c, int t) {
        cash = c;
        time = t;
    }
};
bool compare(person a, person b) {
    if (a.time == b.time) {
        return a.cash < b.cash;
    }
    return a.time > b.time;
}
int main() {
    priority_queue<person, vector<person>, decltype(&compare)> pq(compare);
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        int cash, time;
        cin >> cash >> time;
        pq.emplace(cash, time);
    }
    int total = 0;
    int i = 0;
    while (t >= i && !pq.empty()) {
        int oldTime = pq.top().time;
        if (oldTime >= i)
            total+= pq.top().cash;
        while(pq.top().time == oldTime && !pq.empty())
            pq.pop();
        i++;
    }
    cout << total << '\n';
    return 0;
}
