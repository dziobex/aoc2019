#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

int height = 0, width = 0;
int centerX = 0, centerY = 0;

void generateMap() {
    ifstream in("input.txt");

    int r = 0, l = 0, u = 0, d = 0;
    

    string line;
    while (in >> line) {
        int xaxis=0, yaxis=0;
        stringstream ss(line);

        vector<string> coms;
        while (ss.good()) {
            string c;
            getline(ss, c, ',');
            coms.push_back(c);
        }

        for (auto& com : coms) {
    
            char dir = com[0];
            int length = atoi(com.substr(1, com.size() - 1).c_str());

            if (dir == 'U') {
                yaxis -= length;
            } else if (dir == 'D') {
                yaxis += length;
            } else if (dir == 'R') {
                xaxis += length;
            } else if (dir == 'L') {
                xaxis -= length;
            }

            if (xaxis > r)
                r=xaxis;
            else if (xaxis < l)
                l=xaxis;
            else if (yaxis > d)
                d=yaxis;
            else if (yaxis < u)
                u=yaxis;
        }
    }

    height = abs(u)+d+1;
    width = abs(l) + r + 1;
    centerX = abs(l);
    centerY = abs(u);

    in.close();
}

short tab[20000][20000]{}; // zeroed
int paths[15000][15000]{};

int main () {
    generateMap();

    ifstream in("input.txt");

    int minSum = 1000000;
    //centerX = 10000, centerY = 10000;

    string line; int cou = 0;
    while (in >> line) {
        cou++;
        int cpx = centerX, cpy = centerY;

        stringstream ss(line);

        vector<string> coms;
        while (ss.good()) {
            string c;
            getline(ss, c, ',');
            coms.push_back(c);
        }

        int lSum = 0;
        for (auto& com : coms) {
            //cout << com << '\n';

            char dir = com[0];
            int length = atoi(com.substr(1, com.size() - 1).c_str());

            //tab[cpx][cpy] = true;

            while (--length >= 0) {
                if (dir == 'U')
                    cpy--;
                else if (dir == 'D')
                    cpy++;
                else if (dir == 'L')
                    cpx--;
                else if (dir == 'R')
                    cpx++;

                if (tab[cpx][cpy] != 0 && tab[cpx][cpy] != cou) {
                    int d = paths[cpx][cpy] + lSum+1;
                    //cout << cou << ": " << d << '\n';
                    cout << cou << "; " << paths[cpx][cpy] << " + " << lSum+1 << '\n';
                    if (cou > 1 && d < minSum)
                        minSum = d;
                }
                tab[cpx][cpy] = cou;
                paths[cpx][cpy] = ++lSum;
                //cout << "ehe " << cpx << " " << cpy << "\n";
                
            }
        }

    }

    cout << centerX << "; " << centerY << '\n';
    cout << width << " " << height << '\n';

    
    /*
    for (int i = 0; i < centerX+height; ++i)
    {
        for (int j = 0; j < centerY+width; ++j) {
            if (j == centerX && i == centerY)
                ff << "o ";
            else
            ff << (tab[j][i] == 1 ? "#" : ".") << " ";
        }
        ff << "\n";
    }
    ff.close();
    */

    cout << minSum;


    in.close();

    return 0;
}
