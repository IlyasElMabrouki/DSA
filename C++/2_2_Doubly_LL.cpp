#include<iostream>
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

struct LinkedList{
    Node *head,*tail;
    int size;
    void add(int);
    Node* moveFirst();
    Node* moveNext(Node*);
    Node* movePrevious(Node*);
    void print();
};

Node* LinkedList::moveFirst() {
    return head;
}

Node* LinkedList::moveNext(Node *node) {
    if (head == nullptr) return;
    return node->next;
}

Node* LinkedList::movePrevious(Node *node) {
    if (head == nullptr) return;
    return node->prev;
}

void LinkedList::add(int val) {
    Node *temp;
    if (head == nullptr) {
        head = new Node(val);
    }
    else {
        Node *temp = new Node(val,head,nullptr);
        head->prev = temp;
        head = temp;
    }
    size++;
}

void LinkedList::print(){
    if (head == nullptr) return;
    cout << "Taille: " << size;
    Node *temp = head;
    while (head != nullptr) {
        head->print();
        head = head->next;
    } 
}