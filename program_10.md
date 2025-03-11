#  Create a Triangle class. Add exception handling statements to ensure the following conditions: all sides are greater than 0 and sum of any two sides are greater than the third side. The class should also have overloaded functions for calculating the area of a right angled triangle as well as using Heron's formula to calculate the area of any type of triangle.Overload equality and assignment operator.
```bash
#include <iostream>
#include <cmath>
#include <stdexcept> // For exception handling
using namespace std;
class Triangle {
private:
    double side1, side2, side3;
public:
    // Constructor to initialize the sides of the triangle
    Triangle(double s1, double s2, double s3) {
        if (s1 <= 0 || s2 <= 0 || s3 <= 0) {
            throw invalid_argument("Sides must be greater than 0.");
        }
        if (s1 + s2 <= s3 || s1 + s3 <= s2 || s2 + s3 <= s1) {
            throw invalid_argument("Sum of any two sides must be greater than the third side.");
        }
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }
    // Function to calculate the area of a right-angled triangle
    double calculateArea() const {
        if (isRightAngled()) {
            double base = side1, height = side2;
            return 0.5 * base * height; // Area of right-angled triangle
        }
        throw invalid_argument("Not a right-angled triangle.");
    }
    // Function to calculate the area using Heron's formula
    double calculateAreaUsingHeronsFormula() const {
        double s = (side1 + side2 + side3) / 2; // Semi-perimeter
        double area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
        return area;
    }
    // Function to check if the triangle is right-angled (using Pythagoras theorem)
    bool isRightAngled() const {
        double a = side1, b = side2, c = side3;
        // Check if the triangle satisfies the Pythagoras theorem
        if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
            return true;
        }
        return false;
    }
    // Overloading the assignment operator
    Triangle& operator=(const Triangle& other) {
        if (this != &other) {
            side1 = other.side1;
            side2 = other.side2;
            side3 = other.side3;
        }
        return *this;
    }
    // Overloading the equality operator
    bool operator==(const Triangle& other) const {
        return (side1 == other.side1 && side2 == other.side2 && side3 == other.side3);
    }
    // Method to display the sides of the triangle
    void display() const {
        cout << "Sides of the triangle: " << side1 << ", " << side2 << ", " << side3 << endl;
    }
};
int main() {
    try {
        // Creating a triangle object
        Triangle t1(3, 4, 5); // Right-angled triangle
        t1.display();
        cout << "Area of the right-angled triangle: " << t1.calculateArea() << endl;
        // Creating another triangle object
        Triangle t2(5, 6, 7); // General triangle
        t2.display();
        cout << "Area using Heron's formula: " << t2.calculateAreaUsingHeronsFormula() << endl;
        // Testing assignment operator
        Triangle t3(0, 0, 0); // Initializing with dummy values
        t3 = t1; // Assignment of t1 to t3
        cout << "\nAfter assignment, t3 is:\n";
        t3.display();
        // Testing equality operator
        if (t1 == t3) {
            cout << "\nt1 and t3 are equal." << endl;
        } else {
            cout << "\nt1 and t3 are not equal." << endl;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}

```
![Screenshot (107)](https://github.com/user-attachments/assets/7982f152-3ff4-4669-b1a8-6367e021d5a7)
![Screenshot (108)](https://github.com/user-attachments/assets/79be1c7a-2fdd-4591-9300-e064e455daa3)

![Screenshot (106)](https://github.com/user-attachments/assets/94e813d5-6821-4fe9-98d9-fa6a98313e93)
