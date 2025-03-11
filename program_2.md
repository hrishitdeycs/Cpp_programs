# Write a program to remove the duplicates from an array.
```bash
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
void removeDuplicates(int arr[], int& n) {
    // Use an unordered set to store unique elements
    unordered_set<int> uniqueElements;
    int index = 0; // Index to keep track of the new array without duplicates
    for (int i = 0; i < n; i++) {
        // If the element is not already in the set, add it
        if (uniqueElements.find(arr[i]) == uniqueElements.end()) {
            uniqueElements.insert(arr[i]);
            arr[index++] = arr[i]; // Place the unique element in the array
        }
    }
    // Update the size of the array to reflect the new size after removing duplicates
    n = index;
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int n;
    // Input the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    // Input the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Remove duplicates
    removeDuplicates(arr, n);
    // Output the array after removing duplicates
    cout << "Array after removing duplicates: ";
    printArray(arr, n);
    return 0;
}
```
![Screenshot (64)](https://github.com/user-attachments/assets/6527a2de-1beb-4085-8b7a-f13a8496ee69)
![Screenshot (65)](https://github.com/user-attachments/assets/f15fea1f-efe1-4b9a-aa17-b6a538618273)
![Screenshot (66)](https://github.com/user-attachments/assets/8d56fe56-60eb-406e-aa8b-16b7fd6547f3)

