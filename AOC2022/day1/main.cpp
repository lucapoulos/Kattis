#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<>> top3;
    string line;
    while (getline(cin, line)) {
        int sum = 0;
        while (!line.empty()) {
            sum+= stoi(line);
            getline(cin, line);
        }
        if(top3.empty() || sum > top3.top()) {
            if(top3.size() == 3)
                top3.pop();
            top3.push(sum);
        }
    }
    int total = 0;
    while(!top3.empty()) {
        total += top3.top();
        top3.pop();
    }
    cout << total << '\n';
    return 0;
}
