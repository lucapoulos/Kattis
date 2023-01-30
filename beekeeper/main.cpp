#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
    while (cin >> n && n != 0) {
        int maxPairs = -1;
        string maxWord;
        for (int i = 0; i < n; i++) {
            string line;
            cin >> line;
            int count = 0;
            char prev = '.';
            for (int j = 0; j < line.length(); ++j) {
                if (line[j] == prev && vowels.find(line[j]) != vowels.end()){
                    count++;
                }
                prev = line[j];
            }
            if (count > maxPairs) {
                maxPairs = count;
                maxWord = line;
            }
        }
        cout << maxWord << '\n';
    }
    return 0;
}
