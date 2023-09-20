#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double x, y1, y2;
    cout << "Введите значение X: ";
    cin >> x;
    if (x < -1){
        y1 = -1;
    } else if (x < 1) {
        y1 = x;
    } else if (x < 2) {
        y1 = -x + 2;
    } else {
        y1 = 0;
    }

    y2 = 0;
    if (x < -1) {
        y2 = -1;
    }
    if (x > -1 && x < 2){
        y2 = 1 - abs(x - 1);
    }
    cout << "Ваше значение Y1: " << y1 << endl;
    cout << "Ваше значение Y2: " << y2 << endl;
}
