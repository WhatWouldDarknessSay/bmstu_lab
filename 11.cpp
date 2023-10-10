#include<iostream>
#include<math.h>
#define _USE_MATH_DEFINES
using namespace std;
double r(double x){ // округление для вывода
    return ceil(x * 10000.0) / 10000.0;
}
int main(){
    double x, arcsin, pribl1, pribl2, errabs, errotn, k = 5;
    cout << "deg\tsin\tasin\tpribl\tabserr\totnerr\n"; // вывод заголовка
    for(int i; i < 12; i++){
        x = sin(k* M_PI / 180);
        arcsin = asin(x);
        pribl1 = x + (pow(x, 3) / 6) - (3 * pow(x, 5) / 40) + (5 * pow(x, 7) / 112) - (35 * pow(x, 9) / 1152);
        pribl2 = x + x * x * x / 6 - x * x * x * x * x * 3 / 40 + x*x*x*x*x*x*x * 5 / 112 - x*x*x*x*x*x*x*x*x * 35 / 1152;
        errabs = abs(pribl1 - arcsin);
        errotn = errabs / arcsin;
        cout << r(k) << "⁰\t" << r(x) << "\t" << r(arcsin) << "\t" << r(pribl1) << "\t" << r(errabs) << "\t" << r(errotn) << endl;
        k += 5;
    }
}