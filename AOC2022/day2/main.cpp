#include <bits/stdc++.h>
using namespace std;
#define urk 'X'
#define rk 'A'
#define upapr 'Y'
#define papr 'B'
#define uscissors 'Z'
#define scissors 'C'
// part 1
int part1() {
    int total = 0;
    char c;
    char b;
    while (cin >> c) {
        cin >> b;
        if (c == rk) {
            if (b == urk) // draw X
                total += 3 + 1;
            else if (b == upapr)
                total += 6 + 2; // papr > rk
            else
                total += 3;
        } else if (c == papr) {
            if (b == upapr)
                total += 3 + 2;
            else if (b == uscissors)
                total += 6 + 3;
            else
                total ++;
        } else { // scissors
            if (b == uscissors)
                total += 3 + 3;
            else if (b == urk)
                total += 7;
            else
                total += 2;
        }
    }
    cout << total << '\n';
    return 0;
}

int part2() {
    int total = 0;
    char c;
    char b;
    while (cin >> c) {
        cin >> b;
        if (b == urk) { // lose
            if (c == rk)
                total += 3;
            else if (c == papr) {
                total += 1;
            } else
                total += 2;
        } else if (b == upapr) {
            if (c == rk)
                total += 3 + 1;
            else if (c == papr)
                total += 3 + 2;
            else
                total += 3 + 3;
        } else {
            if (c == rk)
                total += 6 + 2;
            else if (c == papr)
                total += 6 + 3;
            else
                total += 6 + 1;
        }
    }
    cout << total << '\n';
    return 0;

}
int main() {
    int total = 0;
    unordered_map<char,int> lose;
    unordered_map<char,char> tie;
    unordered_map<char,char> win;
    unordered_map<char,int> map;
    char a, b;
    lose['A'] = 3; lose['B'] = 1; lose['C'] = 2;
    tie['A'] = 1; tie['B'] = 2; tie['C'] = 3;
    win['A'] = 2; win['B'] = 3; win['C'] = 1;
    while(cin >> a >> b) {
        if (b == 'X')
            total += lose[a];
        else if(b == 'Y')
            total += 3 + tie[a];
        else
            total += 6 + win[a];
    }
    cout << total << '\n';
    return 0;
}