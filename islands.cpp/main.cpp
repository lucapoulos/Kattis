#include <bits/stdc++.h>
using namespace std;

/*
 * Find subislands given a starting index
 * Return int arr[2], arr[0] = count, arr[1] = end of island
 */
int* find(vector<int> &list, int left, int i, int right) {
    static int* store = (int*)malloc(sizeof(int) * 2);
    int count = 1;

    while (i < right && list[i+1] > left) {
        if(list[i+1] > list[i]){
            int temp = list[i];
            store = find(list, temp, i + 1, right);
            count += store[0];
        }
        i++;
    }
    right = i;
    store[0] = count;
    store[1] = right;

    return store;
}
int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int num;
        cin >> num;
        int count = 0;
        vector<int> list (12);
        for (int i = 0; i < 12; ++i)
            cin >> list[i];
        for (int i = 0; i < 11; ++i) {
            if (list[i+1] > list[i]) {
                int left = list[i];
                int* arr = find(list, left, i+1, 11);
                count+= arr[0];
                i = arr[1];
            }
        }
        cout << num << + " " << count <<  '\n';
        t--;
    }
    return 0;
}



/*
4
1 0 0 1 1 2 2 1 1 0 1 2 0 => 4
2 0 1 2 4 3 1 3 4 5 2 1 0
3 0 1 2 4 4 1 0 2 4 1 0 0
4 0 1 2 3 4 5 6 7 8 9 10 0
 */