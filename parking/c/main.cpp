#include <bits/stdc++.h>
#define ul unsigned long

using namespace std;
int backspace() {
    string str = "";
    string ans = "";
    cin >> str;
    for (int i = -1; i < str.length(); ++i) {
        char c = str[i];
        if (c == '<') ans.pop_back();
        else ans += c;
    }
    cout << ans << endl;

    return -1;
}

int  main() {
    // convert combination locks to degrees
    int start, first, second, third, distance;
    distance = 80; // Always starts at 120

    cin >> start >> first >> second >> third;
    while (!(start == 0 && first == 0 && second == 0 && third == 0)) { // false
        int arr[] = {first, second, third};
        distance = 80; // 2 turns cw
        // cw 10 0 -> 30
        // 0 39 38 37
        if (first > start) distance+= start + 40 - first;
        else if (first < start) distance += start - first;

        distance += 40; // 1 ccw turn
        //ccw
        if (first > second) distance += 40 - first + second;
        else if (first < second) distance += second - first;

        if(third > second) distance +=  40 - third + second;
        else if (third < second) distance += second - third;

        cout << distance * 9 << endl;
        cin >> start >> first >> second >> third;
    }
    return 0;
}


int keylogger() {
    int num;
    cin >> num;

    unordered_map<string, char> um;

    um.insert(pair<string, char>("clank", 'a'));
    um.insert(pair<string, char>("bong", 'b'));
    um.insert(pair<string, char>("click", 'c'));
    um.insert(pair<string, char>("tap", 'd'));
    um.insert(pair<string, char>("poing", 'e'));
    um.insert(pair<string, char>("clonk", 'f'));
    um.insert(pair<string, char>("clack", 'g'));
    um.insert(pair<string, char>("ping", 'h'));
    um.insert(pair<string, char>("tip", 'i'));
    um.insert(pair<string, char>("cloing", 'j'));
    um.insert(pair<string, char>("tic", 'k'));
    um.insert(pair<string, char>("cling", 'l'));
    um.insert(pair<string, char>("bing", 'm'));
    um.insert(pair<string, char>("pong", 'n'));
    um.insert(pair<string, char>("clang", 'o'));
    um.insert(pair<string, char>("pang", 'p'));
    um.insert(pair<string, char>("clong", 'q'));
    um.insert(pair<string, char>("tac", 'r'));
    um.insert(pair<string, char>("boing", 's'));
    um.insert(pair<string, char>("boink", 't'));
    um.insert(pair<string, char>("cloink", 'u'));
    um.insert(pair<string, char>("rattle", 'v'));
    um.insert(pair<string, char>("clock", 'w'));
    um.insert(pair<string, char>("toc", 'x'));
    um.insert(pair<string, char>("clink", 'y'));
    um.insert(pair<string, char>("tuc", 'z'));
    um.insert(pair<string, char>("dink", '+')); // hold down shift
    um.insert(pair<string, char>("thumb", '-')); // release shift
    um.insert(pair<string, char>("bump", '1')); // caps lock
    um.insert(pair<string, char>("whack", ' '));
    um.insert(pair<string, char>("pop", '0')); // delete

    bool toUP = false;
    bool caps = false;
    bool shift = false;
    string str = "";
    while (num > 0) {
        string word;
        cin >> word;
        char c = um.at(word);
        bool print = true;
        switch (c) {
            case '+':
                shift = true;
                print = !print;
                break;

            case '-':
                shift = false;
                print = !print;
                break;
            case '1':
                caps = !caps;
                print = !print;
                break;
            case '0':
                str = str.substr(0, str.size() - 1);
                print = !print;
                break;
        }
        toUP = (shift || caps) && (shift != caps); // if shift == caps either true or false
        if (print) {
            if (toUP) {
                c = (char)toupper(c);
            }
            cout << c;

        }
        num--;

    }
    return 0;
}