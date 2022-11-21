#include <iostream>
#include <fstream>

using namespace std;

const int x = 25;
const int y = 6;

int main () {

    ifstream in("in.txt");

    string data;
    in >> data;

    int layersCount = data.size()/(x*y);
    
    int layerRes = 0, maxCount = 0;
    for (int i = 0; i < layersCount; ++i) { // 100 layers in single data: 15000/(25*6)=100

        int oC=-1, tC=0;
        for (int j = 0; j < x * y; ++j) {
            if (data[i * layersCount + j] == '1')
                oC++;
            else if (data[i * layersCount + j] == '2')
                tC++;
        }

        if (oC + tC > maxCount) {
            maxCount = oC + tC;
            layerRes = oC * tC;
        }

    }

    cout << layerRes;


    in.close();

    return 0;
}