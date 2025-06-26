```bash
#include <iostream>
using namespace std;
// Function for binary search with recursion
int binarySearchRecursive(int arr[], int low, int high, int target) {
    // Base case: element is not found
    if (low > high) {
        return -1;
    }
    // Find the middle element
    int mid = low + (high - low) / 2;
    // Check if the target is at the middle
    if (arr[mid] == target) {
        return mid;
    }
    // If target is smaller, search in the left half
    else if (arr[mid] > target) {
        return binarySearchRecursive(arr, low, mid - 1, target);
    }
    // If target is larger, search in the right half
    else {
        return binarySearchRecursive(arr, mid + 1, high, target);
    }
}
int main() {
    int n, target;
    // Input the number of elements
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    // Input the sorted elements
    cout << "Enter the sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Input the target element to search for
    cout << "Enter the element to search for: ";
    cin >> target;
    // Binary search with recursion
    int resultRecursive = binarySearchRecursive(arr, 0, n - 1, target);
    if (resultRecursive != -1) {
        cout << "Element found at index (recursive): " << resultRecursive << endl;
    } else {
        cout << "Element not found (recursive)." << endl;
    }
    return 0;
}
```
