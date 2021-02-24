#include <iostream>
#include "rkf45.h"
#include "quanc8.h"
#include <cmath>



double function(double t) {
    if (t==0.0) return 0.0;
    else return (1 - cos(t)) / t;
}

double correctValue(double x) {
    double result;
    double errest;
    int nofun;
    double flag;
    quanc8(function, 0.0, x, 0.0, 0.0, &result, &errest, &nofun, &flag);
    //std::cout << result;
    return result;
}

int main() {
    double values[10];
    double count = 2.0;
    correctValue(0.0);
    std::cout << correctValue(2.0) << std::endl;


}


