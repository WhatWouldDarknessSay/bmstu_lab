#include<iostream>
using namespace std;
void nonrec(int n, int m){
    for (int i = n; i <= m; i++){
        if(i % 6 == 0){
            cout << i << " ";
        }
    }
}
void rec(int n, int m){
    if (n <= m){
        if (n % 6 == 0){
            cout << n << " ";
            rec(n + 6, m);
        } else {
            rec(n + 1, m);
        }
    }
    
}
int main(){
    int n, m;
    cin >> n >> m;
    nonrec(n, m);
    cout << "\n";
    rec(n, m);
}
