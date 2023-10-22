#include<iostream>
#include<climits>
using namespace std;

class List {
    int *arr; // Pointer to dynamic array
    int capacity; // Maximum capacity of array
    int size; // Current size of array

public:
    // Constructor
    List() {
        // Allocate initial capacity of 1
        arr = new (nothrow) int[1];
        if (!arr) {
            cout << "Error: Memory allocation failed" << endl;
            exit(1);
        }
        capacity = 1;
        size = 0;
    }

    // Insert data at specific index
    void insert(int data, int index) {
        // Check for valid index
        if (index < 0 || index > size) {
            cout << "Error: Invalid index" << endl;
            return;
        }
        
        // Check for overflow and resize array if necessary
        if (size == capacity) {
            if (capacity > INT_MAX / 2) {
                cout << "Error: Maximum capacity reached" << endl;
                return;
            }
            
            // Allocate new array with double capacity
            int *temp = new (nothrow) int[2 * capacity];
            if (!temp) {
                cout << "Error: Memory allocation failed" << endl;
                return;
            }
            
            // Copy old array to new array
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            
            delete[] arr; // Delete old array
            capacity *= 2; // Double the capacity
            arr = temp; // Point to new array
        }
        
        // Shift elements to right of index to make space for new data
        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }
        
        arr[index] = data; // Insert data at index
        size++; // Increase size
    }

    // Update data at specific index
    void update(int data, int index) {
        // Check for valid index
        if (index < 0 || index >= size) {
            cout << "Error: Invalid index" << endl;
            return;
        }
        
        arr[index] = data; // Update data at index
    }

    // Copy list to a new list and return pointer to it
    List* copy() {
        // Check if list is empty
        if (size == 0) {
            cout << "Error: List is empty" << endl;
            return nullptr;
        }
        
        List *newList = new List(); // Create new list
        
        newList->arr = new (nothrow) int[capacity]; // Allocate new array with same capacity
        
        if (!newList->arr) { // Check for memory allocation failure
            cout << "Error: Memory allocation failed" << endl;
            delete newList; // Delete new list to avoid memory leak
            return nullptr;
        }
        
        newList->capacity = capacity; // Copy capacity
        newList->size = size; // Copy size
        
        for (int i = 0; i < size; i++) { // Copy elements from old array to new array
            newList->arr[i] = arr[i];
        }
        
        return newList; // Return pointer to new list
    }

    // Display elements of list on console
    void display() {
        if (size == 0) { // Check if list is empty
            cout << "Error: List is empty" << endl;
            return;
        }
        
        for (int i = 0; i < size; i++) { 
            cout << arr[i] << " "; 
        }
        
        cout << endl;
    }

    ~List() { 
      delete[] arr; 
    } 
};

int main() {
    List l;

    int num;
    
    cout << "Enter a number: ";
    
    cin >> num;

    if (cin.fail()) {
      cin.clear(); 
      cin.ignore(INT_MAX, '\n'); 
      cout << "Invalid input. Please enter a number." << endl;
      return 1;
    }
    int pos;

    cout << "Enter The index/position you wanna store the number: ";

    cin >> pos;

    l.insert(num, pos);
    
    cout << "Enter a number to insert at position 1: ";
    
    cin >> num;

    if (cin.fail()) {
      cin.clear(); 
      cin.ignore(INT_MAX, '\n'); 
      cout << "Invalid input. Please enter a number." << endl;
      return 1;
    }

    l.insert(num, 1);
    
    l.display();
    
    cout << "Enter a number to update your position: ";
    
    cin >> num;

    if (cin.fail()) {
      cin.clear(); 
      cin.ignore(INT_MAX, '\n'); 
      cout << "Invalid input. Please enter a number." << endl;
      return 1;
    }

    l.update(num, pos);
    
    l.display();
    
    List *l2 = l.copy();
    
    if (l2 != nullptr) {
      l2->display();
      delete l2; 
    }
    
    return 0;
}
