#include<iostream>
#include<cmath>
using namespace std;
double f(double x){
    return cos(4 * x) - x * 0.5;
}
double g(double x){
    return 2 * cos(4 * x);
    }

double g_pr(double x){
    return - 8 * sqrt(sin(4 * x));
}
int main(){
    double x0;
    double x1 = 1.7;
    // МЕТОД ИТЕРАЦИЙ
    double eps = 0.01;
    for (int i = 0; i < 1000000; i++) {
        x0 = x1;
        g_pr(x0) > 1 ? x1 = f(x0): x1 = g(x0);
        // x1 = g(x0);
        if (abs(x0 - x1) < eps) {break;}
    }
    cout << x1 << endl;

    // МЕТОД ПОЛОВИННОГО ДЕЛЕНИЯ

    double xr = 1.7;
    double xl = 0.5;
    while (abs(xr - xl) > eps){
        (f((xr + xl) / 2) > 0) == (f(xl) > 0) ? xl = (xr + xl) / 2 : xr = (xr + xl) / 2;
    }
    cout << xr;
}
x = 