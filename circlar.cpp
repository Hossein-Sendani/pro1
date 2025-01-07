
#include <iostream>
using namespace std;

struct Node {
    int data; // Data to store the value
    Node* next; // Pointer to the next node
};

class CircularLinkedList {
public:
    Node* head; // Head of the circular list

    CircularLinkedList() {
        head = nullptr; // Initialize head as nullptr
    }

    // Insert at the beginning of the circular list
    void InsertAtBegin(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Make it circular
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next; // Traverse until the last node
            }
            temp->next = newNode; // Point the last node to the new node
            newNode->next = head; // Make the new node point to head to form a circle
            head = newNode; // Update head to the new node
        }
    }

    // Insert at the end of the circular list
    void InsertAtEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Make it circular
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next; // Traverse until the last node
            }
            temp->next = newNode; // Point the last node to the new node
            newNode->next = head; // Make the new node point to head to form a circle
        }
    }

    // Insert at a specific index in the circular list
    void InsertAtIndex(int data, int index) {
        if (index == 0) {
            InsertAtBegin(data); // If index is 0, insert at the beginning
            return;
        }
        Node* newNode = new Node;
        newNode->data = data;
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < index - 1; i++) {
            temp = temp->next; // Traverse to the node before the index
        }
        if (temp == nullptr) {
            cout << "Index out of bounds!" << endl;
            delete newNode;
        } else {
            newNode->next = temp->next; // Point to the next node
            temp->next = newNode; // Insert the new node at the specified index
        }
    }

    // Display the circular linked list
    void DisplayList() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " "; // Print the data of the current node
            temp = temp->next; // Move to the next node
        } while (temp != head); // Stop when we complete the cycle
        cout << endl;
    }
};

int main() {
    CircularLinkedList list1;
    int n, data, index;

    // Get the number of elements from the user
    cout << "Enter the number of elements for the circular list: ";
    cin >> n;

    cout << "Please enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> data;
        list1.InsertAtEnd(data); // Insert elements at the end
    }

    cout << "Circular List after inserting elements: ";
    list1.DisplayList();

    // Insert a new element at the beginning
    cout << "Enter a new element to insert at the beginning: ";
    cin >> data;
    list1.InsertAtBegin(data);
    cout << "Circular List after inserting at the beginning: ";
    list1.DisplayList();

    // Insert a new element at the end
    cout << "Enter a new element to insert at the end: ";
    cin >> data;
    list1.InsertAtEnd(data);
    cout << "Circular List after inserting at the end: ";
    list1.DisplayList();

    return 0;
}
