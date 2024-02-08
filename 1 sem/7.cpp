#include<iostream>
#include<cmath>
using namespace std;
double f1(double x){
    double y1;
     if (x < -1){
        y1 = -1;
    } else if (x < 1) {
        y1 = x;
    } else if (x < 2) {
        y1 = -x + 2;
    } else {
        y1 = 0;
    }
    return y1;
}
double f2(double x){
    double y2 = 0;
    if (x < -1) { 
        y2 = -1;
    }
    if (x >= -1 && x < 2){
        y2 = 1 - abs(x - 1);
    }
    return y2;
}

int main(){
    double x, y1, y2;
    cout << "Введите значение X: ";
    cin >> x;
    cout << "Ваше значение Y1: " << f1(x) << endl;
    cout << "Ваше значение Y2: " << f2(x) << endl;
    return 0;
}
