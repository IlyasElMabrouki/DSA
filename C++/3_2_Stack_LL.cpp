#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Stack_LL {
private:
    Node *top;
    int size;
public:
    Stack_LL();
    void push(int);
    int pop();
    int getSize();
    bool isEmpty();
    int peek();
};

Stack_LL::Stack_LL(){
    top = NULL;
    size = 0;
}

int Stack_LL::getSize(){
    return size;
}

bool Stack_LL::isEmpty(){
    return (top == NULL);
}

int Stack_LL::peek(){
    if (isEmpty()){
        cout << "Stack UnderFlow";
        return -1;
    }
    return top->data;
}

void Stack_LL::push(int value){
    //Create node
    Node *node = new Node();
    //affect to the node the data in the args
    node->data = value;
    //affect to the node the adress of the actual first node
    node->next = top;
    //update the adress of top to the first node which is the one we have created
    top = node;
    size++;
}

int Stack_LL::pop(){
    if (isEmpty()){
        cout << "Stack UnderFlow";
        return -1;
    }
    //store the deleted node in a temp variable
    Node *temp = top;
    //store the data of the deleted node
    int tempValue = temp->data;
    //update the top pointer to the second node
    top = top->next; 
    //free the node
    delete temp;
    size--;
    return tempValue;
}