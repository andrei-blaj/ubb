#include "bst.hpp"

#include <iostream>

using namespace std;

SortedBag::SortedBag() {
    root = NULL;
}

//SortedBag::SortedBag() { root = NULL; }

SortedBag::~SortedBag() {}

/////////////////////// PUBLIC ///////////////////////

void SortedBag::Destroy() {
    Destroy(root);
}

void SortedBag::Insert(int data) {
    root = Insert(NULL, root, data);
}

int SortedBag::Delete(int data) {
    Node* x = Search(root, data);
    
    if (x == NULL)
        return -1;
    
    root = Delete(root, data);
    
    return 0;
}

int SortedBag::Search(int data) {
    Node* x = Search(root, data);
    
    if (x == NULL)
        return -1;
    return 0;
}

int SortedBag::count() {
    int contor = 0;
    count(root, contor);
    return contor;
}

bool SortedBag::isEmpty() {
    if (root == NULL)
        return 1; // it's empty
    return 0; // it's not empty
}

void SortedBag::preOrderTraversal() {
    preOrderTraversal(root);
}

void SortedBag::inOrderTraversal() {
    inOrderTraversal(root);
}

void SortedBag::postOrderTraversal() {
    postOrderTraversal(root);
}

/////////////////////// PRIVATE ///////////////////////

bool SortedBag::cmp(int a, int b) {
    if (relation == ">")
        return a > b;
    return a < b;
}

Node* SortedBag::FindMin(Node *root) {
    while(root -> left != NULL)
        root = root -> left;
    return root;
}

Node* SortedBag::Insert(Node* parent, Node *root, int data) {
    
    if(root == NULL) {
        root = new Node();
        root -> data = data;
        root -> parent = parent;
        root -> left = root -> right = NULL;
    }
    else if (data < root -> data)
        root -> left = Insert(root, root -> left, data);
    else
        root -> right = Insert(root, root -> right, data);
    
    return root;
}

struct Node* SortedBag::Delete(struct Node *root, int data) {
    if(root == NULL) return root;
    else if (data < root->data) root -> left = Delete(root->left,data);
    else if (data > root->data) root -> right = Delete(root->right,data);
    // Wohoo... I found you, Get ready to be deleted
    else {
        // Case 1:  No child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        //Case 2: One child
        else if(root->left == NULL) {
            struct Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL) {
            struct Node *temp = root;
            root = root->left;
            delete temp;
        }
        // case 3: 2 children
        else {
            struct Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    
    return root;
}

struct Node* SortedBag::Search(Node *root, int data) {
    
    if (root != NULL) {
        
        if (data == root -> data)
            return root;
        
        if (cmp(data, root -> data))
            return Search(root -> left, data);
        else
            return Search(root -> right, data);
      
    } else
        return NULL;
    
}

void SortedBag::Destroy(Node *root)
{
    if(root != NULL)
    {
        Destroy(root -> left);
        Destroy(root -> right);
        delete root;
    }
}

/////////////////////// TRAVERSALS ///////////////////////

void SortedBag::preOrderTraversal(Node *root) {

    if (root == NULL)
        return;

    cout << root -> data << " ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);

}

void SortedBag::inOrderTraversal(Node *root) {
    
    if (root == NULL)
        return;
    
    inOrderTraversal(root -> left);
    cout << root -> data << " ";
    inOrderTraversal(root -> right);
    
}

void SortedBag::postOrderTraversal(Node *root) {
    
    if (root == NULL)
        return;
    
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout << root -> data << " ";
    
}

void SortedBag::count(Node* root, int &contor) {
    
    if (root == NULL)
        return;
    
    contor += 1;
    
    if (root -> left != NULL)
        count(root -> left, contor);
    if (root -> right != NULL)
        count(root -> right, contor);
        
}

bool IteratorBST::isValid(){
    return root != NULL;
}

int IteratorBST::getValue(){
    return root->data;
}

void IteratorBST::next(){
    
    if(!goDeeper(root -> right)){
        
        if(root -> parent != NULL){
        
            while(root -> parent != NULL && root == root -> parent -> right)
                root = root -> parent;
            
            root = root -> parent;
        }
    }
}

