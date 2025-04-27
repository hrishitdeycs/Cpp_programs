#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // for std::find

using namespace std;

// ANSI escape codes for colored text
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

class SlabAllocator {
private:
    struct Slab {
        vector<void*> freeObjects;
        vector<void*> allocatedObjects;
    };

    unordered_map<size_t, Slab*> slabs;

public:
    ~SlabAllocator() {
        for (auto& pair : slabs) {
            for (auto& allocatedObj : pair.second->allocatedObjects) {
                ::operator delete(allocatedObj);
            }
            delete pair.second;
        }
    }

    void* allocate(size_t objectSize) {
        if (slabs.find(objectSize) == slabs.end()) {
            slabs[objectSize] = new Slab();
        }

        Slab* slab = slabs[objectSize];

        if (!slab->freeObjects.empty()) {
            void* obj = slab->freeObjects.back();
            slab->freeObjects.pop_back();
            slab->allocatedObjects.push_back(obj);
            return obj;
        }

        void* newObject = ::operator new(objectSize);
        slab->allocatedObjects.push_back(newObject);
        return newObject;
    }

    void deallocate(void* obj, size_t objectSize) {
        if (slabs.find(objectSize) == slabs.end()) {
            cout << RED << "Error: Attempting to deallocate from a non-existent slab." << RESET << "\n";
            return;
        }

        Slab* slab = slabs[objectSize];

        auto it = find(slab->allocatedObjects.begin(), slab->allocatedObjects.end(), obj);
        if (it != slab->allocatedObjects.end()) {
            slab->allocatedObjects.erase(it);
            slab->freeObjects.push_back(obj);
        } else {
            cout << YELLOW << "Warning: Attempting to deallocate an object not managed by this allocator." << RESET << "\n";
            ::operator delete(obj);
        }
    }

    void printStatus(size_t objectSize) {
        if (slabs.find(objectSize) == slabs.end()) {
            cout << BLUE << "No slabs allocated yet for this size." << RESET << "\n";
            return;
        }

        Slab* slab = slabs[objectSize];

        cout << "\n" << BOLD << "Slab Status for Size: " << objectSize << RESET << "\n";
        cout << "-------------------------------\n";
        cout << "Allocated objects: " << slab->allocatedObjects.size() << "\n";
        cout << "Free objects: " << slab->freeObjects.size() << "\n";
        cout << "-------------------------------\n";

        cout << "\nIn real memory management systems like the kernel, the slab allocator\n";
        cout << "provides an efficient way to manage memory chunks by keeping track of\n";
        cout << "allocated and free objects within slabs. The print status function allows\n";
        cout << "us to see how much memory is allocated and how much is still free, helping\n";
        cout << "to monitor memory usage in real-time. This prevents memory fragmentation and\n";
        cout << "ensures optimal usage of memory.\n";
    }

    void simulateMemoryOps(size_t objectSize, vector<void*>& allocatedObjects) {
        cout << "\n" << BLUE << "Simulating Kernel Memory Operations..." << RESET << "\n";
        cout << "-------------------------------------------------\n";

        // Only run one cycle (i.e., one allocation and one deallocation)
        cout << "\n" << GREEN << "Allocating memory..." << RESET << "\n";
        // Simulate allocation
        void* obj = allocate(objectSize);
        allocatedObjects.push_back(obj);
        cout << GREEN << "Allocated at: " << obj << RESET << "\n";
        
        // Simulate deallocation
        cout << "\n" << RED << "Deallocating memory..." << RESET << "\n";
        if (!allocatedObjects.empty()) {
            void* deallocObj = allocatedObjects.back();
            deallocate(deallocObj, objectSize);
            allocatedObjects.pop_back();
            cout << RED << "Deallocated at: " << deallocObj << RESET << "\n";
        }
        
        printStatus(objectSize);
    }

    void printErrorTheory(const string& errorMessage) {
        cout << "\nErrors like: " << errorMessage << " typically occur in memory management when\n";
        cout << "an operation is attempted on an object that doesn’t exist in the allocator's records.\n";
        cout << "In kernel memory management, attempts to access memory outside of allocated ranges\n";
        cout << "or try to free memory not managed by the system can result in system crashes or instability.\n";
    }
};

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

int main() {
    size_t objectSize;
    cout << GREEN << "Enter object size for the slab allocator: " << RESET;
    cin >> objectSize;

    SlabAllocator allocator;
    vector<void*> allocatedObjects;

    while (true) {
        menu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                void* obj = allocator.allocate(objectSize);
                allocatedObjects.push_back(obj);
                cout << GREEN << "Object allocated at address: " << obj << RESET << "\n";
                cout << "\nIn kernel memory management, allocating an object involves finding\n";
                cout << "a suitable slab to provide the requested memory. If the slab is empty,\n";
                cout << "a new block of memory is allocated. The allocator returns the address\n";
                cout << "of the newly allocated memory for use in the system.\n";
                break;
            }
            case 2: {
                if (allocatedObjects.empty()) {
                    cout << YELLOW << "No objects to deallocate." << RESET << "\n";
                    allocator.printErrorTheory("No objects to deallocate");
                } else {
                    void* obj = allocatedObjects.back();
                    allocatedObjects.pop_back();
                    allocator.deallocate(obj, objectSize);
                    cout << GREEN << "Object deallocated at address: " << obj << RESET << "\n";
                    cout << "\nIn kernel memory management, deallocating an object involves returning\n";
                    cout << "the memory back to the slab. The allocator ensures that the memory is\n";
                    cout << "properly removed from the list of allocated objects and placed into the\n";
                    cout << "list of free objects, making it available for future allocations.\n";
                }
                break;
            }
            case 3:
                allocator.printStatus(objectSize);
                break;
            case 4:
                allocator.simulateMemoryOps(objectSize, allocatedObjects);
                break;
            case 5:
                cout << BLUE << "Exiting..." << RESET << "\n";
                return 0;
            default:
                cout << RED << "Invalid choice. Try again." << RESET << "\n";
                allocator.printErrorTheory("Invalid choice entered");
        }
    }

    return 0;
}
