#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

struct QueueLL {
    Node* front;
    Node* tail;
    int size;

    QueueLL();
    void enqueue(int);
    Node* dequeue();
    int getSize();
    Node* getFront();
};


QueueLL::QueueLL(){
    front = tail = NULL;
    size = 0;
}

Node* QueueLL::getFront(){
    if (front == nullptr) return nullptr;
    return front;
}

int QueueLL::getSize(){
    return size;
}

void QueueLL::enqueue(int val){
    Node *node = new Node(val);
    //Cas de la création du premier noeud
    if (front == nullptr && tail == nullptr){
        front = tail = node;
    }
    //Cas de la création d'une niéme noeud
    else {
        tail->next = node;
        tail = node;
    }
    size++;
}

Node* QueueLL::dequeue(){
    Node *todelete = front, *temp = front;
    if (front == nullptr) return temp;
    //Suppression du seul élément de la liste
    else if (front == tail){
        front = tail = nullptr;
    }
    // Autre, on incremente front par 1 pour stocker l'index de l'élément suivant
    else{
        front = front->next;
    }
    size--;
    free(todelete);
    return temp;
}

