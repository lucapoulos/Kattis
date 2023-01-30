#include <bits/stdc++.h>
using namespace std;

int main() {
    char arr[4] = {'-', ',', '-', '\n'};
    string line;
    int count = 0;
    while (!cin.eof()) {
        vector<int> pairs;
        for (char i : arr) {
            getline(cin, line, i);
            int temp = stoi(line);
            pairs.push_back(temp);
        }
        unordered_set<int> index;
        for (int i = pairs[0]; i <= pairs[1]; ++i)
            index.insert(i);
        for (int i = pairs[2]; i <= pairs[3]; ++i)
            if (index.count(i) == 1) {
                count++;
                break;
            }
    }
    cout << count << '\n';
    return 0;
}
int part1() {
    char arr[4] = {'-', ',', '-', '\n'};
    string line;
    int count = 0;
    while (!cin.eof()) {
        vector<int> pairs;
        for (int i = 0; i < 4; ++i) {
            getline(cin, line, arr[i]);
            int temp = stoi(line);
            pairs.push_back(temp);
        } // 3 7 2 8
        if ((pairs[0] >= pairs[2] && pairs[1] <= pairs[3]) || (pairs[0] <= pairs[2] && pairs[1] >= pairs[3]))
            count++;
    }
    cout << count << '\n';
    return 0;
}