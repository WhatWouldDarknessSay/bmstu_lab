#include <iostream>
using namespace std;


typedef int (*CompareFunctionType)(void *, void *);
int CompareInt0to9(void *first_pointer, void *second_pointer ) {
    int *first_element_int_pointer = (int *)first_pointer;
    int *second_element_int_pointer = (int *)second_pointer;
    return *first_element_int_pointer - *second_element_int_pointer;
}
int CompareInt9to0(void *first_pointer, void *second_pointer ) {
    int *first_element_int_pointer = (int *)first_pointer;
    int *second_element_int_pointer = (int *)second_pointer;
    return *second_element_int_pointer - *first_element_int_pointer;
}
int CompareCharAtoZ(void *first_pointer, void *second_pointer ) {
    char *first_element_int_pointer = (char *)first_pointer;
    char *second_element_int_pointer = (char *)second_pointer;
    return *first_element_int_pointer - *second_element_int_pointer;
}
int CompareCharZtoA(void *first_pointer, void *second_pointer ) {
    char *first_element_int_pointer = (char *)first_pointer;
    char *second_element_int_pointer = (char *)second_pointer;
    return *second_element_int_pointer - *first_element_int_pointer;
}

void InputArrayInt(int data[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
}
void InputArrayChar(char data[], int n){
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
}

int FindMinimumIndex(void *data_array, int width, CompareFunctionType compare_function_pointer, int first_index, int last_index) {
    // cout << data_array[first_index];
    char *bytevise_array = (char *)data_array;
    int minimum_index = first_index;
    int minimum_byte_number = minimum_index * width;
    int current_byte_number = 0;
    for (int element_number = first_index; element_number < last_index; element_number++) {
        current_byte_number = element_number * width;
        if ((*compare_function_pointer)(&bytevise_array[current_byte_number], &bytevise_array[minimum_byte_number]) < 0) {
            minimum_byte_number = current_byte_number;
        }
    }
    minimum_index = minimum_byte_number / width;
    cout << "minn:" << minimum_index;
    return minimum_index;
}
void SwapChar(char *first_pointer, char *second_pointer) {
    char temp = *first_pointer;
    *first_pointer = *second_pointer;
    *second_pointer = temp;
}
void Swap(void *first_pointer, void *second_pointer, int width) {
    cout << *(char*)first_pointer << " " << *(char*)second_pointer << "\t";
    for (int byte_number = 0; byte_number < width; byte_number++) {
        SwapChar((char *)first_pointer + byte_number, (char *)second_pointer + byte_number);
    }
}



void SelectionSort(void *data_array, int length, int width, CompareFunctionType compare_function_pointer){
    for (int i = 0; i < length; i++) {
        cout << *(char *)data_array;
        Swap(((char *)data_array) + (i) * width, (char *)data_array + FindMinimumIndex(data_array, width, compare_function_pointer, i, length) * width, width);
    }
}


void OutputArrayInt(int data[], int n) {
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
void OutputArrayChar(char data[], int n) {
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
  
int main() {
    bool sort_flag;
    cout << "0 - по возрастанию, 1 - по убыванию: ";
    cin >> sort_flag;

    const int kNumberOfCompareFunctions = 2;
    int CompareInt0to9(void *first_pointer, void *second_pointer);
    int CompareInt9to0(void *first_pointer, void *second_pointer);
    int CompareCharAtoZ(void *first_pointer, void *second_pointer);
    int CompareCharZtoA(void *first_pointer, void *second_pointer);
    CompareFunctionType compare_function_pointers[kNumberOfCompareFunctions];
    CompareFunctionType compare_function_pointers_char[kNumberOfCompareFunctions];
    compare_function_pointers[0] = CompareInt0to9;
    compare_function_pointers[1] = CompareInt9to0;
    compare_function_pointers_char[0] = CompareCharAtoZ;
    compare_function_pointers_char[1] = CompareCharZtoA;

    int N, M;
    cin >> N >> M;
    int data_int[N];
    char data_char[M];
    InputArrayInt(data_int, N);
    InputArrayChar(data_char, M);

    sort_flag ? SelectionSort((void *)data_int, N, 4, compare_function_pointers[1]) : SelectionSort((void *)data_int, N, 4, compare_function_pointers[0]);
    sort_flag ? SelectionSort((void *)data_char, M, 1, compare_function_pointers_char[1]) : SelectionSort((void *)data_char, M, 1, compare_function_pointers_char[0]);
    

    OutputArrayInt(data_int, N);
    OutputArrayChar(data_char, M);
}
