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
