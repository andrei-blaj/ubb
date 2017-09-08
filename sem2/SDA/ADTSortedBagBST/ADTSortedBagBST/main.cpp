//
// ADT SortedBag – implementation on a binary search tree.
//
// A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties
//      - The left sub-tree of a node has a key less than or equal to its parent node's key.
//      - The right sub-tree of a node has a key greater than to its parent node's key.
//
// Thus, BST divides all its sub-trees into two segments; the left sub-tree and the right sub-tree and can be defined as
//      left_subtree (keys)  ≤  node (key)  ≤  right_subtree (keys)
//
// Operations:
//      - Search: Searches an element in a tree.
//      - Insert: Inserts an element in a tree.
//      - Pre-order Traversal: Traverses a tree in a pre-order manner.
//      - In-order Traversal − Traverses a tree in an in-order manner.
//      - Post-order Traversal − Traverses a tree in a post-order manner.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>

#include "bst.hpp"
#include "tests.hpp"

using namespace std;

void print_menu() {
    cout << "> Select a command: \n";
    cout << "     1. Insert a value. \n";
    cout << "     2. Search if a value exists. \n";
    cout << "     3. Remove a value. \n";
    cout << "     4. Pre-Order Traversal. \n";
    cout << "     5. In-Order Traversal. \n";
    cout << "     6. Post-Order Traversal. \n";
    cout << "     7. Get number of elements. \n";
    cout << "     8. Check to see it the BST is empty. \n";
    cout << "     9. Print BST. \n";
}

bool Relation(int a, int b) {
    return a > b;
}

void run() {
    
    Tests tests;
    tests.testAll();
    
    SortedBag BST;
    
    BST.Insert(5);
    BST.Insert(10);
    BST.Insert(3);
    BST.Insert(4);
    BST.Insert(1);
    BST.Insert(11);
    
    while (1) {
    
        string command = "";
        string user_input;
        int val = 0;
        
        print_menu();
        
        while (command == "") {
            cout << "> "; cin >> command;
            if (command < "1" || command > "9") {
                cout << "> Unknown command '" + command + "'\n";
                command = "";
            }
        }
        if (command == "1" || command == "2" || command == "3") {
            
            bool ok = true, negative = false; // We suppose that the user input is valid.
            
            cout << "> Insert value: "; cin >> user_input;

            for (int i = 0; i < user_input.size(); i++) {
                if (user_input[0] == '-') {
                    negative = true;
                    continue;
                }
                    
                if (user_input[i] < '0' || user_input[i] > '9') {
                    // Invalid number
                    cout << "> Invalid input '" + user_input + "'\n";
                    ok = false; // Invalid user input.
                    break;
                } else {
                    val = val * 10 + (int(user_input[i]) - 48);
                }
            }
            
            if (!ok) {
                continue;
            }
            
        }
        
        if (command == "1") {
            // Insert a value
            
            BST.Insert(val);
            
            cout << "> Insertion complete.\n";
            
        } else if (command == "2") {
            // Search if a value exists
            
            int err = BST.Search(val);
            
            if (err == -1)
                cout << "> Value '" + to_string(val) + "' not found.\n";
            else
                cout << "> Match found.\n";
            
        } else if (command == "3") {
            // Remove a value
            
            int err = BST.Delete(val);
            
            if (err == -1)
                cout << "> Value '" + to_string(val) + "' not found.\n";
            else
                cout << "> Removal successful.\n";
            
        } else if (command == "4") {
            // Pre-Order Traversal
            // root, left, right
            
            BST.preOrderTraversal();
            cout << "\n";
            
        } else if (command == "5") {
            // In-Order Traversal
            // left, root, right
            
            BST.inOrderTraversal();
            cout << "\n";
            
        } else if (command == "6") {
            // Post-Order Traversal
            // left, right, root
            
            BST.postOrderTraversal();
            cout << "\n";
            
        } else if (command == "7") {
            // Return the number of elements
            
            int num_of_elements = BST.count();
            cout << "> There are " + to_string(num_of_elements) + " elements in the BST.\n";
            
        } else if (command == "8") {
            
            bool ok = BST.isEmpty();
            
            if (ok)
                cout << "> The BST is empty.\n";
            else
                cout << "> The BST is NOT empty.\n";
            
        } else if (command == "9") {
            
            IteratorBST it = BST.getIterator();
            while(it.isValid()){
                cout<<"Value: "<<it.getValue()<<endl;
                it.next();
            }
            
        }
        
    }
    
}

int main() {
    
    run();
    
    return 0;
}
