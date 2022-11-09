#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

const int size = 141;

int getAdress0(int tab[], int noun, int verb) {
    tab[1] = noun;
    tab[2] = verb;

    for (int i = 0; tab[i] != 99; i += 4) {
        //cout << tab[i+1] << " " << tab[i+2] << " " << tab[i+3] << '\n';
        if (tab[i] == 1)
            tab[tab[i + 3]] = tab[tab[i + 1]] + tab[tab[i + 2]];
        else if (tab[i] == 2)
            tab[tab[i + 3]] = tab[tab[i + 1]] * tab[tab[i + 2]];
    }

    return tab[0];
}

int main () {
    ifstream input("input.txt"); // 141 el

    int n, a = 0;
    int tab[size]{}, t[size]{};
    while (input >> n)
        tab[a++] = n;

    copy(tab, tab + size, t);
    cout << "1: " << getAdress0(t, 12, 2) << "\n2: ";

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            copy(tab, tab + size, t);
             if (getAdress0(t, i, j) == 19690720) {
                cout << 100 * i + j;
                break;
            }
        }
    
    input.close();

    return 0;
}
