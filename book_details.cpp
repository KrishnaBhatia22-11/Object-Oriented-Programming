#include<iostream>
#include<string>
using namespace std;

class Book {
    public:
    string title;
    string author;
    double price;

    void displayDetails() {
        cout << "Book Details:" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {
    Book book1;
    
    book1.title = "The Great Gatsby";
    book1.author = "F. Scott Fitzgerald";
    book1.price = 10.99;

    book1.displayDetails();

    return 0;
}
