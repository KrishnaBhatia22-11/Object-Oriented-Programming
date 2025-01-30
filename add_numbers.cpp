#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    std::cout << "Sum = " << add(num1, num2) << std::endl;
    return 0;
}
