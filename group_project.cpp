#include <iostream>             // Include the iostream library for input/output operations
#include <vector>               // Include the vector container to store dynamic arrays
#include <unordered_map>        // Include unordered_map for efficient key-value storage
#include <algorithm>            // Include the algorithm library for utility functions like find

using namespace std;            // Use the standard namespace to avoid writing 'std::' every time

// ANSI escape codes for colored text in terminal
#define RESET   "\033[0m"      // Reset color to default
#define RED     "\033[31m"     // Set text color to red
#define GREEN   "\033[32m"     // Set text color to green
#define YELLOW  "\033[33m"     // Set text color to yellow
#define BLUE    "\033[34m"     // Set text color to blue
#define BOLD    "\033[1m"      // Set text to bold

// Class for Slab Allocator simulation
class SlabAllocator {
private:
    // Structure representing a slab containing free and allocated objects
    struct Slab {
        vector<void*> freeObjects;        // Vector to store free objects in the slab
        vector<void*> allocatedObjects;   // Vector to store allocated objects in the slab
    };

    unordered_map<size_t, Slab*> slabs;  // Map to store slabs by object size

public:
    // Destructor to clean up memory
    ~SlabAllocator() {
        // Iterate through each slab in the slabs map
        for (auto& pair : slabs) {
            // Iterate through the allocated objects and delete them
            for (auto& allocatedObj : pair.second->allocatedObjects) {
                ::operator delete(allocatedObj);  // Deallocate memory
            }
            delete pair.second;  // Delete the slab itself
        }
    }

    // Method to allocate memory for an object of given size
    void* allocate(size_t objectSize) {
        // If the slab for this object size doesn't exist, create a new slab
        if (slabs.find(objectSize) == slabs.end()) {
            slabs[objectSize] = new Slab();
        }

        Slab* slab = slabs[objectSize];  // Get the slab for the given object size

        // If there are free objects in the slab, reuse one
        if (!slab->freeObjects.empty()) {
            void* obj = slab->freeObjects.back();  // Get the last free object
            slab->freeObjects.pop_back();          // Remove the free object from the list
            slab->allocatedObjects.push_back(obj); // Add the object to allocated objects
            return obj;                           // Return the allocated object
        }

        // If no free objects, allocate new memory
        void* newObject = ::operator new(objectSize);  // Use the global new operator
        slab->allocatedObjects.push_back(newObject);   // Add the new object to allocated objects
        return newObject;  // Return the newly allocated object
    }

    // Method to deallocate a previously allocated object
    void deallocate(void* obj, size_t objectSize) {
        // Check if the slab exists for the given object size
        if (slabs.find(objectSize) == slabs.end()) {
            cout << RED << "Error: Attempting to deallocate from a non-existent slab." << RESET << "\n";
            return;  // Return if slab doesn't exist
        }

        Slab* slab = slabs[objectSize];  // Get the slab for the object size

        // Find the object in the allocatedObjects list
        auto it = find(slab->allocatedObjects.begin(), slab->allocatedObjects.end(), obj);
        if (it != slab->allocatedObjects.end()) {
            slab->allocatedObjects.erase(it);  // Remove the object from allocated objects
            slab->freeObjects.push_back(obj);  // Add the object to the free list
        } else {
            // If object not found in allocated objects, issue a warning
            cout << YELLOW << "Warning: Attempting to deallocate an object not managed by this allocator." << RESET << "\n";
            ::operator delete(obj);  // Deallocate memory directly
        }
    }

    // Method to print the status of a slab for a given object size
    void printStatus(size_t objectSize) {
        // If the slab doesn't exist, print a message
        if (slabs.find(objectSize) == slabs.end()) {
            cout << BLUE << "No slabs allocated yet for this size." << RESET << "\n";
            return;  // Return if no slabs exist for this size
        }

        Slab* slab = slabs[objectSize];  // Get the slab for the given object size

        // Print the slab status: allocated and free object counts
        cout << "\n" << BOLD << "Slab Status for Size: " << objectSize << RESET << "\n";
        cout << "-------------------------------\n";
        cout << "Allocated objects: " << slab->allocatedObjects.size() << "\n";
        cout << "Free objects: " << slab->freeObjects.size() << "\n";
        cout << "-------------------------------\n";

        // Print information about memory management in real systems
        cout << "\nIn real memory management systems like the kernel, the slab allocator\n";
        cout << "provides an efficient way to manage memory chunks by keeping track of\n";
        cout << "allocated and free objects within slabs. The print status function allows\n";
        cout << "us to see how much memory is allocated and how much is still free, helping\n";
        cout << "to monitor memory usage in real-time. This prevents memory fragmentation and\n";
        cout << "ensures optimal usage of memory.\n";
    }

    // Simulate a memory allocation and deallocation cycle
    void simulateMemoryOps(size_t objectSize, vector<void*>& allocatedObjects) {
        cout << "\n" << BLUE << "Simulating Kernel Memory Operations..." << RESET << "\n";
        cout << "-------------------------------------------------\n";

        // Simulate memory allocation
        cout << "\n" << GREEN << "Allocating memory..." << RESET << "\n";
        void* obj = allocate(objectSize);  // Allocate memory for an object
        allocatedObjects.push_back(obj);    // Track the allocated object
        cout << GREEN << "Allocated at: " << obj << RESET << "\n";
        
        // Simulate memory deallocation
        cout << "\n" << RED << "Deallocating memory..." << RESET << "\n";
        if (!allocatedObjects.empty()) {
            void* deallocObj = allocatedObjects.back();  // Get the last allocated object
            deallocate(deallocObj, objectSize);          // Deallocate the object
            allocatedObjects.pop_back();                 // Remove the object from the tracking list
            cout << RED << "Deallocated at: " << deallocObj << RESET << "\n";
        }
        
        // Print the current status of the slab
        printStatus(objectSize);
    }

    // Method to explain memory management errors
    void printErrorTheory(const string& errorMessage) {
        // Provide an explanation for common memory management errors
        cout << "\nErrors like: " << errorMessage << " typically occur in memory management when\n";
        cout << "an operation is attempted on an object that doesn’t exist in the allocator's records.\n";
        cout << "In kernel memory management, attempts to access memory outside of allocated ranges\n";
        cout << "or try to free memory not managed by the system can result in system crashes or instability.\n";
    }
};

// Menu function to display options to the user
void menu() {
    cout << "\n" << BOLD << BLUE << "Slab Allocator Simulation" << RESET << "\n";
    cout << "===========================\n";
    cout << "1. Allocate Object\n";
    cout << "2. Deallocate Object\n";
    cout << "3. Print Status\n";
    cout << "4. Simulate Memory Operations (Side-by-Side)\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Main function to run the slab allocator simulation
int main() {
    size_t objectSize;  // Variable to store the size of objects for allocation
    cout << GREEN << "Enter object size for the slab allocator: " << RESET;
    cin >> objectSize;  // Take user input for object size

    SlabAllocator allocator;  // Create an instance of SlabAllocator
    vector<void*> allocatedObjects;  // Vector to track allocated objects

    // Loop to repeatedly display the menu and perform actions
    while (true) {
        menu();  // Display the menu
        int choice;  // Variable to store the user's choice
        cin >> choice;  // Take user input for the choice

        switch (choice) {
            case 1: {
                void* obj = allocator.allocate(objectSize);  // Allocate memory
                allocatedObjects.push_back(obj);  // Track the allocated object
                cout << GREEN << "Object allocated at address: " << obj << RESET << "\n";
                break;
            }
            case 2: {
                if (allocatedObjects.empty()) {
                    cout << YELLOW << "No objects to deallocate." << RESET << "\n";  // No objects to deallocate
                    allocator.printErrorTheory("No objects to deallocate");
                } else {
                    void* obj = allocatedObjects.back();  // Get the last allocated object
                    allocatedObjects.pop_back();  // Remove it from the tracking list
                    allocator.deallocate(obj, objectSize);  // Deallocate the object
                    cout << GREEN << "Object deallocated at address: " << obj << RESET << "\n";
                }
                break;
            }
            case 3:
                allocator.printStatus(objectSize);  // Print the status of the slab
                break;
            case 4:
                allocator.simulateMemoryOps(objectSize, allocatedObjects);  // Simulate memory operations
                break;
            case 5:
                cout << BLUE << "Exiting..." << RESET << "\n";  // Exit the program
                return 0;
            default:
                cout << RED << "Invalid choice. Try again." << RESET << "\n";  // Handle invalid choice
                allocator.printErrorTheory("Invalid choice entered");
        }
    }

    return 0;  // Return 0 indicating successful execution
}
