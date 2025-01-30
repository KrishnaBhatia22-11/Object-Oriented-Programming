#include<iostream>
#include<string>
using namespace std;

class Student {
    public:
    string name;
    int age;

    void displayDetails() {
        cout << "Student Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    Student student1;
    
    student1.name = "Alice";
    student1.age = 20;

    student1.displayDetails();

    return 0;
}
