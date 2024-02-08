#include<iostream>
#include<cmath>
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

const char DefaultVehicleName[] = "Untyped vehicle";
const char DefaultCoachName [] = "Default Coach";
const char DefaultAutomobileName [] = "Default Automobile";
const char DefaultAeroplaneName [] = "Default Aeroplane";
const double DefaultVehicleSpeed = -1.;
const double DefaultCoachSpeed = 10.;
const double DefaultAutomobileSpeed = 100.;
const double DefaultAeroplaneSpeed = 500.;
const double DefaultTimeToBoot = 0.01;
const int MAX_DISTANCE = 1000;
const int MAX_FLY_TIME = 1000;
const int MAX_RECHARGES = 100;
const int MAX_LITRES = 100;
class Vehicle {
public:
    //Конструктор ТС по умолчанию
    Vehicle () : totalDistance (0), totalTime (0), baseSpeed (DefaultVehicleSpeed) {
        SetName (DefaultVehicleName);
    }
    //Параметризованый конструтор ТС
    Vehicle (const char inNameCString[], double inBaseSpeed) : totalDistance (0), totalTime (0), baseSpeed (inBaseSpeed) {
        SetName (inNameCString);
    }
    //Деструктор ТС
    virtual ~Vehicle () {}
    //Метод получения информации об имени ТС
    const char * const GetName () const {
        return nameCString;
    }
    //Метод получения информации о скорости при покупке
    double GetBaseSpeed () const {
        return baseSpeed;
    }
    //Метод получения информации о текущем пробеге
    double GetTotalDistance () const {
        return totalDistance;
    }
    //Метод получения информации о текущем времени эксплуатации
    double GetTotalTime () const {
        return totalTime;
    }
    //Абстрактный метод совершения поездки
    //Возвращает на true, если поезка удачна и false, если случилась авария.
    virtual bool MakeTrip (double distance) = 0;
    //Абстрактный метод получения информации о текущей скорости
    virtual double GetSpeed () const = 0;
    //Оператор сравнения по умолчанию
    bool operator< (Vehicle &rhs) const {
        if (GetSpeed () < rhs.GetSpeed ()) {
            return true;
        }
        return false;
    }
    //Константа - общее максимальное количество символов в имени ТС
    static const int MAX_NAME_LENGTH = 50;
protected:
    //Счетчик пройденного расстояния
    double totalDistance;
    //Счетчик общего времени эксплуатации
    double totalTime;

    //Метод установки имени транспортного средства
    void SetName (const char inNameCString[]) {
        int i = 0;
        for (i = 0; (inNameCString[i] != 0) && (i < MAX_NAME_LENGTH); ++i) {
            nameCString [i] = inNameCString [i];
        }
        nameCString [i] = 0;
    }
    //С - строка для хранения имени
    char nameCString [MAX_NAME_LENGTH];
    //Скорость нового транспортного средства
    double baseSpeed;
};

class Computer {
public:
    Computer () : baseTimeToBoot (DefaultTimeToBoot) {}
    double GetTimeToBoot () {
        return baseTimeToBoot;
    }
    double baseTimeToBoot;
};

class Aeroplane : public Vehicle {
public:
    using Vehicle::Vehicle;
    Computer comp;
    int timeSinceLastRepair = 0;
    double GetSpeed () const {
        return GetBaseSpeed ();
    }

    bool MakeTrip (double distanceOfTrip) {
        double timeOfTrip = distanceOfTrip / GetSpeed () + comp.GetTimeToBoot ();
        if (timeSinceLastRepair + timeOfTrip > MAX_FLY_TIME) {
        return false;
        }
        timeSinceLastRepair += timeOfTrip;
        totalDistance += distanceOfTrip;
        totalTime += timeOfTrip;
        return true;
    }
    void Repair () {
        timeSinceLastRepair = 0;
    }
    double GetTimeSinceLastRepair () const {
        return timeSinceLastRepair;
    }
    void ComputerUpdate (double newTimeToBoot) {
        comp.baseTimeToBoot = newTimeToBoot;
    }
};

class Coach: public Vehicle{
public:
    using Vehicle::Vehicle;
    double GetSpeed () const {
        return GetBaseSpeed () * exp(-totalTime / 500.);
    }
    bool MakeTrip (double distanceOfTrip) {
        if (totalDistance + distanceOfTrip > MAX_DISTANCE){
            return false;
        }
        double timeOfTrip = distanceOfTrip / GetSpeed ();
        totalDistance += distanceOfTrip;
        totalTime += timeOfTrip;
        return true; 
    }

};

class Automobile: public Vehicle{
public:
    using Vehicle::Vehicle;
    double GetSpeed () const {
        return GetBaseSpeed () * exp(-totalDistance / 500.);
    }
};  

class Battery {
public:
    bool recharge(){
        if (totalRecharge >= MAX_RECHARGES){
            return false;
        }
        totalRecharge += 1;
        percentage = 100;
    }
    void zeroRecharge(){totalRecharge = 0; percentage = 100;}
    void runBattery(double percent){ percentage -= percent;}
    double getPersentage(){return percentage;}
    double getTotalRecharge(){return totalRecharge;}
private:
    double percentage = 100.;
    int totalRecharge = 0;
};

class ElectricCar: public Automobile{
public:
    using Automobile::Automobile;
    Battery battery;
    bool MakeTrip (double distanceOfTrip) {
        double timeOfTrip = distanceOfTrip / GetSpeed ();
        if (battery.getPersentage() * 100 < distanceOfTrip){
            return false;
        }
        totalDistance += distanceOfTrip;
        totalTime += timeOfTrip;
        battery.runBattery(distanceOfTrip * 0.01);
        return true;
    }
    void ChangeBattery(){
        battery.zeroRecharge();
    }
    void rechargeBattery(){battery.recharge();}
};

class Tank{
public:
    bool fill(int litres){
        if(value + litres > MAX_LITRES){
            return false;
        }
        value += litres;
        return true;
    }
    void runTank(double percent){ value -= percent;}
    double getValue(){return value;}
private:
    double value = 100.;
};

class FuelCar: public Automobile{
public:
    using Automobile::Automobile;
    Tank tank;
    bool MakeTrip (double distanceOfTrip) {
        double timeOfTrip = distanceOfTrip / GetSpeed ();
        if (tank.getValue() * 100 < distanceOfTrip){
            return false;
        }
        totalDistance += distanceOfTrip;
        totalTime += timeOfTrip;
        tank.runTank(distanceOfTrip * 0.01);
        return true;
    }
};

void CommitRandomTrips (MyVector<Vehicle *> &vehicles) {
    for (int i = 0; i < vehicles.Length (); ++i) {
        double randomDistance = double(rand() % 20001) / 10.;
        vehicles[i]->MakeTrip (randomDistance);
    }
};

void DisplayVehicles (MyVector<Vehicle *> &vehicles) {
    printf("%s \t%s\t%s\t%s\n", "Name", "Speed", "Dist", "Time");
    for (int i = 0; i < vehicles.Length (); ++i) {
        printf("%s \t%6.2lf\t%7.2lf\t%6.2lf\n", vehicles.At(i)->GetName(), vehicles.At(i)->GetSpeed (), vehicles.At(i)->GetTotalDistance (), vehicles.At(i)->GetTotalTime ());
    }
}

template <class MyType>
void MySwap (MyType &v1, MyType &v2) {

    MyType v3 = v1;
    v1 = v2;
    v2 = v3;
}
template <class ArrayType, class LessFunctionType>
int FindMinimumIndex (ArrayType &data_array, int beginIndex, int endIndex, LessFunctionType LessFunction) {
    int minimumIndex = beginIndex;
    for (int element_number = beginIndex + 1; element_number <= endIndex; ++element_number) {
        if (LessFunction (data_array[element_number], data_array[minimumIndex])) {
            minimumIndex = element_number;
        }
    }
    return minimumIndex;
}
template <class ArrayType, class LessFunctionType>
void SelectionSort (ArrayType &data_array, int beginIndex, int endIndex, LessFunctionType LessFunction) {
    for (int element_number = beginIndex; element_number < endIndex; ++element_number) {
        int minimumIndex = FindMinimumIndex (data_array, element_number, endIndex, LessFunction);
        MySwap (data_array[minimumIndex], data_array[element_number]);
    }
}
bool CompareDefault (Vehicle *lhs, Vehicle *rhs) {
    return *lhs < *rhs;
}
bool CompareTime (Vehicle *lhs, Vehicle *rhs) {
    return lhs->GetTotalTime () < rhs->GetTotalTime ();
}
bool CompareSpeed (Vehicle *lhs, Vehicle *rhs) {
    return lhs->GetSpeed () < rhs->GetSpeed ();
}


int main(){
    srand(0);
    //Векторы для хранения экземпляров ТС
    MyVector<Coach> coaches;
    MyVector<ElectricCar> automobiles;
    MyVector<FuelCar> fuelcars;
    MyVector<Aeroplane> aeroplanes;
    //Добавление конкретных объектов
    coaches.PushBack (Coach ("Coach 1", 9.));
    automobiles.PushBack (ElectricCar ("Electric 1", 90.));
    fuelcars.PushBack (FuelCar ("Fuel car 1", 90.));
    aeroplanes.PushBack (Aeroplane ("Aeroplane 1", 1030.));
    // //Векторы указателей на объекты
    
    MyVector<Vehicle *> coachPointers;
    MyVector<Vehicle *> automobilePointers;
    MyVector<Vehicle *> aeroplanePointers;
    MyVector<Vehicle *> fuelPointers;
    //Инициализация векторов указателей
    for (int i = 0; i < coaches.Length (); ++i) {

        coachPointers.PushBack (&coaches[i]);
    }
    for (int i = 0; i < automobiles.Length (); ++i) {
        automobilePointers.PushBack (&automobiles[i]);

    }
    for (int i = 0; i < aeroplanes.Length (); ++i) {
        aeroplanePointers.PushBack (&aeroplanes[i]);

    }
    for (int i = 0; i < fuelcars.Length (); ++i) {
        fuelPointers.PushBack (&fuelcars[i]);

    }
    MyVector<Vehicle *> vehiclePointers = coachPointers + automobilePointers + aeroplanePointers + fuelPointers;
    CommitRandomTrips(vehiclePointers);
    SelectionSort(vehiclePointers, 0, vehiclePointers.Length() - 1, CompareSpeed);
    DisplayVehicles(vehiclePointers);
    return 0;
}