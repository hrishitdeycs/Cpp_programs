
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



