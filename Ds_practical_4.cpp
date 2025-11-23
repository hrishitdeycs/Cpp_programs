#include <iostream>
using namespace std;
class Stack {
private:
    int* arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        arr = new int[size];
        top = -1;
        capacity = size;
    }
    ~Stack() {
        delete[] arr;
    }
    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = x;
    }
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!\n";
            return 0;
        }
        return arr[top--];
    }
    bool isEmpty() {
        return top == -1;
    }
};
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}
int evaluatePostfix(string exp) {
    Stack s(exp.length());
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (isdigit(c)) {
            int value = int(c - '0');  // explicit conversion
            s.push(value);
        } else if (isOperator(c)) {
            int b = s.pop();
            int a = s.pop();
            s.push(applyOp(a, b, c));
        }
    }
    return s.pop();
}
int evaluatePrefix(string exp) {
    Stack s(exp.length());
    for (int i = exp.length() - 1; i >= 0; i--) {
        char c = exp[i];
        if (isdigit(c)) {
            int value = int(c - '0');  // explicit conversion
            s.push(value);
        } else if (isOperator(c)) {
            int a = s.pop();
            int b = s.pop();
            s.push(applyOp(a, b, c));
        }
    }
    return s.pop();
}
int main() {
    string postfix, prefix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;
    cout << "Enter Prefix Expression: ";
    cin >> prefix;
    cout << "\nPostfix Result: " << evaluatePostfix(postfix);
    cout << "\nPrefix Result: " << evaluatePrefix(prefix);
    return 0;
}
