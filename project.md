# Memory leak detector
# First draft
```bash
#include <iostream>
#include <unordered_map>
#include <ctime>
#include <cstdlib>

using namespace std;

struct AllocationInfo {
    time_t allocationTime;
    size_t size;
};

unordered_map<void*, AllocationInfo> allocations;

void* allocateMemory(size_t size) {
    void* ptr = malloc(size);
    if (ptr) {
        AllocationInfo info = { time(nullptr), size };
        allocations[ptr] = info;
    }
    return ptr;
}

void deallocateMemory(void* ptr) {
    auto it = allocations.find(ptr);
    if (it != allocations.end()) {
        AllocationInfo info = it->second;
        cout << "Deallocating memory of size " << info.size << " allocated at " << ctime(&info.allocationTime);
        allocations.erase(it);
        free(ptr);
    } else {
        cout << "Pointer not found in allocations.\n";
    }
}

void checkMemory() {
    if (allocations.empty()) {
        cout << "No memory leaks detected.\n";
    } else {
        cout << "Memory leaks detected:\n";
        for (const auto& pair : allocations) {
            const AllocationInfo& info = pair.second;
            cout << "Leaked memory of size " << info.size << " allocated at " << ctime(&info.allocationTime);
        }
    }
}

void userInputLoop() {
    char command;
    size_t size;
    void* ptr;

    while (true) {
        cout << "Enter command (a: allocate, d: deallocate, c: check, q: quit): ";
        cin >> command;

        switch (command) {
            case 'a':
                cout << "Enter size to allocate: ";
                cin >> size;
                ptr = allocateMemory(size);
                if (ptr) {
                    cout << "Memory allocated at " << ptr << "\n";
                } else {
                    cout << "Allocation failed.\n";
                }
                break;
            case 'd':
                cout << "Enter pointer to deallocate: ";
                cin >> ptr;
                deallocateMemory(ptr);
                break;
            case 'c':
                checkMemory();
                break;
            case 'q':
                checkMemory();
                return;
            default:
                cout << "Invalid command.\n";
                break;
        }
    }
}

int main() {
    userInputLoop();
    return 0;
}
```
