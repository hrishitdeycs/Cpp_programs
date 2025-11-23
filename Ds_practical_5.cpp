#include <iostream>
using namespace std;
class Queue {
private:
    int *arr;
    int front, rear, capacity;
public:
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return rear == capacity - 1;
    }
    int count() {
        if (isEmpty()) return 0;
        return (rear - front + 1);
    }
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        int value = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        return value;
    }
    // SIMPLE DISPLAY FUNCTION
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Queue() {
        delete[] arr;
    }
};
int main() {
    Queue q(5);
    q.enqueue(10);
    q.display();
    q.enqueue(20);
    q.display();
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    cout << "Count = " << q.count() << endl;
    return 0;
}
