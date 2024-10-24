#include <iostream>
using namespace std;

class TasMax {
    private:
        int size;
        int maxSize;
        int *tab;
    public:
        TasMax(int maxSize);
        int Max();

        int getParentIndex(int childIndex) { return (childIndex - 1) / 2;}
        bool hasParent(int index) { return getParentIndex(index) >= 0; }
        int parent(int index) { return tab[getParentIndex(index)]; }

        int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
        bool hasLeftChild(int index) { return getLeftChildIndex(index) < size; }
        int leftChild(int index) { return tab[getLeftChildIndex(index)];}

        int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }
        bool hasRightChild(int index) { return getRightChildIndex(index) < size; }
        int rightChild(int index) { return tab[ getRightChildIndex(index)]; }

        void swap (int index1, int index2);
        int deletion();
        void insertion(int);
        void heapifyUp(int);
        void heapifyDown(int);
        int* tri(int t[],int n);
};

TasMax::TasMax(int maxSize){
    size = 0;
    this->maxSize = maxSize;
    tab = new int[maxSize];
}

int TasMax::Max(){
    if (size==0) return -1;
    return tab[0];
}

void TasMax::swap(int index1, int index2){
    int temp = tab[index1];
    tab[index1] = tab[index2];
    tab[index2] = temp; 
}

void TasMax::heapifyUp(int index){
    //récupération de l'index de l'élément ajouté
    while (hasParent(index) && parent(index) < tab[index]){
        //Appliquer la permutation
        swap(getParentIndex(index),index);
        //Recupérer l'index du parent pour l'utiliser dans l'itération suivante
        index = getParentIndex(index);
    }
}

void TasMax::heapifyDown(int index){
    //si on n'a pas de left child on aura pas aussi rigth child (regle 1)
    while (hasLeftChild(index)) {
        //Trouver valeur min entre gauche et droite
        int greaterChildIndex  = getLeftChildIndex(index);
        if (hasRightChild(index) && rightChild(index) > leftChild(index)) {
            greaterChildIndex = getRightChildIndex(index);
        }
        //Cas dans le nouveau noeud est le plus petit
        if (tab[index] > tab[greaterChildIndex]) break;
        else {
            swap(index, greaterChildIndex);
            index = greaterChildIndex;
        }
    }
}

void TasMax::insertion(int val){
    if (size == maxSize){
        int *temp = new int[maxSize * 2];
        for (int i=0;i<size;i++){
            temp[i] = tab[i];
        }
        delete[] tab;
        tab = temp;
        maxSize = maxSize * 2;
        tab[size] = val;
    }
    tab[size] = val;
    size++;
    heapifyUp(size-1);
}

int TasMax::deletion(){
    if (size == 0) return -1;
    int root = tab[0];
    tab[0] = tab[size - 1];
    if (size-1 == maxSize/2){
        int *temp = new int[maxSize * 2];
        for (int i=0;i<size;i++){
            temp[i] = tab[i];
        }
        delete[] tab;
        tab = temp;
        maxSize = maxSize / 2;
    }
    size--;
    heapifyDown(0);
    return root;
}

int* TasMax::tri(int t[], int n){
    TasMax *tas = new TasMax(n);
    for (int i=0;i<n;i++){
        tas->insertion(t[i]);
    }
    for (int i=0;i<n;i++){
        t[i] = tas->deletion();
    }
    delete tas;
    return t;
}

int main(){
    TasMax *tas = new TasMax(5);

    tas->insertion(10);
    tas->insertion(20);
    tas->insertion(30);
    cout << tas->deletion() << "\n";
    cout << tas->Max() << "\n";

    int t[] = {1,3,6,12,2};
    int *t_tri = tas->tri(t,5);
    for (int i=0;i<5;i++) cout << t_tri[i] << "\t";
    return 0;
}
