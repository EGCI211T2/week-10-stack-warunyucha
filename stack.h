#ifndef stack_h
#define stack_h
#include "node.h"

class Stack {
    NodePtr top;
    int size;
public:
    void push(int);
    int pop();
    Stack();
    ~Stack();
};

void Stack::push(int x){
    NodePtr new_node = new NODE(x);  // Create new node
    if (new_node) {
        new_node->set_next(top);  // Point the new node's 'next' to the current top
        top = new_node;        // Set the new node as the top of the stack
        size++;                // Increment the size of the stack
    }
    else cout << "Not enough memory. "<< endl;
}

int Stack::pop(){


    if (top != nullptr){ 

    NodePtr t = top;
    int value = t->get_value();   
    top = top->get_next();      
    --size;          
    delete t;                    
    return value;
    }
    cout << "Empty stack ."<<endl;
    return 0;

}

Stack::Stack() {
    top = nullptr;
    size = 0;
}

Stack::~Stack(){
    cout << "Clear the stack" << endl;
    int n = size;
    while (n>0){
        pop();
        n--;
    }
}

#endif
