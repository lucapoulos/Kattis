#include <iostream>
#include <unordered_set>
#include <deque>
using namespace std;
bool check4(deque<char> deck) {
    unordered_set<char> set;
    while (!deck.empty()) {
        set.insert(deck.front());
        deck.pop_front();
    }
    if (set.size() == 14)
        return true;
    return false;
}
int main() {
    string line;
    cin >> line;
    deque<char> deck;
    bool found = false;
    for (int i = 0; i < line.size(); ++i) {
       char c = line[i];
       if (found == true) {
           cout << i++ << '\n';
           break;
       }
       deck.push_back(c);
        if (deck.size() == 14) {
            found = check4(deck);
            deck.pop_front();
        }
    }
    return 0;
}
// bvwbjplbgvbhsrlpgdmjqwftvncz