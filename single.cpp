#include <iostream>
using namespace std;

struct Node {
    int data; // Data to store the value
    Node* next; // Pointer to the next node
};

class SinglyLinkedList {
public:
    Node* head; // Head of the list

    SinglyLinkedList() {
        head = nullptr; // Initialize head as nullptr
    }

    // Insert at the beginning of the list
    void InsertAtBegin(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head; // Point to the previous first node
        head = newNode; // Update head to the new node
    }

    // Insert at the end of the list
    void InsertAtEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr; // The new node will be the last, so its next is nullptr
        if (head == nullptr) {
            head = newNode; // If the list is empty, make the new node the head
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next; // Traverse until the end of the list
            }
            temp->next = newNode; // Attach the new node at the end
        }
    }

    // Insert at a specific index
    void InsertAtIndex(int data, int index) {
        if (index == 0) {
            InsertAtBegin(data); // Insert at the beginning if index is 0
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
            newNode->next = temp->next; // Point the new node to the next node
            temp->next = newNode; // Insert the new node at the correct position
        }
    }

    // Update a node at a specific index
    void UpdateNode(int data, int index) {
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < index; i++) {
            temp = temp->next; // Traverse to the node at the index
        }
        if (temp == nullptr) {
            cout << "Index out of bounds!" << endl;
        } else {
            temp->data = data; // Update the data of the node
        }
    }

    // Remove a node at a specific index
    int RemoveNodeAtIndex(int index) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return -1;
        }
        Node* temp = head;
        if (index == 0) { // Special case for removing the first node
            head = temp->next; // Update head to the second node
            int data = temp->data;
            delete temp; // Delete the first node
            return data;
        }
        for (int i = 0; temp != nullptr && i < index - 1; i++) {
            temp = temp->next; // Traverse to the node before the one to be removed
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Index out of bounds!" << endl;
            return -1;
        }
        Node* next = temp->next->next;
        int data = temp->next->data;
        delete temp->next; // Delete the node
        temp->next = next; // Update the link to the next node
        return data;
    }

    // Display the linked list
    void DisplayList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " "; // Print the data of the current node
            temp = temp->next; // Move to the next node
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list1;
    int n, data, index;

    // Get the number of elements from the user
    cout << "Enter the number of elements for the list: ";
    cin >> n;

    cout << "Please enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> data;
        list1.InsertAtEnd(data); // Insert elements at the end of the list
    }

    cout << "List after inserting elements: ";
    list1.DisplayList();

    // Insert a new element at the beginning
    cout << "Enter a new element to insert at the beginning: ";
    cin >> data;
    list1.InsertAtBegin(data);
    cout << "List after inserting at the beginning: ";
    list1.DisplayList();

    // Insert a new element at the end
    cout << "Enter a new element to insert at the end: ";
    cin >> data;
    list1.InsertAtEnd(data);
    cout << "List after inserting at the end: ";
    list1.DisplayList();

    // Insert an element at a specific index
    cout << "Enter the index and data for inserting: ";
    cin >> index >> data;
    list1.InsertAtIndex(data, index);
    cout << "List after inserting at index " << index << ": ";
    list1.DisplayList();

    return 0;
}
