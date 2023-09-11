#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long a, b, c, r, d, ans1x, ans1y, ans2x, ans2y;
    cout <<"Расчет точек пересечения Ax + By = C и x²+y²=R²" << endl << "Введите коэффициент A";
    cin >> a;
    cout << "Введите коэффициент B";
    cin >> b;
    cout << "Введите коэффициент C";
    cin >> c;
    cout << "Введите коэффициент R";
    cin >> r;
    d = 4 * pow(b, 2) * pow(c, 2) + 4 * (pow(b, 2) + pow(a, 2)) * pow(r, 2) * pow(a, 2);
    cout << d << endl;
    if (d > 0) {
        ans1y = (2 * b * c + sqrt(d)) / (2 * (pow(b, 2) + pow(a, 2)));
        ans2y = (2 * b * c - sqrt(d)) / (2 * (pow(b, 2) + pow(a, 2)));
        ans1x = (c - b * ans1y) / a;
        ans2x = (c - b * ans2y) / a;
        cout << "(" << ans1x << "," << ans1y << ")" << endl << "(" << ans2x << "," << ans2y << ")" << endl;
    } else if(d == 0) {
        ans1y = (2 * b * c + sqrt(d)) / (2 * (pow(b, 2) + pow(a, 2)));
        ans1x = (c - b * ans1y) / a;
        cout << "(" << ans1x << "," << ans1y << ")" << endl;
    } else {
        cout << "Пересечений нет" << endl;
    };
    return 0;
}