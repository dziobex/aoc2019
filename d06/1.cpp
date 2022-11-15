#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Object {
    vector<Object*> childs;

    int direct = 0, indirect = 0;

    void addDirect() {
        ++direct;
    }

    int calculateIndirect() {
        int sum = 0;

        for (int i = 0; i < childs.size(); ++i) {
            sum += childs[i]->direct + childs[i]->calculateIndirect();
        }

        return sum;
    }
};

int main () {
    ifstream in("input.txt");

    string data;
    map<string, Object*> objects;

    while (in >> data) {
        string a = data.substr(0, 3), b = data.substr(4, 3);

        Object *aO = nullptr, *bO = nullptr;
        
        if (objects.find(a) != objects.end()) {
            aO = objects[a];
        } else {
            aO = new Object();
            objects.insert(make_pair(a, aO));
        }

        if (objects.find(b) != objects.end()) {
            bO = objects[b];
        } else {
            bO = new Object();
            objects.insert(make_pair(b, bO));
        }

        aO->childs.push_back(bO);
        aO->addDirect();
    }

    int dirs = 0, indirs = 0;
    for (auto const& x : objects) {
        dirs += x.second->calculateIndirect();
    }

    cout << dirs+objects.size() - 1;


    in.close();


    return 0;
}