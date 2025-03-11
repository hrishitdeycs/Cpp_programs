# Write a program to merge two ordered arrays to get a single ordered array.
```bash
#include <iostream>
using namespace std;
// Function to merge two sorted arrays into a single sorted array
void mergeArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0, j = 0, k = 0;
    // Merge the two arrays while both arrays have elements
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    // If there are remaining elements in arr1, add them
    while (i < n1) {
        merged[k++] = arr1[i++];
    }
    // If there are remaining elements in arr2, add them
    while (j < n2) {
        merged[k++] = arr2[j++];
    }
}
// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int n1, n2;
    // Input the size and elements of the first array
    cout << "Enter the size of the first array: ";
    cin >> n1;
    int arr1[n1];
    cout << "Enter the elements of the first array in sorted order: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    // Input the size and elements of the second array
    cout << "Enter the size of the second array: ";
    cin >> n2;
    int arr2[n2];
    cout << "Enter the elements of the second array in sorted order: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }
    // Create an array to hold the merged result
    int merged[n1 + n2];
    // Merge the arrays
    mergeArrays(arr1, n1, arr2, n2, merged);
    // Output the merged array
    cout << "Merged array: ";
    printArray(merged, n1 + n2);
    return 0;
}
```
![Screenshot (84)](https://github.com/user-attachments/assets/90237e63-c6bc-4755-bca2-5ae174be8ce3)
![Screenshot (85)](https://github.com/user-attachments/assets/d0aa2938-0cbc-4b16-93ea-3324dee567a9)
![Screenshot (86)](https://github.com/user-attachments/assets/610cc96e-dc57-4b27-a667-2fa2ccb427ba)

