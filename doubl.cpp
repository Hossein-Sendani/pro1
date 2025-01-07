
#include <iostream>
using namespace std;

struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node
    Node* prev;     // Pointer to the previous node
};

class DoublyLinkedList {
public:
    Node* head; // Head of the list

    DoublyLinkedList() {
        head = nullptr; // Initialize head as nullptr
    }

    // Insert at the beginning of the doubly linked list
    void InsertAtBegin(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr; // New node has no previous node
        newNode->next = head;    // New node points to the old head
        if (head != nullptr) {
            head->prev = newNode; // Old head's previous pointer now points to the new node
        }
        head = newNode; // Update head to the new node
    }

    // Insert at the end of the doubly linked list
    void InsertAtEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr; // The new node will be the last, so its next is nullptr
        if (head == nullptr) {
            newNode->prev = nullptr; // If the list is empty, prev is also nullptr
            head = newNode; // If the list is empty, make the new node the head
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next; // Traverse until the end of the list
            }
            temp->next = newNode; // Link the last node to the new node
            newNode->prev = temp; // Set the new node's prev pointer to the last node
        }
    }

    // Insert at a specific index in the doubly linked list
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
            newNode->next = temp->next; // Link the new node to the next node
            if (temp->next != nullptr) {
                temp->next->prev = newNode; // Update the next node's prev pointer
            }
            newNode->prev = temp; // Set the new node's prev pointer to the current node
            temp->next = newNode; // Link the current node to the new node
        }
    }

    // Update a node at a specific index in the doubly linked list
    void UpdateNode(int data, int index) {
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < index; i++) {
            temp = temp->next; // Traverse to the node at the index
        }
        if (temp == nullptr) {
            cout << "Index out of bounds!" << endl;
        } else {
            temp->data = data; // Update the data in the node
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
            if (head != nullptr) {
                head->prev = nullptr; // If there is a second node, set its prev pointer to nullptr
            }
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
        if (next != nullptr) {
            next->prev = temp; // Update the previous pointer of the next node
        }
        temp->next = next; // Link the current node to the next node
        return data;
    }

    // Remove the last node from the doubly linked list
    int RemoveNodeAtEnd() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return -1;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next; // Traverse to the last node
        }
        int data = temp->data;
        if (temp->prev != nullptr) {
            temp->prev->next = nullptr; // Update the previous node to end the list
        } else {
            head = nullptr; // If the list has only one node, set head to nullptr
        }
        delete temp; // Delete the last node
        return data;
    }

    // Remove the first node from the doubly linked list
    int RemoveNodeAtBegin() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return -1;
        }
        Node* temp = head;
        head = temp->next; // Update head to the second node
        if (head != nullptr) {
            head->prev = nullptr; // Set the new head's prev pointer to nullptr
        }
        int data = temp->data;
        delete temp; // Delete the first node
        return data;
    }

    // Display the doubly linked list
    void DisplayList() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " "; // Print the data of the current node
            temp = temp->next; // Move to the next node
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list1;
    int n, data, index;

    // Get the number of elements from the user
    cout << "Enter the number of elements for the doubly linked list: ";
    cin >> n;

    cout << "Please enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cout << "Element " << (i + 1) << ": ";
        cin >> data;
        list1.InsertAtEnd(data); // Insert elements at the end
    }

    cout << "Doubly Linked List after inserting elements: ";
    list1.DisplayList();

    // Insert a new element at the beginning
    cout << "Enter a new element to insert at the beginning: ";
    cin >> data;
    list1.InsertAtBegin(data);
    cout << "Doubly Linked List after inserting at the beginning: ";
    list1.DisplayList();

    // Insert a new element at the end
    cout << "Enter a new element to insert at the end: ";
    cin >> data;
    list1.InsertAtEnd(data);
    cout << "Doubly Linked List after inserting at the end: ";
    list1.DisplayList();

    // Insert an element at a specific index
    cout << "Enter the index and data for inserting: ";
    cin >> index >> data;
    list1.InsertAtIndex(data, index);
    cout << "Doubly Linked List after inserting at index " << index << ": ";
    list1.DisplayList();

    // Update a node at a specific index
    cout << "Enter the index and data to update: ";
    cin >> index >> data;
    list1.UpdateNode(data, index);
    cout << "Doubly Linked List after updating node at index " << index << ": ";
    list1.DisplayList();

    // Remove a node at a specific index
    cout << "Enter the index of the node to remove: ";
    cin >> index;
    list1.RemoveNodeAtIndex(index);
    cout << "Doubly Linked List after removing node at index " << index << ": ";
    list1.DisplayList();

    return 0;
}
