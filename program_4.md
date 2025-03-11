# Write a menu driven program to perform string manipulation (without using inbuilt string functions):
# a. Show address of each character in string
# b. Concatenate two strings.
# c. Compare two strings
# d. Calculate length of the string (use pointers)
# e. Convert all lowercase characters to uppercase
# f. Reverse the string
# g. Insert a string in another string at a user specified position
```bash
#include <iostream>
#include <cstring>
using namespace std;

// Function to show address of each character in the string
void showCharacterAddresses(const char* str) {
    cout << "Addresses of each character in the string:" << endl;
    while (*str != '\0') {
        cout << (void*)str << " -> " << *str << endl;
        str++;
    }
}

// Function to concatenate two strings
void concatenateStrings(char* str1, const char* str2) {
    while (*str1 != '\0') {
        str1++;  // Move to the end of the first string
    }
    while (*str2 != '\0') {
        *str1 = *str2;  // Copy character from str2 to str1
        str1++;
        str2++;
    }
    *str1 = '\0';  // Add null terminator at the end
}

// Function to compare two strings
int compareStrings(const char* str1, const char* str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return (*str1 - *str2);  // Return the difference
        }
        str1++;
        str2++;
    }
    return (*str1 - *str2);  // If one string is shorter, return the difference
}

// Function to calculate the length of the string using pointers
int calculateLength(const char* str) {
    const char* ptr = str;
    int length = 0;
    while (*ptr != '\0') {
        length++;
        ptr++;
    }
    return length;
}

// Function to convert all lowercase characters to uppercase
void convertToUppercase(char* str) {
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - 'a' + 'A';  // Convert to uppercase
        }
        str++;
    }
}

// Function to reverse the string
void reverseString(char* str) {
    int length = calculateLength(str);
    int start = 0, end = length - 1;
    while (start < end) {
        // Swap characters at start and end
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to insert a string at a user-specified position
void insertStringAtPosition(char* str1, const char* str2, int position) {
    int length1 = calculateLength(str1);
    int length2 = calculateLength(str2);
    // Shift the characters of str1 to the right to make space for str2
    for (int i = length1; i >= position; i--) {
        str1[i + length2] = str1[i];
    }
    // Insert str2 into str1 at the specified position
    for (int i = 0; i < length2; i++) {
        str1[position + i] = str2[i];
    }
    str1[length1 + length2] = '\0';  // Null-terminate the string
}

int main() {
    int choice;
    char str1[100], str2[100];
    int position;
    int result; // Declare result here, outside the switch

    do {
        cout << "\nMenu: \n";
        cout << "1. Show address of each character in string\n";
        cout << "2. Concatenate two strings\n";
        cout << "3. Compare two strings\n";
        cout << "4. Calculate length of the string\n";
        cout << "5. Convert all lowercase characters to uppercase\n";
        cout << "6. Reverse the string\n";
        cout << "7. Insert a string in another string at a user-specified position\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore newline left by previous input

        switch (choice) {
            case 1:
                cout << "Enter a string: ";
                cin.getline(str1, 100);
                showCharacterAddresses(str1);
                break;
            case 2:
                cout << "Enter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                concatenateStrings(str1, str2);
                cout << "Concatenated string: " << str1 << endl;
                break;
            case 3:
                cout << "Enter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                result = compareStrings(str1, str2);  // Now `result` is declared before the switch
                if (result == 0) {
                    cout << "The strings are equal." << endl;
                } else if (result < 0) {
                    cout << "The first string is lexicographically smaller." << endl;
                } else {
                    cout << "The first string is lexicographically larger." << endl;
                }
                break;
            case 4:
                cout << "Enter a string: ";
                cin.getline(str1, 100);
                cout << "Length of the string: " << calculateLength(str1) << endl;
                break;
            case 5:
                cout << "Enter a string: ";
                cin.getline(str1, 100);
                convertToUppercase(str1);
                cout << "String after conversion to uppercase: " << str1 << endl;
                break;
            case 6:
                cout << "Enter a string: ";
                cin.getline(str1, 100);
                reverseString(str1);
                cout << "Reversed string: " << str1 << endl;
                break;
            case 7:
                cout << "Enter the string: ";
                cin.getline(str1, 100);
                cout << "Enter the string to insert: ";
                cin.getline(str2, 100);
                cout << "Enter the position to insert: ";
                cin >> position;
                insertStringAtPosition(str1, str2, position);
                cout << "String after insertion: " << str1 << endl;
                break;
            case 8:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);
    
    return 0;
}


```
![Screenshot (75)](https://github.com/user-attachments/assets/279f6cf3-d553-4e01-9e5e-c1a8dfa99aa6)
![Screenshot (76)](https://github.com/user-attachments/assets/72c57816-1b6a-419c-81a8-10bdcd84d42c)
![Screenshot (77)](https://github.com/user-attachments/assets/b8e6764a-b893-4abd-b3a1-6ed93458c7af)
![Screenshot (78)](https://github.com/user-attachments/assets/621cbdff-1160-4ea5-8441-d0c9d1e818b9)
![Screenshot (79)](https://github.com/user-attachments/assets/5f36c744-cdb9-412a-9a76-5ab2d7b830ed)
![Screenshot (80)](https://github.com/user-attachments/assets/51c2f076-0cdf-4cb7-9897-64548929bac8)
![Screenshot (81)](https://github.com/user-attachments/assets/d4ea5f4a-9c3b-4c6b-8140-24cc17c30052)
![Screenshot (82)](https://github.com/user-attachments/assets/fdd838aa-0955-4184-858c-fb9ad95f76c8)
![Screenshot (83)](https://github.com/user-attachments/assets/929b00cd-6e2b-4af9-9724-be72c8a5907f)
