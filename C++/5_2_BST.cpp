#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *createLeaf(int val);
    Node *max(Node *);
    Node *min(Node *);
    Node *succ(Node *);
    Node *pred(Node *);
    Node *insertion(Node *, int);
    Node *remove(Node *, int);
    Node *find(Node *, int);
};

Node *Node::max(Node *root)
{
    if (!root || !root->right)return root;
    return max(root->right);
}

Node *Node::min(Node *root)
{
    if (!root || !root->left)
        return root;
    return min(root->left);
}

// the node have a right subtree, the successor is the minimum of the right subtree
Node *Node::succ(Node *node)
{
    if (!node || !node->right) return nullptr;
    return min(node->right);
}

// the node have a left subtree, the predessor is the maximum of the left subtree
Node *Node::pred(Node *node)
{
    if (!node || !node->left)
        return nullptr;
    return max(node->left);
}

Node *Node::find(Node *root, int val)
{
    if (root == nullptr || root->data == val) return root;
    if (root->data > val) return find(root->left, val);
    return find(root->right, val);
}

Node *Node::createLeaf(int val)
{
    Node *temp = new Node();
    temp->left = temp->right = nullptr;
    temp->data = val;
    return temp;
}

Node *Node::insertion(Node *root, int val)
{
    if (root == nullptr) return createLeaf(val);
    // root-> right = ... est essentiel pour établir la liaison avec parent
    if (val > root->data) root->right = insertion(root->right, val);
    // meme chose
    else root->left = insertion(root->left, val);
    // retourner l'adresse du root
    return root;
}

Node *Node::remove(Node *root, int val){
    Node* nodeToDelete = find(root, val);

    if (nodeToDelete == NULL) return root;

    // Case 1: Node to be deleted has no children
    if (nodeToDelete->left == NULL && nodeToDelete->right == NULL) {
        delete nodeToDelete;
        nodeToDelete = NULL;
    }

    // Case 2: Node to be deleted has one child
    else if (nodeToDelete->left == NULL) {
        Node* temp = nodeToDelete;
        nodeToDelete = nodeToDelete->right;
        delete temp;
    } 
    else if (nodeToDelete->right == NULL) {
        Node* temp = nodeToDelete;
        nodeToDelete = nodeToDelete->left;
        delete temp;
    }

    // Case 3: Node to be deleted has two children
    else {
        Node* temp = succ(nodeToDelete);
        nodeToDelete->data = temp->data;
        nodeToDelete->right = remove(nodeToDelete->right, temp->data);
    }
    return root;
}
