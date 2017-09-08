#ifndef bst_hpp
#define bst_hpp

#include <iostream>

using namespace std;

// 'data' holds the information or value of the current node
// 'left' is a pointer to the left child of the current node
// 'right' is a pointer to the right child of the current node
struct Node {
    int data;
    struct Node *parent;
    struct Node *left;
    struct Node *right;
};

class IteratorBST{
    Node* root = NULL;
    
    bool goDeeper(Node* here){
        
        if(here == NULL){
            return false;
        }
        
        if(!goDeeper(here -> left)){
            root = here;
        }
        
        return true;
    }
public:
    IteratorBST(Node* root):root{root}{
        goDeeper(root->left);
    };
    bool isValid();
    int getValue();
    void next();
};

class SortedBag
{
public:
    // Constructor, setting the root to NULL
    SortedBag();
    //SortedBag(bool Relation(int a, int b));
    // Deconstructor
    ~SortedBag();

    void Destroy();
    
    void Insert(int data);
    
    int Delete(int data);
    int Search(int data);
    
    int count();
    
    bool isEmpty();
    
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
    
    IteratorBST getIterator(){
        return IteratorBST{root};
    }
    
private:
    
    bool cmp(int a, int b);
    
    void Destroy(Node *root);

    void preOrderTraversal(Node *root);
    void inOrderTraversal(Node *root);
    void postOrderTraversal(Node *root);
    
    Node* FindMin(Node* root);
    
    Node *Insert(Node* parent, Node *root, int data);
    Node *Delete(Node *root, int data);
    Node *Search(Node *root, int data);
    
    void count(Node *root, int &contor);
    
    Node *root;
    string relation;
};

#endif /* bst_hpp */
