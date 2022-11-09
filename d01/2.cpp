#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main () {
    ifstream input("input.txt");

    int n, sum = 0;
    while (input >> n) {
        int y = 0, i = 1;
            n = floor(n / 3) - 2;

        do {
            y += n;
            n = floor(n / 3) - 2;
        } while (n > 0);

        sum += y;
    }

    cout << sum;
    
    input.close();

    return 0;
}