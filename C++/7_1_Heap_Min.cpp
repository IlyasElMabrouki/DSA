#include <iostream>
using namespace std;
#define MAXSIZE 100

struct Heap{
    int size;
    int items[MAXSIZE];
    
    int getParentIndex(int childIndex) { return (childIndex - 1) / 2;}
    bool hasParent(int index) { return getParentIndex(index) >= 0; }
    int parent(int index) { return items[getParentIndex(index)]; }

    int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
    bool hasLeftChild(int index) { return getLeftChildIndex(index) < size; }
    int leftChild(int index) { return items [getLeftChildIndex(index)];}

    int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }
    bool hasRightChild(int index) { return getRightChildIndex(index) < size; }
    int rightChild(int index) { return items [ getRightChildIndex(index)]; }

    void swap (int index1, int index2);
    int peek();
    int deletion();
    void insertion(int);
    void heapifyUp();
    void heapifyDown();
};

//Pemutation
void Heap::swap(int index1, int index2){
    int temp = items[index1];
    items[index1] = items[index2];
    items[index2] = temp; 
}

// return the root of the heap
int Heap::peek(){
    if (size == 0)return -1;
    return items[0];
}

void Heap::heapifyUp(){
    //récupération de l'index de l'élément ajouté
    int index = size-1;
    while (hasParent(index) && parent(index) > items[index]){
        //Appliquer la permutation
        swap(getParentIndex(index),index);
        //Recupérer l'index du parent pour l'utiliser dans l'itération suivante
        index = getParentIndex(index);
    }
}

void Heap::heapifyDown(){
    int index = 0;
    //si on n'a pas de left child on aura pas aussi rigth child (regle 1)
    while (hasLeftChild(index)) {
        //Trouver valeur min entre gauche et droite
        int smallerChildIndex  = getLeftChildIndex(index);
        if (hasRightChild(index) && rightChild(index) < leftChild(index)) {
            smallerChildIndex = getRightChildIndex(index);
        }
        //Cas dans le nouveau noeud est le plus petit
        if (items[index] < items[smallerChildIndex]) break;
        else {
            swap(index, smallerChildIndex);
            index = smallerChildIndex;
        }
    }
}

int Heap::deletion(){
    if (size == 0) return -1;
    int root = items[0];
    items[0] = items[size - 1];
    size--;
    heapifyDown();
    return root;
}

// Insertion
void Heap::insertion(int val){
    if (size == MAXSIZE) return;
    items[size] = val;
    size++;
    heapifyUp();
}
