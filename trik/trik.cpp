#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<char,int> cups;
    cups['a'] = 1;
    cups['b'] = 0;
    cups['c'] = 0;

    char arr[] = {'a','b','c'};
    string s;
    cin >> s;
    for (char x: s){
        if (x == 'A') {
            int temp = cups['a'];
            cups['a'] = cups['b'];
            cups['b'] = temp;
        } else if (x == 'B') {
            int temp = cups['b'];
            cups['b'] = cups['c'];
            cups['c'] = temp;
        } else {
            int temp = cups['a'];
            cups['a'] = cups['c'];
            cups['c'] = temp;
        }
    }

    for(char k: arr) {
        if (cups[k] == 1)
            cout << k - '`' << endl;
    }


    return 0;
}
