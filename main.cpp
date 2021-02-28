#include <iostream>
#include "quanc8.h"
#include <cmath>
#include "lagrange.h"
#include "SPLINES.H"

using namespace std;


double function(double t) {
    if (t == 0.0) return 0.0;
    else return (1 - cos(t)) / t;
}

double correctValue(double x) {
    double result;
    double errest;
    int nofun;
    double flag;
    quanc8(function, 0.0, x, 0.0, 0.0, &result, &errest, &nofun, &flag);
    return result;
}

int main() {

    double values[11];
    double keys[11];
    double count = 2.0;
    correctValue(0.0);
    for (int i = 0; i < 11; i++) {
        keys[i] = count;
        values[i] = correctValue(count);
        count += 0.1;
    }

    double count1 = 2.05;
    double lagrangeValues[10];
    for (double &lagrangeValue : lagrangeValues) {
        lagrangeValue = lagrange(10, keys, values, 2.0);
        count1 += 0.1;
    }

    count1 = 2.05;
    double b[11];
    double c[11];
    double d[11];
    double splineValues[10];
    spline(10, keys, values, b, c, d);
    for (double &splineValue : splineValues) {
        splineValue = seval(10, &count1, keys, values, b, c, d);
        count1 += 0.1;
    }

    double quancValues[10];
    count1 = 2.05;
    for (double &quancValue : quancValues) {
        quancValue = correctValue(count1);
        count1 += 0.1;
    }
    cout << "QUANC8 " << "Spline " << "Lagrange " << endl;
    for (int i = 0; i < 10; ++i) {
        cout << quancValues[i] << " " << splineValues[i] << " " << lagrangeValues[i] << endl;
    }


}


