#include <iostream>
using namespace std;



typedef int (*CompareFunctionType)(void *, void *);
int CompareInt0to9(void *first_pointer, void *second_pointer ) {
    int *first_element_int_pointer = (int *)first_pointer;
    int *second_element_int_pointer = (int *)second_pointer;
    return *first_element_int_pointer - *second_element_int_pointer;
}
typedef int (*CompareFunctionType)(void *, void *);
int CompareInt9to0(void *first_pointer, void *second_pointer ) {
    int *first_element_int_pointer = (int *)first_pointer;
    int *second_element_int_pointer = (int *)second_pointer;
    return *second_element_int_pointer - *first_element_int_pointer;
}


void InputArray(int data[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
}

int FindMinimumIndex(int data[], int l, int r, CompareFunctionType compare_function_pointer) {
    int minn = l;
    for (int i = l + 1; i <= r; i++) {
        if ((*compare_function_pointer)(&data[i], &data[minn]) < 0) {
            minn = i;
        }
    }
    return minn;
}

void Swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void SelectionSort(int data[], int n, CompareFunctionType compare_function_pointer) {
    for (int i = 0; i <= n; i++) {
        int minn = FindMinimumIndex(data, i, n - 1, &compare_function_pointer);
        Swap(data[i], data[minn]);
    }
}

void OutputArray(int data[], int n) {
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << data[i] << endl;
    }
    cout << endl;
}

int main() {
    // int Compare(void *first_pointer, void *second_pointer);
    const int kNumberOfCompareFunctions = 2;
    int CompareInt0to9(void *first_pointer, void *second_pointer);
    int CompareInt9to0(void *first_pointer, void *second_pointer);
    CompareFunctionType compare_function_pointers[kNumberOfCompareFunctions];
    compare_function_pointers[0] = CompareInt0to9;
    compare_function_pointers[1] = CompareInt9to0;
    int N;
    cin >> N;
    int data[N];
    InputArray(data, N);
    SelectionSort(data, N, compare_function_pointers[0]);
    OutputArray(data, N);
}
