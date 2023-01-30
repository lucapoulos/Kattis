#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
#define um unordered_map

int waitTime(string c, um<char,int> lci) {
    int wt = 0;
    for (int i = 0; i < c.size(); ++i) {
        lci.emplace(pair<char,int>(c[i],i));
    } // getting last index
    for (int i = 0; i < c.size(); ++i) {
        wt += lci[c[i]] * 5; // Every char must wait until their last friend
    }
    return wt;
}

int main() {
    int t;
    cin >> t;

    while (t!=0) {
        int n; // length of line
        cin >> n;
        string line;
        cin >> line;
        um<char,int> lci;
        for (int i = 0; i < n; ++i) {
            if (lci.count(line[i]) == 1) lci.erase(line[i]);
            lci.emplace(pair<char,int>(line[i],i));
        }
        int originalTime = waitTime(line,lci);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                int index = lci[line[j]];
                int next = lci[line[j + 1]];

                if (index > next) {
                    if(j+1 == next) {
                        lci.erase(line[j + 1]);
                        lci.emplace(pair<char,int>(line[j+1], j)); // updating hash
                    }
                    if (j == index) {
                        lci.erase(line[j]);
                        lci.emplace(pair<char,int>(line[j], j+1));
                    }
                    char temp = line[j];
                    line[j] = line[j+1];
                    line[j+1] = temp;
                }
            }

        }
        cout << originalTime - waitTime(line, lci) << '\n';
        t--;
    }

    return 0;
}
