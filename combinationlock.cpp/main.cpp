#include <bits/stdc++.h>
using namespace std;

int  main() {
    // convert combination locks to degrees 1 tick = 9 degrees
    int start, first, second, third, distance;
    cin >> start >> first >> second >> third;

    while (!(start == 0 && first == 0 && second == 0 && third == 0)) {
        distance = 80; // 2 turns cw
        // 10 0 -> 30
        // 10 0
        // 0 39 38 37
        // cw
        if (first > start) distance+= start + 40 - first;
        else if (first < start) distance += start - first;
        distance += 40; // 1 ccw turn

        //ccw
        if (first > second) distance += 40 - first + second;
        else if (first < second) distance += second - first;
        //cw
        if(third > second) distance +=  40 - third + second;
        else if (third < second) distance += second - third;

        cout << distance * 9 << endl;
        cin >> start >> first >> second >> third;
    }
    return 0;
}