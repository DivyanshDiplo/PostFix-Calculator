#include <iostream>
#include "stack_c.h"
#include <stdexcept>
using namespace std;
/* PART  */
/* Stacks using Linked Lists */


 
    // Constructor
    Stack_C::Stack_C(){
        stk = new List();
        
    }

    // Destructor
    Stack_C::~Stack_C(){
        delete stk ;
    }

    void Stack_C::push(int data){
        stk->insert(data);
        
    }

    int Stack_C::pop(){
        
        if(stk->get_size()==0){
            throw std::runtime_error("Empty Stack");
        }else{
        int tailval = stk->delete_tail();
        return tailval;
        }
    }

    int Stack_C::get_element_from_top(int idx){
        if(idx<0){
            throw std::runtime_error("Index out of range");
        }
        if(idx>stk->get_size()){
            throw std::runtime_error("Index out of range");
        }
        Node *ptr = stk->get_head()->next;
        while(ptr->next == NULL){
            ptr = ptr->next;
        }
        
        for(int i=1;i<=idx;i++){
            ptr = ptr->prev;

        }
        return ptr->get_value();
    }

    int Stack_C::get_element_from_bottom(int idx){
        if(idx<0){
            throw std::runtime_error("Index out of range");
        }
        if(idx>stk->get_size()){
            throw std::runtime_error("Index out of range");
        }

        Node *ptr = stk->get_head()->next;
        
        for(int i=0;i<=idx;i++){
            ptr = ptr->next;

        }
       
        return ptr->get_value();

    }

    void Stack_C::print_stack(bool top_or_bottom){
        
        if(stk->get_size()==0){
            return;
        }else{
            if(top_or_bottom == true){
            Node *ptr = stk->get_head()->prev;
            while(ptr->next == NULL){
                ptr = ptr->next;
            }
            for(int i=1;i<=stk->get_size();i++){
                cout<<ptr->get_value();
                cout<<"\n";
                ptr = ptr->prev;
            }
            }else{
                Node *ptr = stk->get_head()->next;
                for(int i=1;i<=stk->get_size();i++){
                    cout<<ptr->get_value();
                    cout<<"\n";
                    ptr = ptr->next;
                }

            }
        }
        
    }

    int Stack_C::add(){
        int listsize = stk->get_size() ;
        if(listsize>=2){
            int first_element = pop();
            int second_element = pop();
            push(first_element + second_element);
            return int(first_element + second_element);
        }else{
            throw std::runtime_error("Not Enough Arguments");
        }
        
    }

    int Stack_C::subtract(){
        int listsize = stk->get_size();
        if(listsize>=2){
            int first_element = pop();
            int second_element = pop();
            push(first_element - second_element);
            return int(first_element - second_element);
        }else{
            throw std::runtime_error("Not Enough Arguments");
        }
        
    }

    int Stack_C::multiply(){
        int listsize = stk->get_size() ;
        if(listsize>=2){
            int first_element = pop();
            int second_element = pop();
            push(first_element * second_element);
            return int(first_element * second_element);
        }else{
            throw std::runtime_error("Not Enough Arguments");
        }
        
    }

    int Stack_C::divide(){
        int listsize = stk->get_size() ;
        if(listsize>=2){
            int first_element = pop();
            int second_element = pop();
            if(second_element != 0){
                push(first_element / second_element);
                return int(first_element / second_element);
            }else{
                throw std::runtime_error("Divide by Zero Error");
            }
                
        }else{
            throw std::runtime_error("Not Enough Arguments");
        }
        
    } 

    List* Stack_C::get_stack() // Get a pointer to the linked list representing the stack
    {
        return stk;
    }

    int Stack_C::get_size() // Get the size of the stack
    {
        return stk->get_size() ;
    }



