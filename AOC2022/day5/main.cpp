#include <iostream>
#include <deque>
#include <vector>
#include <unordered_set>
#include<sstream>
#include <stack>
using namespace std;
// ' ' = 32, '[' = 91, ']' = 93
// 1 + 4
// strtok ]
// i = 2, increment +4
//move 1 from 2 to 1
//move 3 from 1 to 3
//move 2 from 2 to 1
//move 1 from 1 to 2
// push back from the

int main() {
    string line;
    vector<deque<char>> stackies;
    stackies.assign(9, deque<char>());
    while(true) {
        getline(cin, line);
        int j = 0;
        for (int i = 1; i < line.size(); i += 4) {
            char c = line[i];
            if (c == '1')
                goto out;
            if (c < 91 && c > 32) {
                stackies[j].push_back(c);
            }
            j++;
        }
    }
    out: getline(cin, line);
    while (getline(cin, line)) {
        stringstream ss;
        ss << line;
        string temp;
        int found;
        int cc = 0;
        int count, source, dest;
        while (!ss.eof()) {
            ss >> temp;
            if (stringstream(temp) >> found) {
                if (cc == 0)
                    count = found;
                else if (cc == 1)
                    source = found;
                else
                    dest = found;
                cc++;
            }
        }
        stack<char> trans;
        for (int i = 0; i < count; ++i) {
            trans.push(stackies[source - 1].front());
            stackies[source-1].pop_front();
        }
        while(!trans.empty()) {
            stackies[dest - 1].push_front(trans.top());
            trans.pop();
        }
    }
    for (deque<char> d: stackies) {
        cout << d[0];
    }
    return 0;
}
int part1() {
    string line;
    vector<deque<char>> stackies;
    stackies.assign(9, deque<char>());
    while(true) {
        getline(cin, line);
        int j = 0;
        for (int i = 1; i < line.size(); i += 4) {
            char c = line[i];
            if (c == '1')
                goto out;
            if (c < 91 && c > 32) {
                stackies[j].push_back(c);
            }
            j++;
        }
    }
    out: getline(cin, line);
    while (getline(cin, line)) {
        stringstream ss;
        ss << line;
        string temp;
        int found;
        int cc = 0;
        int count, source, dest;
        while (!ss.eof()) {
            ss >> temp;
            if (stringstream(temp) >> found) {
                if (cc == 0)
                    count = found;
                else if (cc == 1)
                    source = found;
                else
                    dest = found;
                cc++;
            }
        }
        for (int i = 0; i < count; ++i) {
            stackies[dest - 1].push_front(stackies[source - 1][0]);
            stackies[source - 1].pop_front();
        }
    }
    for (deque<char> d: stackies) {
        cout << d[0];
    }
    return 0;
}
