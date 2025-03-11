#  Copy the contents of one text file to another file, after removing all whitespaces.
```bash
#include <iostream>
#include <fstream>
#include <cctype>  // For checking whitespace
using namespace std;
int main() {
    // Input and output file names
    string inputFile = "input.txt";
    string outputFile = "output.txt";
    // Open the input file for reading
    ifstream inFile(inputFile);
    // Check if the file opened successfully
    if (!inFile) {
        cerr << "Error: Unable to open input file!" << endl;
        return 1;
    }
    // Open the output file for writing
    ofstream outFile(outputFile);
    // Check if the file opened successfully
    if (!outFile) {
        cerr << "Error: Unable to open output file!" << endl;
        return 1;
    }
    char ch;
    // Read characters from the input file
    while (inFile.get(ch)) {
        // If the character is not a whitespace, write it to the output file
        if (!isspace(ch)) {
            outFile.put(ch);
        }
    }
    // Close the files
    inFile.close();
    outFile.close();
    cout << "File contents copied successfully without whitespaces." << endl;
    return 0;
}

```
![Screenshot (113)](https://github.com/user-attachments/assets/b94bf7aa-0adc-449c-b270-6a4d13bac093)
![Screenshot (114)](https://github.com/user-attachments/assets/1dce0295-f19d-4faf-88d2-d5d1698db3dd)

