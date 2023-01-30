#include <bits/stdc++.h>
using namespace std;
// lead has to be checked every round, streak is everytime you switch
int checkLead(int arr[], string s){
    if (s == "Yraglac") return arr[0] - arr[1];
    return arr[1] - arr[0];
}

int yWin(int maxYL, int maxNL) {
    if (maxYL > maxNL) return - 1;
    else if(maxYL < maxNL) return 1;
    return 0;
}
int nWin(int maxYS, int maxNS) {
    if (maxNS > maxYS) return 1;
    else if(maxNS < maxYS) return -1;
    return 0;
}
int main() {
    int yStreak = 0, nStreak = 0, yLead = 0, nLead = 0, n;
    int maxYS = 0, maxNS = 0, maxYL = 0, maxNL = 0;
    int game[2] = {0,0}; // Y N
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "Yraglac") {
            yStreak++;
            game[0]++;
            yLead = checkLead(game, s);
            maxYL = max(yLead, maxYL);
            maxYS = max(yStreak, maxYS);
            nStreak = 0;
        } else {
            nStreak++;
            game[1]++;
            nLead = checkLead(game, s);
            maxNL = max(nLead, maxNL);
            maxNS = max(nStreak, maxNS);
            yStreak = 0;
        }
    }
    int yw = yWin(maxYL, maxNL);
    int nw = nWin(maxYS, maxNS);
    if (yw == nw) cout << "Agree\n";
    else cout << "Disagree\n";
    return 0;
}

/*
 * Not is longest consecutive streak, tie if both streaks are same length
 * Y
 * N
 * Y
 * N
 * N
 *
 */
