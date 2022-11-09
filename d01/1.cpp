#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main () {
    ifstream input("input.txt");

    int n, sum = 0;
    while (input >> n) {
        sum += floor(n / 3) - 2;
    }

    cout << sum;
    
    input.close();

    return 0;
}