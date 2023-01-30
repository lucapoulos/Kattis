#include <bits/stdc++.h>
using namespace std;

void printword(vector<string> &strings, vector<vector<int>> &indexes, int first) { // pass by reference
    cout << strings[first];
    for (auto i: indexes[first]) {
        printword(strings, indexes, i);
    }
}
int main() {
    int n, first = 0;
    cin >> n;
    vector<string> strings(n);
    vector<vector<int>> indexes;

    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }
    indexes.assign(n, vector<int>()); // fill index vector
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b; // append b to a
        indexes[a-1].emplace_back(b-1); // a will be reused, there will be a queue of words to print
        first = a - 1; // keep track of string that goes first
    }
    printword(strings, indexes, first);
    cout << '\n';
    return 0;
}
