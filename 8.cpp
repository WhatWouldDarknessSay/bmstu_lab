#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
int main(){
    double x, y, z1, z2;
    cout << "Введите X: ";
    cin >> x;
    cout << "Введите Y: ";
    cin >> y;
    if (y < x * tan(M_PI / 3) && y < -1 * x * tan(M_PI / 3)){
        if (y < 0 && y > -2){
            z1 = 1;
        } else {
            z1 = 2;
        }
    } else if(y >= x * tan(M_PI / 3) && y >= -1 * x * tan(M_PI / 3)){
        z1 = 2;
    } else if(y > x * tan(M_PI / 3) && y < -1 * x * tan(M_PI / 3)){
        z1 = 4;
    } else {
        z1 = 3;
    }
    z2 = 2;
    if (y > -2){
        z2 = 1;
    }
    if (y < x * tan(M_PI / 3) && y > -1 * x * tan(M_PI / 3)){
        z2 = 3;
    }
    if (y > x * tan(M_PI / 3) && y < -1 * x * tan(M_PI / 3)){
        z2 = 4;
    }
    cout << "Значение Z1: " << z1 << endl << "Значение Z2: " << z2 << endl;
}