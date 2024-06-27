#ifndef STACK_A_H
#define STACK_A_H

class Stack_A {
public:
    Stack_A(); // Constructor
    
    void push(int e); // Push an element onto the stack
    int pop(); // Pop an element from the stack
    int add(); // Add top two elements
    int subtract(); // Subtract top two elements
    int multiply(); // Multiply top two elements
    int divide(); // Divide top two elements
    
    int* get_stack(); // Get the stack
    int get_size(); // Get the current size of the stack
    int get_element_from_top(int idx); // Get element from the top with index
    int get_element_from_bottom(int idx); // Get element from the bottom with index
    void print_stack(bool top_or_bottom); // Print the stack, top to bottom if true, bottom to top if false
private:
    int stk[1024]; // Fixed size array for the stack
    int size; // Current size of the stack
};

#endif // STACK_A_H
