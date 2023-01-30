#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    vector<char> sols;
    int sum = 0;
    while (cin >> s) {
        unordered_map<char,int> common;
        for (int i = 0; i < 3; ++i) {
            unordered_set<char> dup;
            for (char c: s) {
                if (i > 0) {
                    if (common[c] >= i && dup.count(c) == 0) {
                        common[c]++;
                        dup.insert(c);
                        if (common[c] == 3)
                            sols.push_back(c);
                    }
                }else {
                    common[c] = 1;
                }
            }
            if (i < 2)
                cin >> s;
        }
    }
    for (char c: sols) {
        if (c > 96)
            sum += c - '`'; // get values to represent 1-26
        else
            sum += c - '@' + 26; // get values to represent 27-52
    }
    cout << sum << '\n';
    return 0;
}

int part1() {
    string s;
    vector<char> sols;
    int sum = 0;
    while (cin >> s) {
        unordered_set<char> usc;
        unordered_set<char> dup;
        for (int i = 0; i < s.length(); ++i) {
            if (i >= s.length() / 2) { // second
                if (usc.count(s[i]) == 1 && dup.count(s[i]) == 0) {
                    sols.push_back(s[i]);
                    dup.insert(s[i]);
                }
            } else {
                usc.insert(s[i]);
            }
        }
    }
    for (char c: sols) {
        if (c > 96)
            sum += c - '`';
        else
            sum += c - '@' + 26;
    }
    cout << sum << '\n';
    return 0;
}
