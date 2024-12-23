#include <iostream>
#define MAX 100 // Maximum size of the stack

class Stack {
private:
    int arr[MAX]; // Array to store stack elements
    int top;      // Index of the top element

public:
    Stack() : top(-1) {} // Constructor to initialize the stack

    // Push operation
    void push(int value) {
        if (top >= MAX - 1) {
            std::cout << "Stack Overflow!" << std::endl;
            return;
        }
        arr[++top] = value; // Increment top and add value
        std::cout << value << " pushed to stack." << std::endl;
    }

    // Pop operation
    int pop() {
        if (top < 0) {
            std::cout << "Stack Underflow!" << std::endl;
            return -1; // Indicate that the stack is empty
        }
        return arr[top--]; // Return top value and decrement top
    }

    // Peek operation
    int peek() {
        if (top < 0) {
            std::cout << "Stack is empty!" << std::endl;
            return -1; // Indicate that the stack is empty
        }
        return arr[top]; // Return the top value
    }

    // Display the stack
    void display() {
        if (top < 0) {
            std::cout << "Stack is empty!" << std::endl;
            return;
        }
        std::cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    stack.display();

    std::cout << "Top element is: " << stack.peek() << std::endl;

    std::cout << "Popped element: " << stack.pop() << std::endl;
    
    stack.display();

    return 0;
}