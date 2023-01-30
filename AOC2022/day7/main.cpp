#include <iostream>
#include <map>

using namespace std;

class dir{
public:
    int size;
    string name;
    dir* par;
    map<string,dir*> subD;
    dir(string name, dir* par) {
        this->name = name;
        this->par = par;
        size = 0;
    }

    void calSize() {
        for(auto & [n, d] : subD) {
            this->size += d->size;
        }
    }
};
void traverse(dir** head) {
    for(auto & [n, d] : (*head)->subD) {
        traverse(&d);
    }
    (*head)->calSize();
}
int main() {
    dir root = dir("/", nullptr);
    dir* top = &root;
    dir** cur = &top;
    string line;
    while(cin >> line) {
        if (line == "$") {
            string command;
            cin >> command;
            if (command == "cd") {
                cin >> command;
                if (command == "..") {
                    (*cur)->par->size += (*cur)->size;
                    cur = &(*cur)->par;
                } else
                    cout << ((*cur)->subD[command])->name;
            }
        } else if(line == "dir") {
            string name;
            cin >> name;
            dir newDir = dir(name, *cur);
            (*cur)->subD[name] = &newDir;
        } else{
            (*cur)->size += stoi(line);
            cin >> line;
        }
    }
    traverse(&top);
    return 0;
}
/*
 * create dir a, add two numbers to / size, create dir d
 *
 */