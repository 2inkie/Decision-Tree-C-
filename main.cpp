#include "./include/iris.h"
#include "./include/utils.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int i = 0;
    bool check = true;

    enum header { SL = 0, SW = 1, PL = 3, PW = 4, VY = 5 };

    string outp;
    ifstream file("./data/iris.csv");
    Iris iris[150];

    while (getline(file, outp)) {
        if (check == true) {
            check = false;
            continue;
        }

        stringstream ss(outp);
        string valInp;

        getline(ss, valInp, ',');
        iris[i].feature[0] = stod(valInp);

        getline(ss, valInp, ',');
        iris[i].feature[1] = stod(valInp);

        getline(ss, valInp, ',');
        iris[i].feature[2] = stod(valInp);

        getline(ss, valInp, ',');
        iris[i].feature[3] = stod(valInp);

        getline(ss, valInp);
        iris[i].variety = valInp;

        i++;
    }
    file.close();

    Iris *irisPtrs[150];
    for (int i = 0; i < 150; ++i) {
        irisPtrs[i] = &iris[i];
    }

    double threshold = GiniIndexThreshold(irisPtrs);
    cout << threshold << endl;

    return 0;
}
