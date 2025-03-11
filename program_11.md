#  Create a class Student containing fields for Roll No., Name, Class, Year and Total Marks. Write a program to store 5 objects of Student class in a file. Retrieve these  records from the file and display them.
```bash
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student {
private:
    int rollNo;
    string name;
    string studentClass;
    int year;
    float totalMarks;
public:
    // Constructor to initialize a Student object
    Student(int r, string n, string c, int y, float t) 
        : rollNo(r), name(n), studentClass(c), year(y), totalMarks(t) {}
    // Method to write student details to a file
    void writeToFile(ofstream &file) {
        file << rollNo << endl;
        file << name << endl;
        file << studentClass << endl;
        file << year << endl;
        file << totalMarks << endl;
    }
    // Method to read student details from a file
    void readFromFile(ifstream &file) {
        file >> rollNo;
        file.ignore();  // Ignore the newline character after reading rollNo
        getline(file, name);
        getline(file, studentClass);
        file >> year;
        file >> totalMarks;
    }
    // Method to display the student's information
    void display() const {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Year: " << year << endl;
        cout << "Total Marks: " << totalMarks << endl;
    }
};
int main() {
    // File to store student records
    ofstream outFile("students.txt");
    // Check if the file is opened successfully
    if (!outFile) {
        cerr << "File could not be opened for writing!" << endl;
        return 1;
    }
    // Create 5 Student objects
    Student s1(1, "Alice", "Math", 2023, 450);
    Student s2(2, "Bob", "Science", 2023, 400);
    Student s3(3, "Charlie", "History", 2023, 480);
    Student s4(4, "David", "English", 2023, 470);
    Student s5(5, "Eve", "Computer Science", 2023, 490);
    // Write student details to the file
    s1.writeToFile(outFile);
    s2.writeToFile(outFile);
    s3.writeToFile(outFile);
    s4.writeToFile(outFile);
    s5.writeToFile(outFile);
    // Close the file after writing
    outFile.close();
    // Read and display the student records from the file
    ifstream inFile("students.txt");
    // Check if the file is opened successfully
    if (!inFile) {
        cerr << "File could not be opened for reading!" << endl;
        return 1;
    }
    cout << "\nStudent records retrieved from file:\n";
    // Create a Student object to read data into
    Student tempStudent(0, "", "", 0, 0);
    // Read and display all 5 student records from the file
    for (int i = 0; i < 5; ++i) {
        tempStudent.readFromFile(inFile);
        tempStudent.display();
        cout << "-------------------------------\n";
    }
    // Close the file after reading
    inFile.close();
    return 0;
}

```
![Screenshot (111)](https://github.com/user-attachments/assets/78413c74-62b5-4f1f-8b5a-ab19b186f069)
![Screenshot (112)](https://github.com/user-attachments/assets/966af1bb-1089-4685-9e2e-70a5bc110503)


![Screenshot (109)](https://github.com/user-attachments/assets/37cee36f-1de9-4146-82ef-78cd8779441d)
![Screenshot (110)](https://github.com/user-attachments/assets/381bd946-f833-4164-b0a2-f0915d5be8b2)
