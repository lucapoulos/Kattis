#include <iostream>
#include <queue>
#include <unordered_map>
#include <chrono>
using namespace std;
class node {
public:
    int value, height;
    node(int val, int h) {
        value = val;
        height = h;
    };
};
int main() {
//    auto start = std::chrono::high_resolution_clock::now();
    unordered_map<int,int> floors;
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    queue<node> tree;
    if (s == g) {
        cout << 0 << endl;
        return 0;
    }
    tree.push(node(s,0));
    node x = tree.front();
    while (!tree.empty()) {
        if (x.value > 0 && x.value <= f) {
            if (floors.count(x.value) == 0) { // not visited
                floors.insert(make_pair(x.value,x.height));
                    tree.push(node(x.value+u, x.height + 1));
                    tree.push(node(x.value-d, x.height + 1));
            } else { // visited
                if (floors[x.value] >= x.height) { // less than or equal to shortest path
                    floors[x.value] = (x.height < floors[x.value]) ? x.height : floors[x.value];
                        tree.push(node(x.value+u, x.height + 1));
                        tree.push(node(x.value-d, x.height + 1));
                }
            }
        }
        tree.pop();
        x = tree.front();
    }
    if (floors.count(g) == 0 && s != g) {
        cout << "use the stairs\n";
    } else{
        cout << floors[g] << endl;
    }
//    auto end = std::chrono::high_resolution_clock::now();
//    cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << endl;

    return 0;
}
