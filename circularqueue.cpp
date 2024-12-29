#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queue;
    int front, rear, size, capacity;

public:
    CircularQueue(int capacity) {
        this->capacity = capacity;
        queue = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
        if (size == 0) front = rear = -1;
    }

    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return queue[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        int i = front;
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << queue[rear] << endl;
    }
};

int main() {
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Queue: ";
    q.display();

    q.dequeue();
    cout << "Queue after dequeue: ";
    q.display();

    return 0;
}
