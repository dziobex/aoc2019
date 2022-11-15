#include <iostream>
#include <fstream>

using namespace std;

bool inspect (int n) {
    int prev = n % 10;
    n /= 10;
    bool copyFound = false;

    while (n > 0) {
        if (prev < n % 10)
            return false;
        if (prev == n % 10)
            copyFound = true;
        prev = n % 10;
        n /= 10;
    }

    return copyFound;
}

int main () {
    ifstream in("in.txt");

    int a, b, counter = 0;
    in >> a >> b;

    for (; a <= b; ++a) {
        if (inspect(a))
            ++counter;
    }

    cout << counter;

    in.close();

    return 0;
}