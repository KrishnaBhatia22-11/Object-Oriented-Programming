#include<iostream>
#include<string>
using namespace std;

class Car {
    public:
    string brand;
    string model;
    int year;
};

int main() {
    Car car1;
    
    car1.brand = "Toyota";
    car1.model = "Corolla";
    car1.year = 2020;

    cout << "Car Details:" << endl;
    cout << "Brand: " << car1.brand << endl;
    cout << "Model: " << car1.model << endl;
    cout << "Year: " << car1.year << endl;

    return 0;
}
