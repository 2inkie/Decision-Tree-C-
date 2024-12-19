// src/utils.cpp
#include "../include/utils.h"
#include <cmath>

double GiniIndexThreshold(Iris *current[150]) {
    int count = 50;
    int leftS = 0, leftVe = 0, leftVi = 0, rightS = 50, rightVe = 50,
        rightVi = 50, leftTotal, rightTotal;
    double minGiniIndex = 50, minGiniIndexCheck, giniLeft, giniRight, avg,
           threshold;

    for (int i = 0; i < 149; i++) {
        avg = (current[i]->feature[3] + current[i + 1]->feature[3]) / 2;

        if (i < 50) {
            leftS++;
            rightS--;
        } else if (i < 100) {
            leftVe++;
            rightVe--;
        } else {
            leftVi++;
            rightVi--;
        }

        leftTotal = leftS + leftVe + leftVi;
        rightTotal = 150 - leftTotal;

        giniLeft = 1 - pow(leftS / static_cast<double>(leftTotal), 2) -
                   pow(leftVe / static_cast<double>(leftTotal), 2) -
                   pow(leftVi / static_cast<double>(leftTotal), 2);

        giniRight = 1 - pow(rightS / static_cast<double>(rightTotal), 2) -
                    pow(rightVe / static_cast<double>(rightTotal), 2) -
                    pow(rightVi / static_cast<double>(rightTotal), 2);

        minGiniIndexCheck =
            giniLeft * leftTotal / 150.0 + giniRight * rightTotal / 150.0;

        if (minGiniIndexCheck < minGiniIndex) {
            minGiniIndex = minGiniIndexCheck;
            threshold = avg;
        }
    }

    return threshold;
}
