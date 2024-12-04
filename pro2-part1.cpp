#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size, capacity;
    int* queue;

public:
    // Constructor
    Queue(int cap) {
        capacity = cap;
        front = 0;
        rear = -1;
        size = 0;
        queue = new int[capacity];
    }

    // Destructor
    ~Queue() {
        delete[] queue;
    }

    // Add an item to the queue (Enqueue)
    void Enqueue() {
        if (IsFull()) {
            cout << "\nQueue is full! Cannot add a new item." << endl;
            return;
        }
        int item;
        cout << "\nPlease enter a number to enqueue: ";
        cin >> item;
        rear = (rear + 1) % capacity;  // For circular queue
        queue[rear] = item;
        size++;
        cout << "\nNumber " << item << " has been added to the queue." << endl;
    }

    // Remove an item from the front of the queue (Dequeue)
    void Dequeue() {
        if (IsEmpty()) {
            cout << "\nQueue is empty! No items to dequeue." << endl;
            return;
        }
        int item = queue[front];
        front = (front + 1) % capacity;  // For circular queue
        size--;
        cout << "\nNumber " << item << " has been dequeued from the front." << endl;
    }

    // View the front item without removing it (Peek)
    void Peek() {
        if (IsEmpty()) {
            cout << "\nQueue is empty! No items to display." << endl;
        } else {
            cout << "\nFront item: " << queue[front] << endl;
        }
    }

    // Reverse the queue
    void ReverseQueue() {
        if (IsEmpty()) {
            cout << "\nQueue is empty! Cannot reverse an empty queue." << endl;
            return;
        }

        int start = front;
        int end = rear;
        while (start != end) {
            swap(queue[start], queue[end]);
            start = (start + 1) % capacity;
            end = (end - 1 + capacity) % capacity;
        }
        cout << "\nQueue has been reversed." << endl;
    }

    // Check if the queue is empty
    bool IsEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool IsFull() {
        return size == capacity;
    }

    // Display the current items in the queue
    void DisplayQueue() {
        if (IsEmpty()) {
            cout << "\nQueue is empty." << endl;
            return;
        }
        cout << "\nQueue items: ";
        for (int i = front; i != rear; i = (i + 1) % capacity) {
            cout << queue[i] << " ";
        }
        cout << queue[rear] << endl;
    }
};

int main() {
    int capacity;
    cout << "Please enter the capacity of the queue: ";
    cin >> capacity;

    Queue q(capacity);
    int choice;

    do {
        cout << "\nQueue Operations Menu:";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Reverse Queue";
        cout << "\n5. Display Queue";
        cout << "\n6. Exit";
        cout << "\nPlease enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                q.Enqueue();
                break;
            case 2:
                q.Dequeue();
                break;
            case 3:
                q.Peek();
                break;
            case 4:
                q.ReverseQueue();
                break;
            case 5:
                q.DisplayQueue();
                break;
            case 6:
                cout << "\nExiting the program..." << endl;
                break;
            default:
                cout << "\nInvalid choice, please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
