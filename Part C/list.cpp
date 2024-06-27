#include <iostream>
#include "list.h"

using namespace std;
/* PART B */
/* Stacks using Linked Lists */

/* 
Linked Lists with Sentinels 
[X]<->[7]<->[3]<->[2]<->[X]
The head and tails are dummy elements ([X]) that do not have valid values.
These are called sentinel elements.
*/

    
    List::List() : size(0){
        sentinel_head = new Node(true);
        sentinel_tail = new Node(true);

        sentinel_head->next = sentinel_tail;
        sentinel_tail->prev = sentinel_head;

        
    }

    List::~List(){
        while(sentinel_head->next != sentinel_tail){
            Node *temp = sentinel_head->next;
            sentinel_head->next = temp;
            delete temp;
            }

        delete sentinel_head;
        delete sentinel_tail;
    }

    // Insert an element at the tail of the linked list 
    void List::insert(int v){
        Node *newnode= new Node(v);
        Node *lastnode = sentinel_tail->prev; //as prev of tail points to the current last node
        newnode->next = sentinel_tail;
        sentinel_tail->prev = newnode;
        newnode->prev = lastnode;
        lastnode->next = newnode;

        size++;
    }

    // Delete the tail of the linked list and return the value
    // You need to delete the valid tail element, not the sentinel
    int List::delete_tail(){
        Node *tail = sentinel_tail->prev;
        Node *prevtail = tail->prev;

        int resultval = tail->get_value();
        tail->next = NULL;
        tail->prev == NULL;

        delete tail;

        prevtail->next = sentinel_tail;
        sentinel_tail->prev = prevtail;
        size--;
        return resultval;
    }

    // Return the size of the linked list 
    // Do not count the sentinel elements
    int List::get_size(){
        return size;
} 

    // Return a pointer to the sentinel head of the linked list 
    Node* List::get_head(){
        return sentinel_head;
    }
    
    
   
        


