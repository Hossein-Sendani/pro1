#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;         // ?????? ???? ??????? ?????
    int size;         // ?????? ????? ?????
    int capacity;     // ????? ?????

    // ?????? ????? ????? ?? ???? ????
    void resize(int newCapacity) {
        int* newArr = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    // ??????
    DynamicArray(int initialCapacity = 10) {
        size = 0;
        capacity = initialCapacity;
        arr = new int[capacity];
    }

    // ???????????
    ~DynamicArray() {
        delete[] arr;
    }

    // ?????? ????? ?? ?????? ???
    void Insert(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Invalid index!" << endl;
            return;
        }
        if (size == capacity) {
            resize(2 * capacity);
        }
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
        cout << "Value " << value << " inserted at index " << index << endl;
    }

    // ??? ???? ?? ???? ????? ? ????????? ?????? ??
    int Delete_By_Value(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                for (int j = i; j < size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                size--;
                cout << "Value " << value << " deleted from index " << i << endl;
                return i;
            }
        }
        cout << "Value not found!" << endl;
        return -1;
    }

    // ??? ???? ?? ???? ??????
    void Delete_By_Index(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index!" << endl;
            return;
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Value at index " << index << " deleted" << endl;
    }

    // ????? ?????
    void Display() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // ?????? ????? ?? ?????? ?????
    void Append(int value) {
        if (size == capacity) {
            resize(2 * capacity);
        }
        arr[size++] = value;
        cout << "Value " << value << " appended to the array" << endl;
    }

    // ????? ???? ?????
    void Reverse() {
        for (int i = 0; i < size / 2; i++) {
            swap(arr[i], arr[size - 1 - i]);
        }
        cout << "Array reversed successfully." << endl;
    }

    // ?????? ????? ? ????????? ?????? ??
    int Search_By_Value(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                cout << "Value " << value << " found at index " << i << endl;
                return i;
            }
        }
        cout << "Value not found!" << endl;
        return -1;
    }
};

// ???? ???? ???? ???
int main() {
    DynamicArray array;
    int choice, index, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete by Value\n";
        cout << "3. Delete by Index\n";
        cout << "4. Display\n";
        cout << "5. Append\n";
        cout << "6. Reverse\n";
        cout << "7. Search by Value\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter index and value: ";
            cin >> index >> value;
            array.Insert(index, value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            array.Delete_By_Value(value);
            break;
        case 3:
            cout << "Enter index to delete: ";
            cin >> index;
            array.Delete_By_Index(index);
            break;
        case 4:
            array.Display();
            break;
        case 5:
            cout << "Enter value to append: ";
            cin >> value;
            array.Append(value);
            break;
        case 6:
            array.Reverse();
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            array.Search_By_Value(value);
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

