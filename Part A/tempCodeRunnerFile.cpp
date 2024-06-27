#include"stack_a.h"
#include <stdexcept>
#include <iostream>
using namespace std; 

/* PART A */
/* Stacks using Fixed Size stkays */



        Stack_A::Stack_A():size(0){
            
        }
        
        
        void Stack_A::push(int e){
            if(size>=1024){
                throw std::runtime_error("Stack Full");
            }else{
                stk[size] = e;
                size++;
                
            }
        }


        int Stack_A::pop(){
            if(size==0){
                throw std::runtime_error("Empty Stack");
            }else{
                int Topelement = stk[size-1];
                size--;
                return Topelement;
            }

        }

        int Stack_A::add(){
            
           
            
            if(size>=2){
            int first_element = pop();
            int second_element = pop();
            
            push(first_element + second_element);
            return first_element + second_element;
            }else{
                throw std::runtime_error("Not Enough Arguments");
            }
            
        }

        int Stack_A::subtract(){
            
           
            if(size>=2){
            int first_element = pop();
            int second_element = pop();
            int result = second_element - first_element;
            push(result);
            return result;
            }else{
                throw std::runtime_error("Not Enough Arguments");
            }
        }


        int Stack_A::multiply(){
            
            
            if(size>=2){
            int first_element = pop();
            int second_element = pop();
            int result = first_element*second_element;
            push(result);
            return result;
            }else{
                throw std::runtime_error("Not Enough Arguments");
            }
        }

int Stack_A::divide() {
            if (size < 2) {
        throw std::runtime_error("Not Enough Arguments");
            } else {
        int first_element = pop();  // Second top
        int second_element = pop(); // Top

        if (second_element != 0) {
            float result = static_cast<float>(second_element) / first_element;

            if (second_element % first_element == 0 || result >= 0) {
                push(static_cast<int>(result));
                return static_cast<int>(result);
            } else {
                push(static_cast<int>(result - 1));
                return static_cast<int>(result - 1);
            }
        } else {
            throw std::runtime_error("Divide by Zero Error");
        }
    }
}


         int* Stack_A::get_stack() {
        return stk;
    }

        
        int Stack_A::get_size(){
            if(size<=0){
                return 0;
            }else{
                return size;
            }
        }


        int Stack_A::get_element_from_top(int idx){
            if(size<=0){
                throw std::runtime_error("Index out of range");
            }else if(size-idx<=0){
                throw std::runtime_error("Index out of range");
            }else{
                
                return stk[size-1-idx];
            }
        }


        int Stack_A::get_element_from_bottom(int idx){
            if(idx>=size || idx<0){
                throw std::runtime_error("Index out of range");
            }else{
                
                return stk[idx];
            }
        }

        void Stack_A::print_stack(bool top_or_bottom){
        if(size==0){
            return;
        }else{
            if(top_or_bottom == true){
                for(int i=size-1;i>=0;i--){
                    cout<<stk[i]<<" ";
                    
                }
            }else{
                for(int i =0;i<=size-1;i++){
                    cout<<stk[i]<<" ";
                    
                }
            }
        }    
            
            
    }