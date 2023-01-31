#include <bits/stdc++.h>
using namespace std;
class problem1 {

    string toBinary(int a) {
        string o;
        while (a) {
            if (a & 1)
                o += '1';
            else
                o += '0';
            a>>=1;
        }
        while (o.size() < 4)
            o = o + '0';
        string s = "";
        for (int i = o.size()-1; i > -1; i--) {
            s = s + o[i];
        }
        return s;
    }

    int main() {
        char grid[4][4];
        string line;
        while(cin >> line) {
            for (int i = 0; i < line.size(); i++) {
                int c = line[i] - '0';
                string digit = toBinary(c);
                for (int j = 0; j < digit.size(); j++) {
                    int k = digit[j] - '0';
                    if (k == 0)
                        grid[j][i] = '.';
                    else
                        grid[j][i] = '*';
                }
            }

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (j == 2) {
                        cout << " " << grid[i][j];
                        continue;
                    }
                    cout << grid[i][j];
                }
                cout << endl;
            }
        }

        return 0;
    }
};

int main() {
    cout << "hello";
    return 0;
}



