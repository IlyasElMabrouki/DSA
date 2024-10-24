#include <iostream>
using namespace std;
#define MAX 100

struct CircularQueue{
    int data[MAX];
    int front;
    int rear;

    CircularQueue();
    void enqueue(int);
    int dequeue();
    int size();
    bool isEmpty();
    bool isFull();
    int getFront();
};

CircularQueue::CircularQueue(){
    front = rear = -1;
}

bool CircularQueue::isEmpty(){
    if (front == -1 && rear == -1) return true;
    return false;
}

bool CircularQueue::isFull(){
    // CircualQueue est rempli si l'élément suivant du rear est front
    if ((rear + 1) % MAX == front) return true;
    return false;
}

int CircularQueue::size() {
    return (rear - front) + 1;
}

int CircularQueue::getFront(){
    if (isEmpty()) return -1;
    return data[front];
}

void CircularQueue::enqueue(int val){
    // Cas du queue full on sort immédiatement vue qu'on a plus d'espace
    if (isFull()) return;
    // Cas du queue empty on modifie les 2 indicateurs
    if (isEmpty())front = rear = 0;
    // Autre, on incremete rear par un
    else rear = rear + 1 % MAX;
    // Dans ces 2 derniers cas, on ajoute l'élément en utilisant la valeur dans parms
    data[rear] = val;
}

int CircularQueue::dequeue(){
    int temp;
    // Cas du queue vide on sort immédiatement vue qu'on a rien à supprimer
    if (isEmpty()) return -1;
    // Cas du queue contient qu'un seul élément, on retourne à l'etape initiale
    else if (front == rear){
        temp = front;
        front = rear = -1;
    }
    // Autre, on incremente front par 1 pour stocker l'index de l'élément suivant
    else {
        temp = front;
        front = front + 1 % MAX;
    }
    return data[temp];
}
