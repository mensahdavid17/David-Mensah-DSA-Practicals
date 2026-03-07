#include <iostream>

int size = 0;
struct Tnode{
    int data;
    Tnode *left;
    Tnode *right;
};


Tnode *root = NULL;


bool isEmpty(){
    return (size == 0);

}

int treeSize(){
    return size;
}

void insert(int value) {
    Tnode *temp = new Tnode; 
    temp->left = NULL;
    temp->right = NULL;
    temp->data = value;

    if (root == NULL) {
        root = temp;
        size++;
        return;
    }

    Tnode *current = root;
    Tnode *parent = NULL; 

    while (current != NULL) {
        parent = current;
        if (value > current->data) {
            current = current->right;
        } else if (value < current->data) {
            current = current->left;
        } else {
            delete temp; 
            return;
        }
    }

    if (value > parent->data) {
        parent->right = temp;
    } else {
        parent->left = temp;
    }
    size++;
}   

//function that returns the memory address of a particular node
Tnode* search(Tnode* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == value) {
        return root;
    }
    else if (value < root->data) {
        return search(root->left, value);
    }
    else {
        return search(root->right, value);
    }
}    

Tnode* findMin(Tnode* node) {
    Tnode* temp = node;
    while (temp && temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}


void deleteNode(Tnode*& root, int value) {
    if (root == NULL) {
        return;
    }

    if (value < root->data) {
        deleteNode(root->left, value);
    } else if (value > root->data) {
        deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            Tnode* temp = root->right;
            delete root;
            root = temp; 
        } else if (root->right == NULL) {
            Tnode* temp = root->left;
            delete root;
            root = temp; 
        }
        else {
            Tnode* temp = findMin(root->right);

            root->data = temp->data;

            deleteNode(root->right, temp->data);
        }
    }
}

void preOrder(Tnode *root){ //root, left right
    if (root != NULL){
        std::cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Tnode *root){ //left right root
    if (root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        std::cout << root->data << " ";
    }
}

void inOrder(Tnode *root){ //left root right
    if (root != NULL){
        inOrder(root->left);
        std::cout << root->data << " ";
        inOrder(root->right);
    }
}        

int main(){
    insert(10);
    insert(2);
    insert(30);
    insert(4);
    insert(5);
    insert(20);

    std::cout << "The Preoder traversal of the tree is = ";
    preOrder(root);
    printf("\n");

    std::cout << "The Inorder traversal of the tree is = ";
    inOrder(root);
    std::cout << "\n";

    std::cout << "The Postorder traversal of the tree is = ";
    postOrder(root);
    std::cout << "\n";

    deleteNode(root, 5);

    std::cout << "The Preoder traversal of the tree is = ";
    preOrder(root);
    std::cout << "\n";

    return 0;
}