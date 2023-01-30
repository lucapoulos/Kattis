#include <bits/stdc++.h>
using namespace std;

struct Child {
public:
    vector<int> toys;
};
struct Categories{
public:
    int numToysLeft;
    vector<int> toys;
};

bool compare(Child c1, Child c2){ return c1.toys.size() < c2.toys.size(); }

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    //unordered_map<int,int> children; // key is child, value is toy they took
    vector<Child>v1; // children vectors

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k; // toys
        Child c;
        for (int j = 0; j < k; ++j) {
            int t;
            cin >> t;
            c.toys.emplace_back(t);
        }
        v1.emplace_back(c);
    }
    // sort children
    sort(v1.begin(), v1.end(), compare);
    vector<Categories> v2;
    for (int i = 0; i < p; ++i) {
        int l, r;
        cin >> l;
        vector<int> toys;
        for (int j = 0; j < l; ++j) {
            int t;
            cin >> t;
            toys.emplace_back(t);
        }
        cin >> r;
        Categories c;
        c.toys = toys;
        c.numToysLeft = r;
        v2.emplace_back(c);
    }
    for (int i = 0; i < m; ++i) {

    }

    return 0;
}


/* sort children from least toys to most
 * starting at 1, n is num children     m is toys   p is toy categories
 * k is num of toys a given child would play with
 * on line p, first number is category and l is # toys in category

4 3 2
2 1 2
1 2
1 3
1 3
2 1 2 1
1 2 3 2   -> output = 3

4 3 2
3 1 2 3
2 2 3
1 1
 */

