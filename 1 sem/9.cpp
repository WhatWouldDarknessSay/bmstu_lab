#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double a, b, c;
    cin >> a >> b >> c;
    double d = b * b - 4 * a * c;
    if (a == 0 && b == 0){
        c == 0 ? cout << "любое число": cout << "нет решений";
    } else if(a == 0){
        double ans = -c / b;
        ans == -0.0 ? ans = 0.0: true;
        cout << ans;
    } else if(b == 0){
        double ans = sqrt(-c / a);
        cout << ans;
    } else {
        if (d > 0){
            double ans1 = (-b + sqrt(d)) / (2 * a);
            double ans2 = (-b - sqrt(d)) / (2 * a);
            cout << ans1 << " " << ans2;
        } else if (d == 0){
            double ans = (-b + sqrt(d)) / (2 * a);
            cout << ans;
        } else {
            cout << "решений нет";
        }
    }
    
}   