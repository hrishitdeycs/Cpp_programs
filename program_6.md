# Write a program to search a given element in a set of N numbers using Binary search
# (i) with recursion 
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
![Screenshot (87)](https://github.com/user-attachments/assets/7bd7ebb6-df93-4932-8c99-c4c63426346a)
![Screenshot (88)](https://github.com/user-attachments/assets/09dd9676-f098-40d1-971e-b6abe62411e4)
![Screenshot (91)](https://github.com/user-attachments/assets/25fc87ca-47e3-4f19-a557-c3854f476fa2)

# (ii) without recursion.
```bash
#include <iostream>
using namespace std;
// Function for binary search without recursion
int binarySearchIterative(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    // Continue searching while the range is valid
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // Check if the target is at the middle
        if (arr[mid] == target) {
            return mid;
        }
        // If target is smaller, search in the left half
        else if (arr[mid] > target) {
            high = mid - 1;
        }
        // If target is larger, search in the right half
        else {
            low = mid + 1;
        }
    }
    // If the element is not found, return -1
    return -1;
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
    // Binary search without recursion
    int resultIterative = binarySearchIterative(arr, n, target);
    if (resultIterative != -1) {
        cout << "Element found at index (iterative): " << resultIterative << endl;
    } else {
        cout << "Element not found (iterative)." << endl;
    }
    return 0;
}

```
![Screenshot (89)](https://github.com/user-attachments/assets/f82c44a4-cdbe-4c74-ae3a-2b1f6751a2b0)
![Screenshot (90)](https://github.com/user-attachments/assets/5245f330-4fb9-4435-a0ac-8bd2bd1d2303)
![Screenshot (92)](https://github.com/user-attachments/assets/806a8b54-3967-4a9c-b0fe-13ec6c645716)
