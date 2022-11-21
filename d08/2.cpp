#include <iostream>
#include <fstream>

using namespace std;

const int x = 25;
const int y = 6;

int main () {

    ifstream in("in.txt");

    string data;
    in >> data;

    string result(x * y, ' ');

    for (int i = 0; i < y; ++i)
        for (int j = 0; j < x; ++j)
            for (int a = 0; a < 100; ++a)
                if (data[a * 150 + i * x + j] != '2') {
                    result[i * x + j] = data[a * 150 + i * x + j];
                    break;
                }

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j)
            cout << (result[i * x + j] == '1' ? "#" : " ");
        cout << '\n';
    }


    in.close();

    return 0;
}