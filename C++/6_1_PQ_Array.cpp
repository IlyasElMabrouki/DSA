#include <iostream>
#include <cassert>
using namespace std;
#define SIZE_MAX 100

//Queue de priorité d'un Tableau trié
struct PQ {
    int size;
    int data[SIZE_MAX];
    PQ();
    int getSize();
    bool isEmpty();
    bool isFull();
    void insert(int);
    int Delete();
};

PQ::PQ(){
    size = 0;
}

int PQ::getSize(){
    return size;
}

bool PQ::isEmpty(){
    return size==0;
}

bool PQ::isFull(){
    return size==SIZE_MAX;
}

//Insérer dans la bonne position
void PQ::insert(int value){
    if (isFull()) return;
    int i = size - 1;
    while (i >= 0 && value > data[i]) {
        data[i + 1] = data[i];
        i--;
    }
    // Insert the new element at the correct position
    data[i + 1] = value;
    size++;
}

//Supprimer en décalant le reste
int PQ::Delete(){
    if (isEmpty()) return -1;
    int temp = data[0];
    for (int i = 0; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
    return temp;
}


