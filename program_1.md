# Write a program to compute the sum of the first n terms of the following series:
![Screenshot 2025-03-11 113637](https://github.com/user-attachments/assets/9fac2b74-64f5-4418-8db8-26e98a19a2ed)
# The number of terms n is to be taken from the user through the command line.If the command line argument is not found then prompt the user to enter the value of n.
```bash
#include <iostream>
#include <cstdlib> // For handling command-line arguments
using namespace std;
double compute_series_sum(int n) {
    double series_sum = 0.0;    
    // Loop through the first n terms of the series
    for (int i = 1; i <= n; i++) {
        // Alternating signs, (-1)^(i+1)
        if (i % 2 == 1) {
            series_sum += 1.0 / (i * i); // Add for odd terms
        } else {
            series_sum -= 1.0 / (i * i); // Subtract for even terms
        }
    }    
    return series_sum;
}
int main(int argc, char* argv[]) {
    int n;
    // Check if command-line argument is passed
    if (argc > 1) {
        n = atoi(argv[1]);  // Convert the argument to an integer
    } else {
        // Prompt user to input the value of n
        cout << "Enter the number of terms (n): ";
        cin >> n;
    }
    // Compute and print the sum of the series
    double result = compute_series_sum(n);
    cout << "The sum of the first " << n << " terms of the series is: " << result << endl;
    return 0;
}
```
![Screenshot (62)](https://github.com/user-attachments/assets/7724391b-a9d3-4e6e-acd4-c5cf7091ff82)
![Screenshot (63)](https://github.com/user-attachments/assets/06af934f-5d8f-418e-b429-00a9389e7a5b)
