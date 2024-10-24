#include <iostream>
using namespace std;
#define MAX 100

class Stack_Array{
private:
    int values[MAX];
    int top;
public:
    Stack_Array(){
        top = -1;
    }
    bool isFull();
    bool isEmpty();
    int size();
    int peek();
    void push(int);
    int pop();
};

bool Stack_Array::isFull(){
    return (top == MAX-1);
}

bool Stack_Array::isEmpty(){
    return (top == -1);
}

int Stack_Array::size(){
    return top + 1;
}

int Stack_Array::peek(){
    if (isEmpty()){
        cout << "Stack UnderFlow";
        return -1;
    }
    return values[top];
}

void Stack_Array::push(int data){
    if (isFull()){
        cout << "Stack OverFlow";
        return;
    }
    top++;
    values[top] = data;
}

int Stack_Array::pop(){
    if (isEmpty()){
        cout << "Stack UnderFlow";
        return -1;
    }
    int value = values[top];
    top--;
    return value;
}
