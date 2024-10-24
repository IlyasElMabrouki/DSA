#include <iostream>
using namespace std;

struct vecteur{
    int *data;
    int taille;
    vecteur(int);
    void remplir();
    void afficher();
};

vecteur::vecteur (int taille){
    this->taille = taille;
    data = new int[taille];
}

void vecteur::remplir(){
    for (int i=0;i<taille;i++){
        cout << "Saisir une valeur:\n";
        cin >> data[i];
    }
}

void vecteur::afficher(){
    for (int i=0;i<taille;i++){
        cout << data[i] << "\t";
    }
}

int main(){
    vecteur v(4);
    v.remplir();
    v.afficher();
    return 0;
}