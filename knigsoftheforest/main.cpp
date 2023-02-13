#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class moose {
public:
    int year;
    int strength;
    bool karl;
    moose(int y, int s, bool b) {
        year = y;
        strength = s;
        karl = b;
    }
};

/* true means dont swap, false means swap a and b
* This allows us to sort a priority queue of moose by their years, */
class sortYear {
public:
    bool operator()(moose a, moose b) {return a.year > b.year;}
};
bool operator<(moose a, moose b) {return a.strength < b.strength;}


int main() {
    int cases, numyears, karl_year, karl_stren;
    cin >> cases >> numyears >> karl_year >> karl_stren;
    moose karl = moose(karl_year, karl_stren, true);
    priority_queue <moose, vector<moose>> contestant_pool; // Sorted by strength, greatest to least
    priority_queue<moose, vector<moose>, sortYear> total_contestants; // Sorted by year, least to greatest
    int a, b;
    while (cin >> a >> b)
        total_contestants.push(moose(a, b, false));

    int year = 2011;
    for (int i = year; i < year + numyears; i++) {
        while (total_contestants.top().year == i && !total_contestants.empty()) {
            moose x = total_contestants.top();
            contestant_pool.push(x);
            total_contestants.pop();
        }
        if (i == karl.year)
            contestant_pool.push(karl);
        if (contestant_pool.top().karl) {
            cout << i << endl;
            goto finish;
        }
        contestant_pool.pop();
    }
    cout << "unknown\n";
    finish: return 0;
}

