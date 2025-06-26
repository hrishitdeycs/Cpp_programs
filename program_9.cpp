
#include <iostream>
#include <string>
using namespace std;
// Base class Person
class Person {
protected:
    string name; // Data member to store name
public:
    // Constructor to initialize the name
    Person(string n) : name(n) {}
    // Virtual function for runtime polymorphism
    virtual void display() {
        cout << "Name: " << name << endl;
    }
    // Destructor (virtual to ensure proper cleanup in derived classes)
    virtual ~Person() {}
};
// Derived class Student
class Student : public Person {
private:
    string course;
    float marks;
    int year;
public:
    // Constructor to initialize attributes
    Student(string n, string c, float m, int y) : Person(n), course(c), marks(m), year(y) {}
    // Overriding display method to show Student's attributes
    void display() override {
        cout << "Student Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Marks: " << marks << endl;
        cout << "Year: " << year << endl;
    }
};
// Derived class Employee
class Employee : public Person {
private:
    string department;
    float salary;
public:
    // Constructor to initialize attributes
    Employee(string n, string d, float s) : Person(n), department(d), salary(s) {}
    // Overriding display method to show Employee's attributes
    void display() override {
        cout << "Employee Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};
// Main function
int main() {
    // Creating objects of Student and Employee classes
    Person* p1 = new Student("Alice", "Computer Science", 88.5, 2);
    Person* p2 = new Employee("Bob", "IT", 50000);
    // Displaying the details using runtime polymorphism
    cout << "Displaying Student details:" << endl;
    p1->display();
    cout << "\nDisplaying Employee details:" << endl;
    p2->display();
    // Cleaning up the dynamically allocated memory
    delete p1;
    delete p2;
    return 0;
}

