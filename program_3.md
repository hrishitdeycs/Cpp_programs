#  Write a program that prints a table indicating the number of occurrences of each alphabet in the text entered as command line arguments.
```bash
#include <iostream>
#include <cctype>  // For character functions like tolower
#include <string>
#include <map>
using namespace std;
void countAlphabetOccurrences(const string& text) {
    map<char, int> frequency;
    // Loop through each character in the text
    for (char ch : text) {
        // Convert to lowercase to handle case-insensitivity
        ch = tolower(ch);   
        // Check if the character is an alphabet letter
        if (isalpha(ch)) {
            frequency[ch]++;  // Increment the count of the alphabet
        }
    }
    // Print the table of occurrences
    cout << "Alphabet Occurrences:" << endl;
    cout << "Letter | Occurrences" << endl;
    cout << "----------------------" << endl;
    for (char letter = 'a'; letter <= 'z'; letter++) {
        // If the letter exists in the map, print its frequency
        if (frequency.find(letter) != frequency.end()) {
            cout << letter << "      | " << frequency[letter] << endl;
        } else {
            cout << letter << "      | 0" << endl;
        }
    }
}
int main(int argc, char* argv[]) {
    // Check if any command line arguments were provided
    if (argc < 2) {
        cout << "Please provide a text input as a command line argument." << endl;
        return 1;  // Return error if no argument is passed
    }
    // Concatenate the command line arguments into a single string
    string text = "";
    for (int i = 1; i < argc; i++) {
        text += string(argv[i]) + " ";  // Add space between words
    }
    // Call the function to count occurrences
    countAlphabetOccurrences(text);
    return 0;
}

```
![Screenshot (67)](https://github.com/user-attachments/assets/b221a933-094a-4a9c-92c5-4fcc852b4da6)
![Screenshot (68)](https://github.com/user-attachments/assets/cee70275-4072-4770-8305-6792cc332fe8)
![Screenshot (69)](https://github.com/user-attachments/assets/6f196b15-69fe-478e-b35d-9ae4013495cf)
![Screenshot (70)](https://github.com/user-attachments/assets/27e3db58-d2d8-46a4-b52e-fbce40c72f61)
