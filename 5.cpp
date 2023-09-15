#include<iostream>
#include <cmath>
using namespace std;
int main(){
    double x[3] = {-3, 0, 3};
    double long y[3] = {0, 0, 0};
    int a = 4;
    for (int i=0; i < 3; ++i){
        y[i] = pow(a, x[i]) - (pow(a, 2 * x[i]) / 3) + (pow(a, 3 * x[i]) * 4 / (3 * 5)) - (pow(a, 4 * x[i]) * 6 / (3 * 5 * 7));
        cout << y[i] << endl;
    };
    return 0;
}