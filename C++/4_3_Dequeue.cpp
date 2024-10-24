#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *next;
    Node *prev;
    Node(int value,Node* next=nullptr,Node* prev=nullptr);
    void print()const;
};

Node::Node(int value,Node* next, Node* prev){
    this->value=value;
    this->next=next;
    this->prev = prev;
}

void Node::print()const{
    cout<<value<<" ->";
}

struct Dequeue {
    Node* front;
    Node* tail;
    int size;

    Dequeue();
    void InsertFirst(int);
    void InsertLast(int);
    Node* DeleteFirst();
    Node* DeleteLast();
    Node* getFirst();
    Node* getLast();
    int getSize();
    bool isEmpty();
};

Dequeue::Dequeue(){
    front = tail = NULL;
    size = 0;
}

Node* Dequeue::getFirst(){
    if (isEmpty()) return nullptr;
    return front;
}

Node* Dequeue::getLast(){
    if (isEmpty()) return;
    return tail;
}

bool Dequeue::isEmpty(){
    return (front == NULL);
}

int Dequeue::getSize(){
    return size;
}

void Dequeue::InsertFirst(int val) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
        front= tail = newNode;
    } 
    else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    size++;
}

Node* Dequeue::DeleteFirst(){
    Node *todelete = front, *temp = front;
    //Liste Vide
    if (front == nullptr) return temp;
    //Liste a un seul élément
    else if (front == tail){
        front = tail = nullptr;
    }
    else {
        front->prev = nullptr;
        front = front->next;
    }
    size--;
    delete todelete;
    return temp;
}

void Dequeue::InsertLast(int val){
    Node* newNode = new Node(val);
    if (isEmpty()) {
        front = tail = newNode;
    } 
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

Node *Dequeue::DeleteLast(){
    Node *toDelete = tail, *temp = tail;
    if (isEmpty()) return nullptr;
    if (front == tail){
        front = tail = nullptr;
    }
    else {
        tail->prev = NULL;
        tail = tail->prev;
    }
    delete toDelete;
    return temp;
}
