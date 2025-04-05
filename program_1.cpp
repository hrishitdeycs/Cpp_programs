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
