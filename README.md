# Cpp-Repo

# Dynamic Array Implementation in C++

This program is a basic implementation of a list data structure using dynamic arrays in C++. It includes operations for creating a list, inserting values at specific locations, updating values, copying the list, and displaying the list. The program also includes error handling for invalid operations such as inserting or updating at an invalid index, copying an empty list, and memory allocation failures.

## Features

- **Dynamic Array:** The list is implemented as a dynamic array that automatically resizes itself as needed.
- **Insertion:** You can insert a value at any valid index in the list.
- **Update:** You can update the value at any valid index in the list.
- **Copy:** You can create a copy of the list.
- **Display:** You can display the contents of the list.

## Usage

1. Compile the program using any C++ compiler.
2. Run the program. You will be prompted to enter a number and a position.
3. Enter the number you want to insert and the position at which you want to insert it.
4. You will be prompted again to enter a number to insert at position 1.
5. Enter the number you want to insert at position 1.
6. The program will display the contents of the list after each operation.

## Error Handling

The program includes robust error handling:

- If you try to insert or update at an invalid index, the program will print an error message and ignore the operation.
- If you try to copy an empty list, the program will print an error message and return a null pointer.
- If memory allocation fails when creating or resizing the array, the program will print an error message and exit or ignore the operation as appropriate.

## Future Improvements

This is a basic implementation and does not include all possible features of a list data structure. Future improvements may include additional operations such as deletion, search, and sort.


