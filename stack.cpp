#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int size;
    int* stack;

public:
    // Constructor to initialize the stack
    Stack(int s) {
        size = s;
        stack = new int[size];
        top = -1;
    }

    // Destructor to free the dynamically allocated memory
    ~Stack() {
        delete[] stack;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == size - 1;
    }

    // Function to add an element to the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        stack[++top] = value;
        cout << "Pushed: " << value << endl;
    }

    // Function to remove an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << "Popped: " << stack[top--] << endl;
    }

    // Function to view the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return stack[top];
    }

    // Function to get the size of the stack
    int getSize() {
        return top + 1;
    }
};

int main() {
    Stack stack(5);  // Create a stack of size 5

    // Pushing elements to the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    // Trying to push when the stack is full
    stack.push(60);

    // Popping elements from the stack
    stack.pop();
    stack.pop();

    // Pushing more elements
    stack.push(60);
    stack.push(70);

    // Viewing the top element and the size of the stack
    cout << "Top element: " << stack.peek() << endl;
    cout << "Stack size: " << stack.getSize() << endl;

    return 0;
}
