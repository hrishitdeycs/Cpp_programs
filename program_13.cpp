
#include <iostream>
#include <stdexcept> // For exception handling
using namespace std;
int main() {
    double p, q;
    // Taking input for p and q
    cout << "Enter two numbers (p and q): ";
    cin >> p >> q;
    try {
        // If q is zero, throw an exception
        if (q == 0) {
            throw runtime_error("Error: Division by zero is not allowed.");
        }
        // Perform the division and display the result
        double result = p / q;
        cout << "Result of " << p << " / " << q << " = " << result << endl;
    }
    catch (const runtime_error& e) {
        // Catch and handle the exception
        cout << e.what() << endl;
    }
    return 0;
}


