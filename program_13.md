# Write a program to read two numbers p and q . If q is 0 then throw an exception else display the result of p/q.
```bash
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

```
![Screenshot (115)](https://github.com/user-attachments/assets/c7a9cfc0-0d2e-43d9-ac95-5ffba984d44c)
![Screenshot (116)](https://github.com/user-attachments/assets/8faa499b-c449-44d0-8cce-864c040f95ff)
