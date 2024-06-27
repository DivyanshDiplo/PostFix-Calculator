#ifndef STACK_B_H
#define STACK_B_H

#include <string>

class Stack_B {
public:
    Stack_B(); // Constructor
    ~Stack_B(); // Destructor
    
    void push(int a); // Push an element onto the stack
    int pop(); // Pop an element from the stack
    int add(); // Add the top two elements
    int subtract(); // Subtract the top two elements
    int multiply(); // Multiply the top two elements
    int divide(); // Divide the top two elements
    
    int* get_stack(); // Get the stack array
    int get_size(); // Get the current size of the stack
    int get_element_from_top(int idx); // Get element from the top by index
    int get_element_from_bottom(int idx); // Get element from the bottom by index
    void print_stack(bool top); // Print the stack (top to bottom if true, bottom to top if false)
    
private:
    int* stk; // Pointer to the stack array
    int size; // Current size of the stack
    int capacity; // Current capacity of the stack
};

#endif // STACK_B_H
