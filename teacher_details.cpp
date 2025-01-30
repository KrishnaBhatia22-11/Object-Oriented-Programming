#include<iostream>
#include<string>
using namespace std;

class Teacher {
    public:
    string name;
    int age;
    string department;
    double salary;
};

int main () {
    Teacher t1;
    t1.name = "John Doe";
    t1.age = 45;
    t1.department = "Computer Science";
    t1.salary = 50000.0;

    cout << "Teacher Details:" << endl;
    cout << "Name: " << t1.name << endl;
    cout << "Age: " << t1.age << endl;
    cout << "Department: " << t1.department << endl;
    cout << "Salary: " << t1.salary << endl;
}
