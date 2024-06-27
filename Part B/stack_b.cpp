#include"stack_b.h"
#include <iostream>
#include <stdexcept>

using namespace std;


    Stack_B::Stack_B() : size(0), capacity(1024) {
    stk = new int[capacity];
}

    Stack_B::~Stack_B() {
    delete[] stk;
    }



void Stack_B::push(int a){
    
    if(size  == capacity){
        int newsize = capacity*2;
        int *newArr = new int[newsize];
        for(int i=0;i<size;i++){                       //make new stack and copy former stack to new stack
        newArr[i]= stk[i];
    }
        capacity = newsize;
        delete[] stk;
        stk = newArr;
        
    }
    stk[size] = a;
    size++;

}

int Stack_B::pop(){
    if(size==0){
        throw runtime_error("Empty Stack");
    }else{
        int last_element = stk[size-1];
        size--;
        //changing size
        if(size <= capacity/2 && capacity > 1024){
            int newsize = capacity/2;
            int *newArr = new int[newsize];
            for(int i=0;i<size;i++){                      
                newArr[i]= stk[i];
            }

            delete[] stk;
            stk = newArr;
            capacity = newsize;
        }
        
        return last_element;
    }

}




int Stack_B::add(){
            
            
            
            if(size>=2){
                int first_element = pop();
                int second_element = pop();
                int result = first_element + second_element;
                push(result);

                if(size < capacity/2 && capacity > 1024){
                    int newsize = capacity*2;
                    int *newArr = new int[newsize];
                    for(int i=0;i<size;i++){                       //make new stack and copy former stack to new stack
                        newArr[i]= stk[i];
                    }

                    delete[] stk;
                    stk = newArr;
                    capacity = newsize;
                }
                return result;
            }else{
                throw std::runtime_error("Not Enough Arguments");
            }
            
        }


int Stack_B::subtract(){
            
            
            if(size>=2){
            int first_element = pop();
            int second_element = pop();
            int result = second_element - first_element;
            push(result);
            if(size <= capacity/2 && capacity > 1024){
                int newsize = capacity/2;
                int *newArr = new int[newsize];
                for(int i=0;i<size;i++){                      
                    newArr[i]= stk[i];
                }

                delete[] stk;
                stk = newArr;
                capacity = newsize;
        }
            return result;
            }else{
                throw std::runtime_error("Not Enough Arguments");
            }
        }
 

int Stack_B::multiply(){
            
            
            if(size>=2){
            int first_element = pop();
            int second_element = pop();
            int result = first_element*second_element;
            push(result);
            if(size <= capacity/2 && capacity > 1024){
            int newsize = capacity/2;
            int *newArr = new int[newsize];
            for(int i=0;i<size;i++){                      
                newArr[i]= stk[i];
            }

            delete[] stk;
            stk = newArr;
            capacity = newsize;
        }
            return result;
            }else{
                throw std::runtime_error("Not Enough Arguments");
            }
        }



int Stack_B::divide(){
    if (size < 2){
        throw std::runtime_error("Not Enough Arguments");
    }else{
        int first_element = pop();  // Second top
        int second_element = pop(); // Top
         if(size <= capacity/2 && capacity > 1024){
                    int newsize = capacity/2;
                    int *newArr = new int[newsize];
                        for(int i=0;i<size;i++){                      
                            newArr[i]= stk[i];
                        }

                        delete[] stk;
                        stk = newArr;
                        capacity = newsize;
                    }
        if(second_element != 0) {
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

            
       
            
               


int* Stack_B::get_stack() {
        return stk;

}


int Stack_B:: get_size(){
            if(size<=0){
                return 0;
            }else{
                return size;
            }
}


int Stack_B::get_element_from_top(int idx){
            if (idx >= 0 && idx < size) {
                return stk[size-1-idx];
                
            }else{
                
                throw std::runtime_error("Index out of range");
            }
        }


int Stack_B::get_element_from_bottom(int idx){
            if(idx >=0 && idx<size){
                return stk[idx];
                throw std::runtime_error("Index out of range");
            }else{
                
                throw std::runtime_error("Index out of range");
            }
        }


void Stack_B::print_stack(bool top){
    if(size==0){
            return;
        }else{
            if(top == true){
            for(int i=size-1;i>=0;i--){
                cout<<stk[i];
                cout<<"\n";
            }
            }else{
                for(int i =0;i<size;i++){
                    cout<<stk[i];
                    cout<<"\n";
                }
            }
        }
        
            
    }       



