#include <iostream>
#include <fstream>

using namespace std;

bool inspect (int n) {
    int prev = n % 10, cC = 0;
    n /= 10;
    bool copyFound = false;

    while (n > 0) {
        if (prev < n % 10)
            return false;
        if (prev == n % 10)
            ++cC;
        else {
            if (cC == 1)
                copyFound = true;
            cC = 0;
        }

        prev = n % 10;
        n /= 10;
    }

    return copyFound || cC == 1;
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