 
#include <iostream>
using namespace std;
// Recursive function to calculate GCD using Euclidean algorithm
int gcdRecursive(int a, int b) {
    // Base case: If b is 0, the GCD is a
    if (b == 0) {
        return a;
    }
    // Recursive case: Call gcd on b and the remainder of a divided by b
    return gcdRecursive(b, a % b);
}
int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    int result = gcdRecursive(a, b);
    cout << "GCD of " << a << " and " << b << " is: " << result << endl;
    return 0;
}
```
```bash
#include <iostream>
using namespace std;
// Iterative function to calculate GCD using Euclidean algorithm
int gcdIterative(int a, int b) {
    // Keep applying the Euclidean algorithm until b becomes 0
    while (b != 0) {
        int temp = b;
        b = a % b; // Find remainder
        a = temp;  // Update a to b's value
    }
    return a; // When b becomes 0, a is the GCD
}
int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    int result = gcdIterative(a, b);
    cout << "GCD of " << a << " and " << b << " is: " << result << endl;
    return 0;
}


