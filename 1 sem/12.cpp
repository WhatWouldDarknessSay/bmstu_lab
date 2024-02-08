#include<iostream>
#include<cmath>
using namespace std;
int main(){
    long long data[25] = {-8, 17, -14, 5, -3, 12, -20, 9, -11, 4, -18, 15, -6, 7, -13, 10, -16, 3, -9, 14, -4, 11, -19, 6, -2}, a, b, counter = 0, ans1 = 2, summ = 0;
    bool flag1 = false, flag2 = false;
    cout << "Введите число для положительных: ";
    cin >> a;
    cout << "Введите число для отрицательных: ";
    cin >> b;
    for (int i = 0; i < 25; i++){
        if (data[i] > 0 && data[i] % a == 0){
            counter += 1;
            ans1 = ans1 * data[i];
            flag1 = true;
            cout << data[i];
        } else if (data[i] < 0 && data[i] % b == 0){
            summ += data[i];
            flag2 = true;
        }
        cout << data[i] << " ";
    }
    flag1 == true ? cout << endl << "среднее геометрическое: " << pow(ans1, 1.0 / counter) : cout << "\nнет подходящих чисел для среднего геометрического";
    flag2 == true ? cout << endl << "сумма: " << summ : cout << "\nнет подходящих чисел для суммы";

}