#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear) {
            rear->next = newNode;
        } else {
            front = newNode; // If queue was empty
        }
        rear = newNode;
    }

    // Dequeue operation
    int dequeue() {
        if (front == nullptr) {
            std::cerr << "Queue is empty!" << std::endl;
            return -1; // Indicate that the queue is empty
        }
        int value = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr; // If the queue is now empty
        }
        delete temp;
        return value;
    }

    // Display the queue
    void display() {
        Node* current = front;
        if (!current) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~Queue() {
        while (front) {
            dequeue();
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    std::cout << "Queue: ";
    q.display();

    std::cout << "Dequeued: " << q.dequeue() << std::endl;
    std::cout << "Queue after dequeue: ";
    q.display();

    return 0;
}