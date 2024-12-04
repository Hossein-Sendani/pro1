#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, size, capacity;
    int* queue;

public:
    // Constructor to initialize the queue with a specified capacity
    CircularQueue(int cap) {
        capacity = cap;
        front = 0;
        rear = -1;
        size = 0;
        queue = new int[capacity];
    }

    // Destructor to free dynamically allocated memory
    ~CircularQueue() {
        delete[] queue;
    }

    // Add an item to the queue (Enqueue)
    void Enqueue(int item) {
        if (IsFull()) {
            cout << "\nQueue is full! Cannot add the item." << endl;
            return;
        }
        rear = (rear + 1) % capacity;  // Circular increment
        queue[rear] = item;
        size++;
        cout << "\nItem " << item << " has been added to the queue." << endl;
    }

    // Remove an item from the queue (Dequeue)
    int Dequeue() {
        if (IsEmpty()) {
            cout << "\nQueue is empty! Cannot remove an item." << endl;
            return -1;  // Return a value to indicate failure
        }
        int item = queue[front];
        front = (front + 1) % capacity;  // Circular increment
        size--;
        cout << "\nItem " << item << " has been removed from the queue." << endl;
        return item;
    }

    // View the front item without removing it (Peek)
    int Peek() {
        if (IsEmpty()) {
            cout << "\nQueue is empty! No front item to display." << endl;
            return -1;  // Return a value to indicate failure
        }
        return queue[front];
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
        int i = front;
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << queue[rear] << endl;  // Print the rear item
    }
};

int main() {
    int capacity;
    cout << "Please enter the capacity of the queue: ";
    cin >> capacity;

    CircularQueue q(capacity);
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
            case 1: {
                int item;
                cout << "Enter a number to enqueue: ";
                cin >> item;
                q.Enqueue(item);
                break;
            }
            case 2:
                q.Dequeue();
                break;
            case 3:
                cout << "Front item: " << q.Peek() << endl;
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
