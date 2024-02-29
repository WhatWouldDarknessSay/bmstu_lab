#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

struct City{
    string Name;
    double AverageTemperature;
    int month;
    double AmountOfFallout;

};
bool compare(const City& a, const City& b) {
    return a.Name < b.Name;
}


int main(){
    City cities [] ={
        {"City1", 1.0, 1, 10.0},
        {"City2", 2.0, 2, 20.0},
        {"City4", 4.0, 4, 40.0},
        {"City3", 3.0, 3, 30.0},
    };
    int n = 4;
    // запись в файл
    FILE* file= fopen("3.bin", "wb");
    fwrite(cities, sizeof *cities, n, file);
    fclose(file);
    //чтение
    City cities2[n];
    FILE* file2 = fopen("3.bin", "rb");
    const size_t ret_code = fread(cities2, sizeof cities2[0], n, file2);
    sort(cities, cities + sizeof(cities) / sizeof(cities[0]), compare);
    if (ret_code == n){
        for (int i = 0; i < n; i++){
            cout << cities[i].Name << " " << cities[i].AverageTemperature << " " << cities[i].month << " " << cities[i].AmountOfFallout << endl;
        }
        cout << "введите название города: ";
        string in_name;
        cin >> in_name;
        for (int i = 0; i < n; i++){
            if (cities[i].Name == in_name){
                cout << cities[i].Name << " " << cities[i].AverageTemperature << " " << cities[i].month << " " << cities[i].AmountOfFallout << endl;
            }
        }
    }
    fclose(file2);
    return 0;
}
