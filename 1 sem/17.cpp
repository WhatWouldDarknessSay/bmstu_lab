#include<iostream>
using namespace std;

template<class TypeOfElement>
class MyVector{
public:
    MyVector(){
        length = 0;
        capacity = 1;
        dataPointer = new TypeOfElement[1];
    }

    ~MyVector(){
        delete[] dataPointer;
    }
                                    
    MyVector(const MyVector &rhs) {
        capacity = rhs.Capacity();
        dataPointer = new TypeOfElement[capacity];
        for (int i = 0; i < capacity; i++) {
            dataPointer[i] = rhs.At(i);
        }
    }

    MyVector &operator=(const MyVector &rhs) {
        if (this != &rhs) {
            delete[] dataPointer;
            capacity = rhs.Capacity();
            dataPointer = new TypeOfElement[capacity];
            for (int i = 0; i < capacity; i++) {
                dataPointer[i] = rhs.At(i);
            }
            length = capacity;
        }
        return *this;
    }

    void PushBack (TypeOfElement newElement){ 
        TypeOfElement* temp;
        if (capacity <= length){ // если недостаточно логической длины, то копируем массив и заменяем его
            UpCapacity(capacity + 1);
        }
        dataPointer[length] = newElement;
        length += 1;
    }

    TypeOfElement &operator[] (int index) {return dataPointer[index];}
    const TypeOfElement &At (int index) const {return dataPointer[index];}
    bool IsEmpty () const {return length == 0;}
    int Length () const {return length;}
    int Capacity () const{return capacity;}

    MyVector operator+ (const MyVector &rhs) const {
        MyVector<TypeOfElement> result;
        result.UpCapacity(Capacity() + rhs.Capacity()); 
        for(int i = 0; i < Capacity(); i++) result.PushBack(At(i)); 
        for(int i = 0; i < rhs.Capacity(); i++) result.PushBack(rhs.At(i)); 
        return result;
};


private:
    int length, capacity;
    TypeOfElement *dataPointer;

    void UpCapacity (int newCapacity){
        TypeOfElement* temp;
        capacity = newCapacity;
        temp = new TypeOfElement[newCapacity];
        for(int i = 0; i < length; i++){
            temp[i] = dataPointer[i];
        }
        delete[] dataPointer;
        dataPointer = temp;
    }
};
template<class TypeOfElement>
void InputMyVector (MyVector<TypeOfElement> &inVector, int N){
    TypeOfElement tmp;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        inVector.PushBack(tmp);
    }
}
template<class TypeOfElement>
void OutputMyVector (const MyVector<TypeOfElement> &outVector){
    for(int i = 0; i < outVector.Length(); i++) cout << outVector.At(i) << " ";
}

template<class MyType>
void MySwap (MyType &element1, MyType & element2) {
    MyType element3 = element1;
    element1 = element2;
    element2 = element3;
}

int main(){
    MyVector<char> vec1, vec2, vec3;
    InputMyVector(vec1, 5);
    InputMyVector(vec2, 5);
    MySwap (vec1, vec2);
    vec3 = vec1 + vec2;
    OutputMyVector(vec3);
}