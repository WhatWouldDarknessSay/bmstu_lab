#include<iostream>
using namespace std;

unsigned long long compare_counter = 0;
unsigned long long copy_counter = 0;

void BubbleUp (double input_data[][2][2], int start_index, int final_index, int &new_border){
    for (int i = start_index; i > final_index; --i){
        compare_counter += 1;
        double iftmp = input_data[i][0][0] * input_data[i][1][1] - input_data[i][0][1] * input_data[i][1][0];
        double iftmppre = input_data[i - 1][0][0] * input_data[i - 1][1][1] - input_data[i - 1][0][1] * input_data[i - 1][1][0];
        if(iftmp < iftmppre){
            for(int n = 0; n < 2; n++){
                for(int m = 0; m < 2; m++){
                    double tmp = input_data[i][n][m];
                    input_data[i][n][m] = input_data[i - 1][n][m];
                    input_data[i - 1][n][m] = tmp;
                }
            }
            new_border = i;
            copy_counter += 3;
        }
    }
}

int main(){
    int current_border = 0;
    int N = 3;
    double X[N][2][2] = {{{1, 1}, {1, 2}}, {{1, 2}, {1, 1}}, {{3, 7}, {-6, 4}}};
    while (current_border < N) {
        int new_border = N;
        BubbleUp(X, N-1, current_border, new_border);
        if(new_border == N){
            break;
        }

        current_border = new_border;
    }
    for(int i = 0; i < N; i++) cout << X[i][0][0] << " " << X[i][0][1] << "\t";
    cout << "\n";
    for(int i = 0; i < N; i++) cout << X[i][1][0] << " " << X[i][1][1] << "\t";
}