# Memory leak detector
```bash
#include <iostream>        // For input/output operations
#include <unordered_map>   // For storing allocation information (using a hash map)
#include <ctime>           // For working with time (used to track the time of allocation)
#include <cstdlib>         // For malloc() and free()

using namespace std;

// Structure to store information about each memory allocation
struct AllocationInfo {
    time_t allocationTime; // Time when memory was allocated
    size_t size;          // Size of the allocated memory
};

// Unordered map (hash map) to track all allocated memory pointers
unordered_map<void*, AllocationInfo> allocations;

// Function to allocate memory and track its allocation
// Takes the size of memory to be allocated as an argument
void* allocateMemory(size_t size) {
    void* ptr = malloc(size);  // Allocate memory using malloc
    if (ptr) {  // If allocation is successful
        AllocationInfo info = { time(nullptr), size };  // Store allocation time and size
        allocations[ptr] = info;  // Store the information in the allocations map
    }
    return ptr;  // Return the allocated memory pointer
}

// Function to deallocate memory and remove its tracking information
// Takes the pointer to the memory to be deallocated as an argument
void deallocateMemory(void* ptr) {
    // Search for the memory pointer in the allocations map
    auto it = allocations.find(ptr); 
    if (it != allocations.end()) {  // If pointer is found in the map
        AllocationInfo info = it->second;  // Get the allocation info
        // Print details about the deallocation
        cout << "Deallocating memory of size " << info.size 
             << " allocated at " << ctime(&info.allocationTime);
        allocations.erase(it);  // Remove the allocation info from the map
        free(ptr);  // Free the memory using free()
    } else {  // If the pointer is not found in the map
        cout << "Pointer not found in allocations.\n";
    }
}

// Function to check for any memory leaks (allocated memory that wasn't freed)
void checkMemory() {
    // Check if there are any allocations still present in the map
    if (allocations.empty()) {
        cout << "No memory leaks detected.\n";  // No memory leaks
    } else {
        cout << "Memory leaks detected:\n";  // If there are memory leaks
        // Iterate over all the remaining allocations and print their details
        for (const auto& pair : allocations) {
            const AllocationInfo& info = pair.second;
            cout << "Leaked memory of size " << info.size 
                 << " allocated at " << ctime(&info.allocationTime);
        }
    }
}

// Function to handle user input and perform memory management operations
void userInputLoop() {
    char command;  // Command entered by the user
    size_t size;   // Size of memory to allocate
    void* ptr;     // Pointer to the allocated memory (or deallocated memory)

    // Infinite loop for user interaction
    while (true) {
        // Prompt user for input and provide options for memory management
        cout << "Enter command (a: allocate, d: deallocate, c: check, q: quit): ";
        cin >> command;  // Read user command

        switch (command) {  // Switch case based on the command entered
            case 'a':  // Allocate memory
                cout << "Enter size to allocate: ";
                cin >> size;  // Read the size of memory to allocate
                ptr = allocateMemory(size);  // Call the allocateMemory function
                if (ptr) {  // If allocation is successful
                    cout << "Memory allocated at " << ptr << "\n";
                } else {  // If allocation fails
                    cout << "Allocation failed.\n";
                }
                break;

            case 'd':  // Deallocate memory
                cout << "Enter pointer to deallocate: ";
                cin >> ptr;  // Read the pointer to deallocate
                deallocateMemory(ptr);  // Call the deallocateMemory function
                break;

            case 'c':  // Check for memory leaks
                checkMemory();  // Call the checkMemory function
                break;

            case 'q':  // Quit the program
                checkMemory();  // Check for memory leaks before quitting
                return;  // Exit the user input loop

            default:  // If an invalid command is entered
                cout << "Invalid command.\n";
                break;
        }
    }
}

// Main function to start the program
int main() {
    userInputLoop();  // Start the user input loop for memory management
    return 0;  // Exit the program
}
```
![Screenshot (124)](https://github.com/user-attachments/assets/54f60bde-233b-4c71-8d5c-fb220276d12c)
