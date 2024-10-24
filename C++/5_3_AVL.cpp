#include <iostream>
using namespace std;

//Structure du noeud qui contient height qui va nous aider à calculer la balance
struct Node {
    int data;
    struct Node *left, *right;
    int height;
};

Node *rightRotate(Node *y){
    //1.Déclaration + Affectation
    Node *x = y->left, *t = x->right;
    //2.modifications
    x->right = y;
    y->left = t;
    //3.Mettre à jour les hauteurs
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    //4.retourne nouveau parent
    return x;
}

Node *leftRotate(Node *x){
    Node *y = x->right, *t = y->left;
    y->left = x;
    x->right = t;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

int height(Node *node){
    if (node == NULL) return -1;
    return node->height;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

//Utiliser dans la fonction insert dans le cas d'un noeud racine
Node* createNode(int val){
    Node *temp = new Node();
    temp->left = temp->right = nullptr;
    temp->data = val;
    return temp;
}

int get_balance_factor(Node *node){
    if (node == NULL) return 0;
    return height(node->left) - height(node->right); 
}

Node* min(Node *root){
    if (!root || !root->left)
        return root;
    return min(root->left);
}

Node* succ(Node *node){
    if (!node || !node->right)
        return nullptr;
    return min(node->right);
}

Node* insert(Node *node, int value) {
    //1.Verifier root est null 
    if (node == NULL) return createNode(value);
    //2.Ajouter selon la comparaison de la valeur avec la valeur du root
    if (value < node->data) node->left = insert(node->left, value);
    else if (value > node->data) node->right = insert(node->right, value);
    else return node; //on ne gere pas se cas pour eviter les doublons
    //3.Mettre à jour le height du noeud
    node->height = 1 + max(height(node->left), height(node->right));
    //4.Récupérer la nouvelle balance
    int balance = get_balance_factor(node);

    // Left Left Case
    if (balance > 1 && value < node->left->data) return rightRotate(node);

    //Left Right Case
    if (balance > 1 && value > node->left->data){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && value > node->right->data) return leftRotate(node);

    //Right Left Case
    if (balance < -1 && value < node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node *remove(Node *root, int value){
    //1.Verifier si root est vide
    if (root == NULL) return root;
    //2.Chercher l'élément à supprimer
    if (value < root->data) root->left = remove(root->left, value);
    else if (value > root->data) root->right = remove(root->right, value);
    else {
        //Case 1 : Node to be deleted has no children
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }

        // Case 2: Node to be deleted has one child
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } 

        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }

        // Case 3: Node to be deleted has two children
        else {
            Node* temp = succ(root);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
    }
    //3.Verifier si l'élément qui a été supprimé est root 
    // (dans le cas le root a été le seul élément)
    if (root == NULL) return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = get_balance_factor(root);

    //Left Left Case
    if (balance > 1 && get_balance_factor(root->left) >= 0) return rightRotate(root);

    //Left Right Case
    if (balance > 1 && get_balance_factor(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //Right Right Case
    if (balance < -1 && get_balance_factor(root->right) <= 0) return leftRotate(root);

    //Right Left Case
    if (balance < -1 && get_balance_factor(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
   
    return root;
}
