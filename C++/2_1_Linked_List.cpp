#include<iostream>
using namespace std;

class Node{
  public :
    int value;
    Node *next;
    Node(int value,Node* next=nullptr);
    void print()const;
};

Node::Node(int value,Node* next){
    this->value=value;
    this->next=next;
}

void Node::print()const{
    cout<<value<<" ->";
}

class LinkedList{
  private :
    Node *head,*tail,*cursor;
    int size;
  public :
    void moveFirst();
    void moveNext();
    void movePrevious();
    int getValue()const;
    bool hasNext()const;
    bool isEmpty()const;
    void add(int);
    void print()const;  
};

LinkedList::LinkedList(){
  head=tail=cursor=nullptr;
  size=0;
}

void LinkedList::moveFirst(){
  if(isEmpty())throw "moveFirst Exception: The list is empty!!!";
  cursor=head;
}

void LinkedList::moveNext(){
  if(isEmpty())throw "moveNext Exception: The list is empty!!!";
  cursor=cursor->next;
}

void LinkedList::movePrevious(){
  if(isEmpty())throw "movePrevious Exception: The list is empty!!!";
  if(cursor==tail)return;
  Node *temp=head;
  while(temp->next!=cursor)temp=temp->next;
  cursor=temp;
}

int LinkedList::getValue()const{
  if(isEmpty())throw "getValue Exception : The list is empty!!!";
  return cursor->value;
}

bool LinkedList::hasNext()const{
  return cursor->next!=nullptr;
}
    
bool LinkedList::isEmpty()const{
  return head==nullptr;
}
    
void LinkedList::add(int x){
  if(isEmpty())head=tail=cursor=new Node(x);
  else {
    cursor->next=new Node(x,cursor->next);
    cursor=cursor->next;
  }
  size++;
}
    
void LinkedList::print()const{
  if(isEmpty())
    cout<<"The list is empty!!!"<<endl;
  else{
    cout<<"size: "<<size<<endl;
    cout<<"Values: ";
    Node *temp=head;
    while(temp!=nullptr){
      temp->print();
      temp=temp->next;
    }
    cout<<endl;
  }
}  
