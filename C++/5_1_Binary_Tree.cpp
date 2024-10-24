#include <iostream>
#include <math.h>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node *createNode(int);
    void preOrder(Node *);
    void inOrder(Node *);
    void postOrder(Node *);
    void LevelOrder(Node*);
    int getSize(Node *);
    int leafCount(Node *);
    int height(Node *);
    int is_not_degenerate(Node *);
    int search(Node *,int);
};

Node *Node::createNode(int data)
{
    Node *a = new Node();
    a->data = data;
    a->left = nullptr;
    a->right = nullptr;
    return a;
}

void Node::preOrder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void Node::inOrder(Node *root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void Node::postOrder(Node *root){
    if (root == nullptr)return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void Node::LevelOrder(Node *root){
    //1.Initialisation de la file (Queue)
    Queue q;
    Node *x;
    q.enqueue(root);
    //2.Boucle sur le contenu de la file
    while (!q.isEmpty()){
        x = q.dequeue();
        cout << x->data;
        if (x->left != NULL) q.enqueue(x->left);
        if (x->right != NULL) q.enqeue(x->right);
    }
}

int Node::getSize(Node *root){
    if (root == nullptr) return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

int Node::leafCount(Node *root){
    if (root == nullptr) return 0;
    if (!root->left && !root->right) return 1;
    return leafCount(root->left) + leafCount(root->right);
}


int Node::height(Node *root){
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int is_not_degenerate(Node *root){
    if (root == NULL) return 0;
    if (root->left != NULL && root->right != NULL) return 1;
    if (root->left == NULL) return is_not_degenerate(root->right);
    return is_not_degenerate(root->left);
}

//Retourne 0 dans le cas d'inéxistance et 1 dans le cas d'existance
int search(Node *root, int val){
    if (root == NULL) return 0;
    //Cas du root contient la valeur recherché
    if (root->data == val) return 1;
    //On passe à la recherche dans le fils gauche si elle retourne 1 on retourne aussi 1
    if (search(root->left,val) == 1) return 1;
    //Si elle retourne 0 on recherche dans le fils droite
    return search(root->right,val); 
}
