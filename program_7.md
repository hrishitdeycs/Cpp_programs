 # Write a program to calculate GCD of two numbers 
 # (i) with recursion 
 ```bash
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
![Screenshot (93)](https://github.com/user-attachments/assets/783c6f27-a401-4501-8800-f0097c4c4d71)
![Screenshot (95)](https://github.com/user-attachments/assets/5382b964-2659-45e8-b72f-3043fb168788)


 # (ii) without recursion.
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

```
![Screenshot (94)](https://github.com/user-attachments/assets/29b148f3-1726-4c6e-b81f-b867ccd570c2)
![Screenshot (96)](https://github.com/user-attachments/assets/591d6df7-5e75-4ff3-8903-bca3e2328a20)

