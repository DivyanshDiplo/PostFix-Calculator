#include "node.h"
#include <iostream>
using namespace std;

/* PART B */
/* Stacks using Linked Lists */


    // Use to construct a sentinel node (see list.h)
    Node::Node(bool sentinel): is_sentinel(sentinel), value(0){
        next = NULL;
        prev = NULL;
        
    }

    // Use to construct a regular node
    Node::Node(int v,Node* nxt, Node* prv){
       next = nxt;
       prev = nxt;
       value = v;
       is_sentinel = false;

    }

    // Return whether a node is a sentinel node 
    // Use it to check if we are at the ends of a list
    bool Node::is_sentinel_node(){
        return is_sentinel;
    }

    // Return the value of a node
    int Node::get_value(){
        return value;
    }


