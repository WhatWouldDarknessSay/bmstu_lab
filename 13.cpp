#include<iostream>
#include<cmath>
using namespace std;

const int n = 3;
const int m = 3;

template<typename T>
void input_matrix(T matrix, int m, int n) {
    cout << "введите матрицу " << endl;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
        
    }
}

template<typename T>
void output_matrix(T matrix, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            cout << matrix[i][j] << '\t';
        }
        int max_len = 0, max_prod = 1, cur_len = 0, cur_prod = 1; 
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < 0) { 
                cur_len++;
                cur_prod *= matrix[i][j];
            } else { 
                if (cur_len > max_len) {
                    max_len = cur_len;
                    max_prod = cur_prod;
                }
                cur_len = 0;
                cur_prod = 1;
            }
        }
        if (cur_len > max_len) {
            max_len = cur_len;
            max_prod = cur_prod;
        }
        if (max_len == 0) {
            max_prod = 0;
        }
        cout << " длина = " << max_len << ", произведение = " << max_prod << "\n";
    }
}

int main(){
    double static_matrix[n][m], **dynamic_matrix = new double*[m];

    for (int i = 0; i < m; i++){
        dynamic_matrix[i] = new double[n];
    }
    input_matrix(static_matrix, m, n);
    input_matrix(dynamic_matrix, m, n);

    output_matrix(static_matrix, m, n);
    output_matrix(dynamic_matrix, m, n);
}